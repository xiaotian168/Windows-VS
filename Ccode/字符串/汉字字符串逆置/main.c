#include<stdio.h>
#include<stdlib.h>

int main()
{
	/**********************************************************/
	/*
		Windows�£�һ������GBK���� ռ2���ֽ�
			input:�Ұ���886
			output:688�㰮��

		˼·���Ƚ�ȫ���ַ�������
			  ѭ������������ASCIIֵΪ��������������ֵ����
	*/
	/**********************************************************/
	char str[] = "�Ұ���886��";
	printf("%s\n", str);	//printf(str)
	int len = strlen(str);

	for (int i = 0; i <= len/2; ++i)	//���������ַ���
	{
		int temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}

	for (int i = 0; i < len; ++i)	//�����ֵı�ʾ��λ
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