#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//2. 将字符串数组进行排序
//ret = sort(p1, len1, buf2, len2, &p3, &len3);
int sort(char **array1, int len1, char (*buf2)[30], int len2, char ***p3, int *len3)
{
	if (array1 == NULL || buf2 == NULL || len1 <= 0 || len2 <= 0)	//异常处理
		return -1;
	*len3 = len1 + len2;	//获取总字符串个数
	char **tmp3 = (char**)calloc(*len3,sizeof(char*));
	if (tmp3 == NULL)
		return -1;
	for (int i = 0; i < len1; ++i)
	{
		tmp3[i] = (char *)calloc(strlen(array1[i])+1,sizeof(char));	//堆中分配空间
		strcpy(tmp3[i],array1[i]);	//拷贝字符串
	}
	for (int i = len1; i < *len3; ++i)
	{
		tmp3[i] = (char *)calloc(strlen(buf2[i - len1]) + 1, sizeof(char));
		strcpy(tmp3[i], buf2[i-len1]);	//拷贝字符串
	}
	
	for (int i = 0; i < *len3 - 1; ++i)	//选择法排序
	{
		for (int j = i + 1; j < *len3; ++j)
		{
			if (strcmp(tmp3[i], tmp3[j]) > 0)	//升序;交换
			{
				char *tmp = tmp3[i];
				tmp3[i] = tmp3[j];
				tmp3[j] = tmp;
			}
		}
	}
	*p3 = tmp3;
}

void printBuf(char **p3, int len)
{
	if (p3 == NULL || len <= 0)	//异常处理
		return;
	for (int i = 0; i < len; ++i)
		printf("%s\n", p3[i]);
}

void free_buf(char ***p3, int len)
{
	if (p3 == NULL || len <= 0)
		return;
	char **tmp = *p3;
	for (int i = 0; i < len; ++i)
	{
		if (tmp[i])
		{
			free(tmp[i]);
			tmp[i] = NULL;
		}	
	}
	free(tmp);
	tmp = NULL;
	*p3 = tmp;
}

int  main01()
{
	int ret = 0;
	char *p1[] = { "aa", "ccccccc", "bbbbbb" };
	char buf2[][30] = { "111111", "3333333", "222222" };
	char **p3 = NULL;
	int len1, len2, len3, i = 0;

	len1 = sizeof(p1) / sizeof(*p1);
	len2 = sizeof(buf2) / sizeof(buf2[0]);

	/*
	功能：
	1、把指针数组p1的字符串取出来，
	2、把二维数组buf2的字符取出来，
	3、上面的字符串放在 p3，p3 是在堆区指针数组(每个元素同时又指向堆区)
	4、对 p3 中字符串进行排序，通过 strcmp() 进行排序
	参数：
	p1： 指针数组首地址，char *p1[] = {"aa", "ccccccc", "bbbbbb"};
	len1：p1元素个数
	buf2：二维数组首元素地址，char buf2[][30] = {"111111", "3333333", "222222"};
	len2：buf2字符串的行数
	p3：二级指针的地址，需要在函数内分配堆区指针数组，保存p1和buf2的字符串，还需要排序
	len3：保存p3中的字符串个数
	返回值：成功为0， 失败为负数
	*/
	ret = sort(p1, len1, buf2, len2, &p3, &len3);

	//打印内容
	printBuf(p3, len3);

	//释放p3所指向内存
	//在函数内部把p3的值赋值为NULL
	//len3：保存p3中的字符串个数
	free_buf(&p3, len3);

	printf("\n");
	system("pause");
	return 0;
}

int count_one_bits(unsigned int tmp)
{
	int n = 0;
	while (tmp)
	{
		if (tmp % 2)
		{
			n++;	
		}
		tmp /= 2;
	}
	return n;
}

int count_one_bits1(unsigned int tmp)
{
	int n = 0;
	for (int i = 0; i < 32; ++i)
	{
		if ((tmp >> 31) ^ 0)//依次比较每个位上的数是否为1(从高位开始);每次比较一位，与0异或，值为本身
			n++;
		tmp = tmp << 1;	//更新比较的bit位,丢弃高位
	}
	return n;
}

int main(void)
{
	/*******************************************************/
	/*
		计算一个无符号的数中，二进制位中值为 1 的个数
		提示：>>

		int count_one_bits(unsigned int tmp)
		{

		}
	*/
	/*******************************************************/
	int n;
	printf("input:");
	scanf("%d", &n);
	printf("%d", count_one_bits1(n));
	printf("\n");
	system("pause");
	return 0;
}


char **getMem(int n) //动态打造指针数组
{
	char **buf = (char**)calloc(n, sizeof(char *));
	if (buf == NULL)
		return NULL;
	for (int i = 0; i < n; ++i)
	{
		buf[i] = (char*)calloc(30,sizeof(char));
	}
	return buf;
}

/*
功能：把 "abcdef,acccd,eeee,aaaa,e3eeee,ssss,"，以","分隔出字符串，分配放在二维数组buf中
参数：
str：	原字符串，"abcdef,acccd,eeee,aaaa,e3eeee,ssss,"
c：	 	分隔标志：','
buf: 	指针数组首元素地址，其空间在主调函数分配
count：保存buf字符串的个数
返回值：
成功：0
失败：非0
*/
int spitString(const char *str, char c, char **buf, int *count)
{
	int n = 0;
	int i = 0;
	while (*str)
	{
		if (*str != c)
		{
			buf[n][i] = *str;
			i++;
			if (*(str + 1) == '\0')	//判断结尾字符不是c；则后面补'\0'
				buf[n][i] = '\0';
		}
		else
		{
			buf[n][i] = '\0';
			i = 0;
			n++;
			(*count)++;
		}
		str++;
	}
	return 0;
}

void getMemFree(char ***buf, int n) //释放空间
{
	if (buf == NULL || n <= 0)
		return;
	char **tmp = *buf;
	for (int i = 0; i < n; ++i)
	{
		if (tmp[i])
		{
			free(tmp[i]);
			tmp[i] = NULL;
		}
	}
	free(tmp);
	tmp = NULL;
	*buf = tmp;
}

int main03(void)
{
	/************************************************************************/
	/*	有一个字符串符合以下特征 "abcdef,acccd,eeee,aaaa,e3eeee,ssss,"
		a) 以逗号, 隔开字串，字串数量不会超过10个，每个字串长度不会超过30
		b) 以逗号分隔字符串，并把结果传出
		c)参考库函数：strchr(), strncpy(), strcpy(), strlen()
		不能使用strtok()
	*/
	/************************************************************************/
	char *p = "abcdef,acccd,eeee,aaaa,e3eeee,ssss,";
	char **buf = getMem(10); //动态打造指针数组
	int n = 0;
	int ret = 0;

	ret = spitString(p, ',', buf, &n);
	if (ret != 0)
	{
		system("pause");
		return ret;	
	}

	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%s\n", buf[i]); //打印分隔后的字符串
	}

	getMemFree(&buf, n); //释放空间

	system("pause");
	return 0;
}

