#include<stdio.h>
#include<stdlib.h>

int main()
{
	char buf[100];
	//������������
	sscanf("1234 5678", "%*d %s", buf);
	printf("buf1=%s\n", buf);

	//��ָ����ȵ�����
	sscanf("12345678", "%4s", buf);
	printf("buf2=%s\n", buf);

	//ȡ������ָ���ַ������ַ���
	sscanf("123abcABC", "%[1-9a-z]", buf);
	printf("buf3=%s\n", buf);

	//ȡ��ָ���ַ���Ϊֹ���ַ���
	sscanf("123abcABC", "%[^A-Z]", buf);
	printf("buf4=%s\n", buf);

	//ȡ��ָ���ַ�Ϊֹ���ַ���
	sscanf("123456 abcdedf", "%[^ ]", buf);
	printf("buf5=%s\n", buf);

	system("pause");
	return 0;
}