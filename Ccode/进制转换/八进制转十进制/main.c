#include<stdio.h>
#include<stdlib.h>
#include<math.h>	//����powͷ�ļ�
#include<string.h>

//str��һ���˽�������ʽ���ַ���  str[12] = "1314"   ���һ��Ԫ����'\0'
//����ֵ��ʮ��������
long int transform(const char *str)	//�ɹ�����ʮ����������ʧ�ܷ���-1��
{
	if (str == NULL)
		return -1;
	int len = strlen(str);	//�õ���Ч���ȣ�������'\0'
	long int sum = 0;
	long int value = 0;
	for (int i = 0; i < len; i++)
	{
		value = (str[i] - '0') * pow(8, len-1-i);	//�õ����ֶ�Ӧ��λ���ϵ���ֵ��Ȩֵ�ĳ˻�
		sum += value;	//�ۼӺ�
	}
	return sum;
}

int main()
{
	/**********************************************/
	/*
		�˽����ַ���ת��Ϊʮ��������
			�˽��ƣ�"1234"���ַ�����
			ʮ���ƣ�668	(����)
	*/
	/**********************************************/
	char size[12] = "1234";
	printf("%ld\n", transform(size));

	system("pause");
	return 0;
}