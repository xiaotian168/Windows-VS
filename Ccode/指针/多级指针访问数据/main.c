#include<stdio.h>
#include<stdlib.h>

int main()
{
	/***************************************************************/
	/*
		n��ָ��ֻ�ܽ�����n�Σ������ᱨ��
			���������ͨ��ǿת�������͵�����Ϊָ�����ͽ��з���
	*/
	/***************************************************************/
	int n = 100;
	int *p = &n;
	int **pp = &p;
	int ***ppp = &pp;
	int ****pppp = &ppp;
	int *****ppppp = &pppp;
	int ******pppppp = &ppppp;

	******pppppp = 77;

	printf("%d\n", ******pppppp);

	system("pause");
	return 0;
}