#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void *mycalloc(size_t rmemb, size_t Size)
{
	size_t sum = rmemb * Size;
	if (sum == 0)	//判断形参有值为零
		return NULL;
	void *ret = NULL;
	if (sum / rmemb == Size)	//判断要分配的空间在最大范围内，未溢出；
	{
		ret = (void *)malloc(sum);
		memset(ret, 0, sum);	//注意：此处sum太大调用memset会崩溃
		return ret;
	}
	else          //溢出返回空
		return NULL;
}

int main()
{
	/**************************************************************/
	/*
	编写calloc的实现
		通过调用malloc执行分配,调用memset将内存设置为00
		你的代码应该没有任何由算术溢出引起的漏洞,
		且无论数据类size\_t用多少位表示,代码都应该正常工作。

	库函数calloc有如下声明: 
  
		void *calloc(size_t rmemb, size_t Size) ;
		根据库文档: “函数calloc为一个数组分配内存,该数组有rmemb个元素,
		每个元素为size字节。内存设置为00,
		如果rmemb或size为0,则calloc返回NULL。 
	*/
	/****************************************************************/
	int *p = (int *)mycalloc(4, 1000000000);	//程序崩溃，由于调用了memset引起的
	system("pause");
	return 0;
}