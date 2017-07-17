#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	/*******************************************************/
	/*
	1.堆区二维数组练习（无需封装函数）
	a)在堆区申请空间，int a[3][4]
	b)通过循环给每一个元素赋值，以及打印每个元素的值
	c)使用完，需要释放堆区空间
	*/
	/*******************************************************/

	////法一:
	////定义一个数组指针类型
	//typedef int(*PARRAY)[4];	//为int (*)[4]数组指针起一个别名
	//PARRAY p;
	//p = (PARRAY)malloc(sizeof(int) * 3 * 4);	//分配空间
	//if (p == NULL)	//异常处理
	//	return -1;

	//法二：
	int(*p)[4] = (int(*)[4])malloc(sizeof(int)*3*4);
	if (p == NULL)
		return -1;
	int k = 0;
	for (int i = 0; i < 3; ++i)	//赋值
	{
		for (int j = 0; j < 4; ++j)
			*(*(p + i) + j) = ++k;
	}
	for (int i = 0; i < 3; ++i)	//打印
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
		1.堆区二维数组练习（无需封装函数）
		a)在堆区申请空间，int a[3][4]
		b)通过循环给每一个元素赋值，以及打印每个元素的值
		c)使用完，需要释放堆区空间
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

//2.结构体嵌套一级指针和二级指针练习
//结构体类型，每个导师有三个学生
typedef struct Teacher
{
	char *tName; //导师名字，需要动态分配空间
	char **stu;  //三个学生，需要动态分配空间，堆区数组
	int age;
}Teacher;

//在createTeacher中分配空间
int createTeacher(Teacher **p/*out*/, int n1, int n2)
{
	if (p == NULL || n1 <= 0 || n2 <= 0)	//异常处理
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

//给成员赋值
void initTeacher(Teacher *p, int n1, int n2)
{
	if (p == NULL || n1 <= 0 || n2 <= 0)	//异常处理
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

//打印结构体成员信息
void printTeacher(Teacher *p, int n1, int n2)
{
	if (p == NULL || n1 <= 0 || n2 <= 0)	//异常处理
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

//根据导师名字排序, 降序
void sortTeacher(Teacher *p, int n)
{
	if (p == NULL || n <= 0)
		return;
	//for (int i = 0; i < n - 1; ++i) //冒泡排序
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

	for (int i = 0; i < n - 1; ++i)	//选择排序
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

//释放空间，在函数内部把p赋值为NULL
void freeTeacher(Teacher **p, int n1, int n2)
{
	if (p == NULL || n1 <= 0 || n2 <= 0)	//异常处理
		return;
	Teacher *tmp = *p;
	if (tmp)
	{
		for (int i = 0; i < n1; ++i)
		{
			if (tmp[i].tName)	//释放每个导师的名字所占空间
			{
				free(tmp[i].tName);
				tmp[i].tName = NULL;
			}
			char **stu_tmp = tmp[i].stu;
			if (stu_tmp)
			{
				for (int j = 0; j < n2; ++j)
				{
					if (stu_tmp[j])//释放每个导师的每个学生所占空间
					{
						free(stu_tmp[j]);
						stu_tmp[j] = NULL;
					}
				}
				free(stu_tmp);//释放每个导师的所有学生所占空间
				stu_tmp = NULL;
			}
		}
		free(tmp);	//释放所有导师所占空间
		tmp = NULL;
	}
}

int main02(void)
{
	int ret = 0;
	int n1 = 3; //导师个数
	int n2 = 3; //学生
	Teacher *p = NULL;

	ret = createTeacher(&p, n1, n2);
	if (ret != 0)
	{
		printf("createTeacher err: %d\n", ret);
		system("pause");
		return ret;
	}

	initTeacher(p, n1, n2); //给成员赋值

							//打印成员，排序前
	printf("排序前：\n");
	printTeacher(p, n1, n2);

	//根据导师名字排序, 降序
	sortTeacher(p, n1);

	//打印成员，排序后
	printf("\n排序后：\n");
	printTeacher(p, n1, n2);

	//释放空间，在函数内部把p赋值为NULL
	freeTeacher(&p, n1, n2);

	system("pause");
	return 0;
}

int delete_space(char *str)	//删除成功返回0，失败返回非0
{
	if (str == NULL)
		return -1;
	int len = strlen(str);
	for (int i = 0; i < len; ++i)	//遍历字符串，遇到空格左移(注意相连是空格的情况)
	{
		if (str[i] == ' ')
		{
			for (int j = i; j < len - 1; ++j)
			{
				str[j] = str[j + 1];
			}
			len--;	//长度减少
			i--;	//重新判断当前位置是否为空格
		}
	}
	str[len] = '\0';	//补字符串结束符'\0'
	return 0;
}

void delspace(char *p1)
{
	char *p2;
	while (*p1 != '\0') //如果没有到结束符
	{
		if (*p1 == ' ')
		{
			p2 = p1;
			while (*p2 != '\0')
			{
				*p2 = *(p2 + 1);
				p2++;
			}/*end of while*/

			p1--; //抵消下面的p1++

		}/*end of if*/

		p1++;

	}/*end of while*/
}

int main03(void)
{
	/*******************************************************/
	/*
		3、编写一个函数。其参数为一个字符串，
		   函数删除字符串中的空格
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
