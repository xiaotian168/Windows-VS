//#define _CRT_SECURE_NO_WARNING
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//int main(void)
//{
//	int a;
//	int b;
//	printf("&a = %d\n&b = %d", &a, &b);
//	printf("\n");
//	system("pause");
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNING
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<math.h>
//
//typedef struct Teacher
//{
//	int data;
//	struct Teacher *next;
//}Teacher;
//
//int main(void)
//{
//	/*******************************************************/
//	/*
//		��̬����������
//	*/
//	/*******************************************************/
//	Teacher t1, t2, t3;
//	t1.data = 1;
//	t2.data = 2;
//	t3.data = 3;
//
//	t1.next = &t2;
//	t2.next = &t3;
//	t3.next = NULL;
//
//	Teacher *p = &t1;
//	while (p)
//	{
//		p->data = 6;
//		printf("%d ", p->data);
//		p = p->next;
//	}	
//	system("pause");
//}

//#define _CRT_SECURE_NO_WARNING
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//int main01()
//{
//	char a[4] = { 1, 2, 3, 4 };
//	char *p = a;
//	printf("%d, %d, %d, %d\n", *p, *(p + 1), *(p + 2), *(p + 3));
//
//	int *p1 = (int *)a;//��a�ĵ�ַǿתΪint *����
//	printf("%d\n", *p1);
//	printf("%x\n", *p1);
//
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print_array(char ** p, int n)
{
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		printf("%s, ", p[i]);
	}
	printf("\n");
}

void sort_array(char ** p, int n)
{
	int i = 0;
	int j = 0;
	char * tmp;


	//ѡ������
	for (i = 0; i < n - 1; ++i)
	{
		for (j = i + 1; j < n; ++j)
		{
			if (strcmp(p[i], p[j]) < 0) //�Ƚϣ�����
			{
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}

}

int main(void)
{
	char str1[100] = { 0 };
	char str2[100] = { 0 };
	char str3[100] = { 0 };

	char ** a = (char**)malloc(3 * sizeof(char*));
	//char * a[3] = { str1, str2, str3 };

	a[0] = str1;
	a[1] = str2;
	a[2] = str3;

	strcpy(a[0], "aaaaaaaa");
	strcpy(a[1], "bbbbbb");
	strcpy(a[2], "ccccccc");

	int n = sizeof(a) / sizeof(*a);

	//��ӡ
	print_array(&a[0], n);

	//����
	sort_array(a, n);

	//��ӡ
	print_array(&a[0], n);

	free(a);

	printf("\n");
	system("pause");
	return 0;
}