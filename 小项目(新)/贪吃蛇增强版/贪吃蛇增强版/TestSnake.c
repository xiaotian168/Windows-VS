#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#define Width 50
#define Height 20

//��ǿ�棨�Զ���һ�������ƶ���
//���⣺���ܸı��ƶ�����

typedef struct pps_node_t
{
	int x;
	int y;
}pps_node_t;

pps_node_t get_node()	//�����ȡ����ڵ� Width*Height��Χ����ӡ�����ؽڵ�
{
	pps_node_t p;
	srand((unsigned int)time(NULL));
	p.x = rand() % Width;
	p.y = rand() % Height;
	return p;
}

pps_node_t *start()	//��ʼ��Ϸ����ʼ��������ʼλ��
{
	pps_node_t *p = (pps_node_t *)calloc(1, sizeof(struct pps_node_t));
	if (p == NULL)
	{
		fprintf(stderr, "û�п����ڴ���\n");
		return NULL;
	}
	srand((unsigned int)time(NULL) + 7);
	p->x = rand() % Width;
	p->y = rand() % Height;
	return p;
}

void print_info(pps_node_t *p_start, int n, pps_node_t p)	//̰����λ��
{
	int k = 0, s = 0;
	for (int i = 0; i <= Height; ++i)	//��ʾ��Ϸԭʼ���λ��
	{
		for (int j = 0; j <= Width; ++j)
		{
			if (i == Height)
				printf("-");
			else if (j == Width)
				printf("|");
			else if (p.x == j && p.y == i)
				printf("*");
			else
			{
				if (k < n)
				{
					int m = 0, flag = 1;	//flag��Ϊ���λ
					for (; m < n; m++)	//�Ƚ����нڵ�����
					{
						if ((p_start[m].x == j) && (p_start[m].y == i))
						{
							printf("@");
							k++;
							s++;	//��¼�ڵ�����
							flag = 0;
							break;
						}
					}
					if (flag)	//��ǰ���겻�ǽڵ�����
						printf(" ");
				}
				else
					printf(" ");
			}
		}
		printf("\n");
	}
	printf("��ǰ�����ȣ�%d\n", s);
}

int panduan(const pps_node_t *p_start, int n)	//�ж�̰���߽ڵ��Ƿ����غϣ��з���1��û�з���0
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if ((p_start[i].x == p_start[j].x) && (p_start[i].y == p_start[j].y))
			{
				return 1;
			}
		}
	}
	return 0;
}

void move(const char *c, pps_node_t *p_start, int n, pps_node_t p, pps_node_t *op)	//�ƶ�����λ��
{
	if (c[0] == 'l')	//�����ƶ�
	{
		if (n != 1)
		{
			while (1)
			{
				*op = p_start[0];	//������β������Ϣ
				for (int i = 0; i < n - 1; ++i)	//���½ڵ�
					p_start[i] = p_start[i + 1];
				p_start[n - 1].x = p_start[n - 1].x - 1;	//������ͷ
				p_start[n - 1].y = p_start[n - 1].y;

				if (panduan(p_start, n))	//�����ظ��ڵ㣬��Ϸ����
				{
					printf("\nGame Over\n");
					Sleep(4000);
					exit(-1);
				}

				print_info(p_start, n, p);	//��ӡ��ǰλ��
				Sleep(100);	//��ӡһ�Σ�ͣ��0.5��
				system("cls");	//����
			}
		}
		else
		{
			while (1)
			{
				*op = p_start[0];	//������β������Ϣ
				p_start->x -= 1;

				if (panduan(p_start, n))	//�����ظ��ڵ㣬��Ϸ����
				{
					printf("\nGame Over\n");
					Sleep(4000);
					exit(-1);
				}

				print_info(p_start, n, p);	//��ӡ��ǰλ��
				Sleep(500);	//��ӡһ�Σ�ͣ��0.7��
				system("cls");	//����
			}
		}
		return;
	}
	if (c[0] == '\'')	//�����ƶ�
	{
		if (n != 1)
		{
			while (1)
			{
				*op = p_start[0];	//������β������Ϣ
				for (int i = 0; i < n - 1; ++i)	//���½ڵ�
					p_start[i] = p_start[i + 1];
				p_start[n - 1].x = p_start[n - 1].x - 1;	//������ͷ
				p_start[n - 1].y = p_start[n - 1].y;

				if (panduan(p_start, n))	//�����ظ��ڵ㣬��Ϸ����
				{
					printf("\nGame Over\n");
					Sleep(4000);
					exit(-1);
				}

				print_info(p_start, n, p);	//��ӡ��ǰλ��
				Sleep(100);	//��ӡһ�Σ�ͣ��0.5��
				system("cls");	//����
			}
		}
		else
		{
			while (1)
			{
				*op = p_start[0];	//������β������Ϣ
				p_start->x += 1;

				if (panduan(p_start, n))	//�����ظ��ڵ㣬��Ϸ����
				{
					printf("\nGame Over\n");
					Sleep(4000);
					exit(-1);
				}

				print_info(p_start, n, p);	//��ӡ��ǰλ��
				Sleep(500);	//��ӡһ�Σ�ͣ��0.7��
				system("cls");	//����
			}
		}
		return;
	}
	if (c[0] == 'p')	//�����ƶ�
	{
		if (n != 1)
		{
			while (1)
			{
				*op = p_start[0];	//������β������Ϣ
				for (int i = 0; i < n - 1; ++i)	//���½ڵ�
					p_start[i] = p_start[i + 1];
				p_start[n - 1].x = p_start[n - 1].x;	//������ͷ
				p_start[n - 1].y = p_start[n - 1].y - 1;

				print_info(p_start, n, p);	//��ӡ��ǰλ��
				Sleep(100);	//��ӡһ�Σ�ͣ��0.5��
				system("cls");	//����
			}
		}
		else
		{
			while (1)
			{
				*op = p_start[0];	//������β������Ϣ
				p_start->y -= 1;

				print_info(p_start, n, p);	//��ӡ��ǰλ��
				Sleep(500);	//��ӡһ�Σ�ͣ��0.7��
				system("cls");	//����
			}
		}
		return;
	}
	if (c[0] == ';')	//�����ƶ�
	{
		if (n != 1)
		{
			while (1)
			{
				*op = p_start[0];	//������β������Ϣ
				for (int i = 0; i < n - 1; ++i)	//���½ڵ�
					p_start[i] = p_start[i + 1];
				p_start[n - 1].x = p_start[n - 1].x;	//������ͷ
				p_start[n - 1].y = p_start[n - 1].y + 1;

				if (panduan(p_start, n))	//�����ظ��ڵ㣬��Ϸ����
				{
					printf("\nGame Over\n");
					Sleep(4000);
					exit(-1);
				}

				print_info(p_start, n, p);	//��ӡ��ǰλ��
				Sleep(100);	//��ӡһ�Σ�ͣ��0.5��
				system("cls");	//����
			}
		}
		else
		{
			while (1)
			{
				*op = p_start[0];	//������β������Ϣ
				p_start->y += 1;

				if (panduan(p_start, n))	//�����ظ��ڵ㣬��Ϸ����
				{
					printf("\nGame Over\n");
					Sleep(4000);
					exit(-1);
				}

				print_info(p_start, n, p);	//��ӡ��ǰλ��
				Sleep(500);	//��ӡһ�Σ�ͣ��0.7��
				system("cls");	//����
			}
		}
		return;
	}
}

void addnode(pps_node_t **p_start, pps_node_t *p, int n, pps_node_t op)	//̰���߽ڵ����ӣ����Ҹ��´�ӡ��ǰ�ڵ���Ϣ
{
	if (p_start == NULL)
		return;
	pps_node_t *temp = *p_start;
	temp = (pps_node_t *)realloc(*p_start, n * sizeof(pps_node_t));	//��չ�½ڵ�洢�ռ�
	if (temp == NULL)
		return;

	temp[n - 1] = *p;	//��ͷ����
	for (int i = n - 2; i > 0; --i)	//�����м�ڵ���Ϣ
		temp[i] = temp[i - 1];
	temp[0] = op;	//��β��Ϣ

	if (panduan(temp, n))	//�����ظ��ڵ㣬��Ϸ����
	{
		printf("\nGame Over\n");
		Sleep(4000);
		exit(-1);
	}

	*p = get_node();
	print_info(*p_start, n, *p);
}

int main()
{
	pps_node_t *p_start = start();	//��ȡԭʼλ��
	pps_node_t p;
	p = get_node();	//��������ڵ�λ��
	int n = 1;	//��Ϊ������ʼ����
	print_info(p_start, n, p);	//��ʾ��Ϸ��ʼ״̬
	pps_node_t op = p_start[0];	//����β���ڵ�����

	while (1)
	{
		if (p_start[n - 1].x >= Width || p_start[n - 1].x < 0 || p_start[n - 1].y >= Height || p_start[n - 1].y < 0)	//�жϳ��磻�˳�ѭ������Ϸ����
		{
			printf("\nGame Over\n");
			break;
		}

		//�����û�ָ��
		char order[10];	//����̰�����ƶ�����
		if (p.x == p_start[n - 1].x && p.y == p_start[n - 1].y)	//���������ӣ�����������²����ڵ�
		{
			n++;
			system("cls");	//����
			addnode(&p_start, &p, n, op);
			continue;
		}
		scanf("%s", order);
		//����
		system("cls");
		//Sleep(10);	//ʱ��ͣ����λ����

		move(order, p_start, n, p, &op);	//̰�����ƶ�
		memset(order, 0, sizeof(order));
	}
	Sleep(4000);	//��Ϸ������ͣ��4��
	free(p_start);	//�ͷ�̰������ռ�ѿռ�
	system("pause");
	return 0;
}