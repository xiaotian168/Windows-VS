#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	/*******************************************************/
	/*
	1.������ά������ϰ�������װ������
	a)�ڶ�������ռ䣬int a[3][4]
	b)ͨ��ѭ����ÿһ��Ԫ�ظ�ֵ���Լ���ӡÿ��Ԫ�ص�ֵ
	c)ʹ���꣬��Ҫ�ͷŶ����ռ�
	*/
	/*******************************************************/

	////��һ:
	////����һ������ָ������
	//typedef int(*PARRAY)[4];	//Ϊint (*)[4]����ָ����һ������
	//PARRAY p;
	//p = (PARRAY)malloc(sizeof(int) * 3 * 4);	//����ռ�
	//if (p == NULL)	//�쳣����
	//	return -1;

	//������
	int(*p)[4] = (int(*)[4])malloc(sizeof(int)*3*4);
	if (p == NULL)
		return -1;
	int k = 0;
	for (int i = 0; i < 3; ++i)	//��ֵ
	{
		for (int j = 0; j < 4; ++j)
			*(*(p + i) + j) = ++k;
	}
	for (int i = 0; i < 3; ++i)	//��ӡ
	{
		for (int j = 0; j < 4; ++j)
			printf("%d\t", *(*(p + i) + j));
		printf("\n");
	}

	if (p)
	{
		free(p);
		p = NULL;
	}
	system("pause");
	return 0;
}

int main01(void)
{
	/*******************************************************/
	/*
		1.������ά������ϰ�������װ������
		a)�ڶ�������ռ䣬int a[3][4]
		b)ͨ��ѭ����ÿһ��Ԫ�ظ�ֵ���Լ���ӡÿ��Ԫ�ص�ֵ
		c)ʹ���꣬��Ҫ�ͷŶ����ռ�
	*/
	/*******************************************************/
	int **a = (int**)malloc(3*sizeof(int *));
	if (a == NULL)
		return -1;
	int n = 1;
	for (int i = 0; i < 3; ++i)
	{
		a[i] = (int*)malloc(4*sizeof(int));
		if (a[i] == NULL)
			return -1;
		for (int j = 0; j < 4; ++j)
		{	
			a[i][j] = n++;
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < 3; ++i)
	{
		if (a[i])
		{
			free(a[i]);
			a[i] = NULL;
		}
	}
	free(a);
	a = NULL;
	printf("\n");
	system("pause");
	return 0;
}

//2.�ṹ��Ƕ��һ��ָ��Ͷ���ָ����ϰ
//�ṹ�����ͣ�ÿ����ʦ������ѧ��
typedef struct Teacher
{
	char *tName; //��ʦ���֣���Ҫ��̬����ռ�
	char **stu;  //����ѧ������Ҫ��̬����ռ䣬��������
	int age;
}Teacher;

//��createTeacher�з���ռ�
int createTeacher(Teacher **p/*out*/, int n1, int n2)
{
	if (p == NULL || n1 <= 0 || n2 <= 0)	//�쳣����
		return -1;
	Teacher *tmp = (Teacher*)malloc(n1 * sizeof(Teacher));
	if (tmp == NULL)
		return -1;
	for (int i = 0; i < n1; ++i)
	{
		tmp[i].tName = (char*)malloc(64);
		tmp[i].stu = (char**)malloc(n2 * sizeof(char*));
		char **stu_tmp = tmp[i].stu;
		for (int j = 0; j < n2; ++j)
		{
			stu_tmp[j] = (char*)malloc(64);
		}
	}
	*p = tmp;
	return 0;
}

//����Ա��ֵ
void initTeacher(Teacher *p, int n1, int n2)
{
	if (p == NULL || n1 <= 0 || n2 <= 0)	//�쳣����
		return;
	for (int i = 0; i < n1; ++i)
	{
		sprintf(p[i].tName,"Teacher0%d",i+1);
		for (int j = 0; j < n2; ++j)
		{
			sprintf(p[i].stu[j], "xiaotian0%d%d", i+1, j+1);
		}
		p[i].age = 18 + i;
	}
}

//��ӡ�ṹ���Ա��Ϣ
void printTeacher(Teacher *p, int n1, int n2)
{
	if (p == NULL || n1 <= 0 || n2 <= 0)	//�쳣����
		return;
	for (int i = 0; i < n1; ++i)
	{
		printf("%s\t", p[i].tName);
		for (int j = 0; j < n2; ++j)
		{
			printf("%s\t", p[i].stu[j]);
		}
		printf("%d\n",p[i].age);
	}
}

//���ݵ�ʦ��������, ����
void sortTeacher(Teacher *p, int n)
{
	if (p == NULL || n <= 0)
		return;
	//for (int i = 0; i < n - 1; ++i) //ð������
	//{
	//	for (int j = 0; j < n - 1 - i; ++j)
	//	{
	//		if (strcmp(p[j].tName, p[j+1].tName) < 0)
	//		{
	//			Teacher tmp = p[j];
	//			p[j] = p[j+1];
	//			p[j+1] = tmp;
	//		}
	//	}
	//}

	for (int i = 0; i < n - 1; ++i)	//ѡ������
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (strcmp(p[i].tName, p[j].tName) < 0)
			{
				Teacher tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}
}

//�ͷſռ䣬�ں����ڲ���p��ֵΪNULL
void freeTeacher(Teacher **p, int n1, int n2)
{
	if (p == NULL || n1 <= 0 || n2 <= 0)	//�쳣����
		return;
	Teacher *tmp = *p;
	if (tmp)
	{
		for (int i = 0; i < n1; ++i)
		{
			if (tmp[i].tName)	//�ͷ�ÿ����ʦ��������ռ�ռ�
			{
				free(tmp[i].tName);
				tmp[i].tName = NULL;
			}
			char **stu_tmp = tmp[i].stu;
			if (stu_tmp)
			{
				for (int j = 0; j < n2; ++j)
				{
					if (stu_tmp[j])//�ͷ�ÿ����ʦ��ÿ��ѧ����ռ�ռ�
					{
						free(stu_tmp[j]);
						stu_tmp[j] = NULL;
					}
				}
				free(stu_tmp);//�ͷ�ÿ����ʦ������ѧ����ռ�ռ�
				stu_tmp = NULL;
			}
		}
		free(tmp);	//�ͷ����е�ʦ��ռ�ռ�
		tmp = NULL;
	}
}

int main02(void)
{
	int ret = 0;
	int n1 = 3; //��ʦ����
	int n2 = 3; //ѧ��
	Teacher *p = NULL;

	ret = createTeacher(&p, n1, n2);
	if (ret != 0)
	{
		printf("createTeacher err: %d\n", ret);
		system("pause");
		return ret;
	}

	initTeacher(p, n1, n2); //����Ա��ֵ

							//��ӡ��Ա������ǰ
	printf("����ǰ��\n");
	printTeacher(p, n1, n2);

	//���ݵ�ʦ��������, ����
	sortTeacher(p, n1);

	//��ӡ��Ա�������
	printf("\n�����\n");
	printTeacher(p, n1, n2);

	//�ͷſռ䣬�ں����ڲ���p��ֵΪNULL
	freeTeacher(&p, n1, n2);

	system("pause");
	return 0;
}

int delete_space(char *str)	//ɾ���ɹ�����0��ʧ�ܷ��ط�0
{
	if (str == NULL)
		return -1;
	int len = strlen(str);
	for (int i = 0; i < len; ++i)	//�����ַ����������ո�����(ע�������ǿո�����)
	{
		if (str[i] == ' ')
		{
			for (int j = i; j < len - 1; ++j)
			{
				str[j] = str[j + 1];
			}
			len--;	//���ȼ���
			i--;	//�����жϵ�ǰλ���Ƿ�Ϊ�ո�
		}
	}
	str[len] = '\0';	//���ַ���������'\0'
	return 0;
}

void delspace(char *p1)
{
	char *p2;
	while (*p1 != '\0') //���û�е�������
	{
		if (*p1 == ' ')
		{
			p2 = p1;
			while (*p2 != '\0')
			{
				*p2 = *(p2 + 1);
				p2++;
			}/*end of while*/

			p1--; //���������p1++

		}/*end of if*/

		p1++;

	}/*end of while*/
}

int main03(void)
{
	/*******************************************************/
	/*
		3����дһ�������������Ϊһ���ַ�����
		   ����ɾ���ַ����еĿո�
	*/
	/*******************************************************/
	char str[] = " he ll o wor  l  d";
	//delete_space(str);
	delspace(str);
	printf(str);
	printf("\n");
	system("pause");
	return 0;
}
