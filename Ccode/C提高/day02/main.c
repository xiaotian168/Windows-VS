#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int mystrlen(const char *str)
{
	int len = 0;
	if (str == NULL)
		return len;
	while (*str++)
		len++;
	return len;
}

/*
功能：在字符串haystack中查找字符串needle出现的位置
参数：
haystack：源字符串首地址
needle：匹配字符串首地址
返回值：
成功：返回第一次出现的needle地址
失败：NULL
*/
char *my_strstr(const char *haystack, const char *needle)
{
	if (haystack == NULL || needle == NULL)
		return NULL;
	int len2 = mystrlen(needle);
	int len = 0;	//作为后面判断是否出现匹配字符串的标志
	while (*haystack && *needle)	//遍历字符串进行比较
	{
		if (*haystack == *needle)	//出现相等字符，目标字符指针移动；相等的字符个数自增1
		{
			len++;
			needle++;
		}
		else    //出现不等字符
		{
			needle -= len;	//目标子串指针回到起点
			len = 0;	//相等的字符个数归零
		}	
		haystack++;
	}
	if (len == len2)	//判断找到相等子串
		return haystack -= len2;
	else
		return NULL;
}

int main()
{
	/************************************************************/
	/*
		实现my_strstr()函数，功能和strstr()函数一样。
		a. 函数中不使用任何操作字符串的函数(如：strcpy、strcmp等)
		b. 函数中的任何地方不使用下标。
	*/
	/************************************************************/
	char *haystack = "hello worldjfal";
	char *needle = "ld";
	printf(my_strstr(haystack, needle));
	system("pause");
	return 0;
}

/*
功能：
键值对（“key = value”）字符串更加键key查找对应的值value
参数：
keyval：键值对（“key = value”）字符串
pkey：键
buf：匹配键所对应的内容
len：匹配键所对应内容的长度
返回值：
成功：0
失败：非0
*/
int getKeyByValue(char *keyvaluebuf, char *keybuf, char *valuebuf, int* valuebuflen)
{
	//异常处理
	if (keyvaluebuf == NULL || keybuf == NULL || valuebuf == NULL || valuebuflen == NULL)
		return -1;
	int key_len = strlen(keybuf);	//求key值长度
	keyvaluebuf = strstr(keyvaluebuf, keybuf);	//将子串（"key = value"）的首地址重新赋值给键值对
	if (keyvaluebuf == NULL)	//不存在目标子串
		return -1;

	keyvaluebuf = keyvaluebuf + key_len;	//移动到目标子串
	int len = strlen(keyvaluebuf);	//求未去除空格的目标字符串长度
	*valuebuflen = 0;
	for (int i = 0; i < len; ++i)	//拷贝目标子串到valuebuf中
	{
		if ((isspace(keyvaluebuf[i]) || keyvaluebuf[i] == '=') && *valuebuflen == 0)
			continue;
		else
			valuebuf[(*valuebuflen)++] = keyvaluebuf[i];
	}
	return 0;
}

int main01()
{
	/*************************************************************/
	/*
		键值对（"key = value"）字符串，在开发中经常使用
		要求1：请自己定义一个接口，实现根据key获取
		要求2：编写测试用例
		要求3：键值对中间可能有n多空格，请去除空格	
		注意：键值对字符串格式可能如下：
		"key1 = value1"
		"key2 =       value2"
		"key3  = value3"
		"key4        = value4"
		"key5   =   "
		"key6   ="
		参考库函数：strncpy(), strlen(), strstr(), 
					不能使用sscanf()函数
	*/
	/************************************************************/
	char buf[128] = { 0 };
	int len = 0;

	// 在"key1 =    valude1"中查找"key1"匹配的字符串，
	//如果找到，获取=后面的字符串，而且去掉多余空格
	int ret = getKeyByValue("key1 =    valude1 ", "key1", buf, &len);
	//调用函数后：buf="valude1", len=7
	printf("%s %d", buf, len);

	system("pause");
	return 0;
}