#include<stdio.h>
#include<stdlib.h>

int main()
{
	/**********************************************************/
	/*
		Windows下：一个汉字GBK编码 占2个字节
			input:我爱你886
			output:688你爱我

		思路：先将全部字符串逆置
			  循环遍历；遇到ASCII值为负的相邻两个数值互换
	*/
	/**********************************************************/
	char str[] = "我爱你886哈";
	printf("%s\n", str);	//printf(str)
	int len = strlen(str);

	for (int i = 0; i <= len/2; ++i)	//逆置所有字符串
	{
		int temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}

	for (int i = 0; i < len; ++i)	//将汉字的表示复位
	{
		if (str[i] < 0)
		{
			int temp = str[i];
			str[i] = str[i + 1];
			str[i+1] = temp;
			++i;
		}
	}
	printf("%s\n", str);
	system("pause");
	return 0;
}