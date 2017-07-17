#include<stdio.h>
#include<stdlib.h>

struct tar_header
{
	char name[100];//文件名
	char mode[8];
	char uid[8];
	char gid[8];
	char size[12]; //文件大小的八进制数的字符串形式
	char mtime[12];
	char chksum[8];
	char typeflag;
	char linkname[100];
	char magic[6];
	char version[2];
	char uname[32];
	char gname[32];
	char devmajor[8];
	char devminor[8];
	char prefix[155];
	char padding[12];
};

int main()
{
	char s1[1024] = { 0 };
	char buf[sizeof(struct tar_header)] = { 0 };
	struct tar_header *head = (struct tar_header *)buf;
	printf("输入文件名 打包名\n");
	scanf("%s %s", head->name, s1);
	FILE *fp = fopen(s1, "wb");
	FILE *p = fopen(head->name, "rb");
	//set_magic_mode_checksum(head);
	fseek(p, 0, SEEK_END);
	int len = ftell(p);
	fseek(p, 0, SEEK_SET);
	char a[512] = { 0 };

	sprintf(head->size, "%011o", len);
	fwrite(head, 1, 512, fp);
	//fseek(fp, 512, SEEK_SET);
	//int newlen = 0;
	/*while (len)
	{
	memset(a, 0, sizeof(a));
	newlen = sizeof(a) > len ? len : sizeof(a);
	fread(a, 1, newlen, p);
	fwrite(a, 1, 512, fp);
	len -= newlen;
	}*/
	fread(a, 1, len, p);
	fwrite(a, 1, 512, fp);

	//fseek(fp, 0, SEEK_END);
	memset(buf, 0, sizeof(buf));
	fwrite(head, 1, 512, fp);


	fclose(p);
	fclose(fp);

}