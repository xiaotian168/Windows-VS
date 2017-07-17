#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"LinkList.h"

struct Person
{
	char name[64];
	int age;
};

void myPrint(void* data)
{
	struct Person *person = (struct Person *)data;
	printf("Name:%s Age:%d\n", person->name, person->age);
}

int valFound(void *data, void *my_data)
{
	//���սڵ�����
	struct Person *person = (struct Person *)data;

	int *n = (int *)my_data;

	if (person->age == *n)	//�ҵ��ض���ֵ
	{
		return 0;
	}
	return -1;
}



void test()
{

	//��������
	struct Person p1 = { "aaa", 10 };
	struct Person p2 = { "bbb", 20 };
	struct Person p3 = { "ccc", 30 };
	struct Person p4 = { "ddd", 40 };
	struct Person p5 = { "eee", 50 };
	struct Person p6 = { "fff", 60 };

	//��������
	LinkList list = Init_LinkList();

	//ָ��λ�ò�������
	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 1, &p3);
	Insert_LinkList(list, 1, &p4);
	Insert_LinkList(list, 2, &p5);
	Insert_LinkList(list, 3, &p6);

	printf("��ǰ�����СΪ��%d\n", Size_LinkList(list));
	Foreach_LinkList(list, myPrint);

	//ͷ����������
	PushFront_LinkList(list, &p6);
	printf("-----------------------\nͷ���������ݺ�Ϊ:\n");
	Foreach_LinkList(list, myPrint);

	//β����������
	PushBack_LinkList(list, &p6);
	printf("-----------------------\nβ���������ݺ�Ϊ:\n");
	Foreach_LinkList(list, myPrint);

	//��ֵɾ�����ݺ�
	RemoveByVal_LinkList(list, &(p6.age), valFound);
	printf("-----------------------\n��ֵɾ�����ݺ�Ϊ:\n");
	Foreach_LinkList(list, myPrint);

	//ָ��λ��ɾ������
	Remove_LinkList(list, 1);
	printf("-------------\n");
	Foreach_LinkList(list, myPrint);

	//ͷ��ɾ������
	PopFront_LinkList(list);
	printf("-------------\nͷ��λ��ɾ�����ݺ�Ϊ:\n");
	Foreach_LinkList(list, myPrint);

	//β��ɾ������
	PopBack_LinkList(list);
	printf("-------------\nβ��λ��ɾ�����ݺ�Ϊ:\n");
	Foreach_LinkList(list, myPrint);

	//����ָ�����ݣ���������ң�
	int n = 30;
	struct Person *node = (struct Person *)Get_Value(list, valFound, &n);
	printf(node->name);
	printf("\n");

	//�����ӡ����
	printf("�����ӡΪ\n");
	print_LinkList(list, myPrint);


	//��������
	Destroy_LinkList(list);
}

int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}