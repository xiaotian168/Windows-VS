#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#define Width 50
#define Height 20

//增强版（自动朝一个方向移动）
//问题：不能改变移动方向

typedef struct pps_node_t
{
	int x;
	int y;
}pps_node_t;

pps_node_t get_node()	//随机获取蛇身节点 Width*Height范围；打印并返回节点
{
	pps_node_t p;
	srand((unsigned int)time(NULL));
	p.x = rand() % Width;
	p.y = rand() % Height;
	return p;
}

pps_node_t *start()	//开始游戏；初始化蛇身起始位置
{
	pps_node_t *p = (pps_node_t *)calloc(1, sizeof(struct pps_node_t));
	if (p == NULL)
	{
		fprintf(stderr, "没有可用内存了\n");
		return NULL;
	}
	srand((unsigned int)time(NULL) + 7);
	p->x = rand() % Width;
	p->y = rand() % Height;
	return p;
}

void print_info(pps_node_t *p_start, int n, pps_node_t p)	//贪吃蛇位置
{
	int k = 0, s = 0;
	for (int i = 0; i <= Height; ++i)	//显示游戏原始相对位置
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
					int m = 0, flag = 1;	//flag作为标记位
					for (; m < n; m++)	//比较所有节点坐标
					{
						if ((p_start[m].x == j) && (p_start[m].y == i))
						{
							printf("@");
							k++;
							s++;	//记录节点总数
							flag = 0;
							break;
						}
					}
					if (flag)	//当前坐标不是节点坐标
						printf(" ");
				}
				else
					printf(" ");
			}
		}
		printf("\n");
	}
	printf("当前蛇身长度：%d\n", s);
}

int panduan(const pps_node_t *p_start, int n)	//判断贪吃蛇节点是否有重合，有返回1；没有返回0
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

void move(const char *c, pps_node_t *p_start, int n, pps_node_t p, pps_node_t *op)	//移动更新位置
{
	if (c[0] == 'l')	//向左移动
	{
		if (n != 1)
		{
			while (1)
			{
				*op = p_start[0];	//保存蛇尾坐标信息
				for (int i = 0; i < n - 1; ++i)	//更新节点
					p_start[i] = p_start[i + 1];
				p_start[n - 1].x = p_start[n - 1].x - 1;	//更新蛇头
				p_start[n - 1].y = p_start[n - 1].y;

				if (panduan(p_start, n))	//出现重复节点，游戏结束
				{
					printf("\nGame Over\n");
					Sleep(4000);
					exit(-1);
				}

				print_info(p_start, n, p);	//打印当前位置
				Sleep(100);	//打印一次，停留0.5秒
				system("cls");	//清屏
			}
		}
		else
		{
			while (1)
			{
				*op = p_start[0];	//保存蛇尾坐标信息
				p_start->x -= 1;

				if (panduan(p_start, n))	//出现重复节点，游戏结束
				{
					printf("\nGame Over\n");
					Sleep(4000);
					exit(-1);
				}

				print_info(p_start, n, p);	//打印当前位置
				Sleep(500);	//打印一次，停留0.7秒
				system("cls");	//清屏
			}
		}
		return;
	}
	if (c[0] == '\'')	//向右移动
	{
		if (n != 1)
		{
			while (1)
			{
				*op = p_start[0];	//保存蛇尾坐标信息
				for (int i = 0; i < n - 1; ++i)	//更新节点
					p_start[i] = p_start[i + 1];
				p_start[n - 1].x = p_start[n - 1].x - 1;	//更新蛇头
				p_start[n - 1].y = p_start[n - 1].y;

				if (panduan(p_start, n))	//出现重复节点，游戏结束
				{
					printf("\nGame Over\n");
					Sleep(4000);
					exit(-1);
				}

				print_info(p_start, n, p);	//打印当前位置
				Sleep(100);	//打印一次，停留0.5秒
				system("cls");	//清屏
			}
		}
		else
		{
			while (1)
			{
				*op = p_start[0];	//保存蛇尾坐标信息
				p_start->x += 1;

				if (panduan(p_start, n))	//出现重复节点，游戏结束
				{
					printf("\nGame Over\n");
					Sleep(4000);
					exit(-1);
				}

				print_info(p_start, n, p);	//打印当前位置
				Sleep(500);	//打印一次，停留0.7秒
				system("cls");	//清屏
			}
		}
		return;
	}
	if (c[0] == 'p')	//向上移动
	{
		if (n != 1)
		{
			while (1)
			{
				*op = p_start[0];	//保存蛇尾坐标信息
				for (int i = 0; i < n - 1; ++i)	//更新节点
					p_start[i] = p_start[i + 1];
				p_start[n - 1].x = p_start[n - 1].x;	//更新蛇头
				p_start[n - 1].y = p_start[n - 1].y - 1;

				print_info(p_start, n, p);	//打印当前位置
				Sleep(100);	//打印一次，停留0.5秒
				system("cls");	//清屏
			}
		}
		else
		{
			while (1)
			{
				*op = p_start[0];	//保存蛇尾坐标信息
				p_start->y -= 1;

				print_info(p_start, n, p);	//打印当前位置
				Sleep(500);	//打印一次，停留0.7秒
				system("cls");	//清屏
			}
		}
		return;
	}
	if (c[0] == ';')	//向下移动
	{
		if (n != 1)
		{
			while (1)
			{
				*op = p_start[0];	//保存蛇尾坐标信息
				for (int i = 0; i < n - 1; ++i)	//更新节点
					p_start[i] = p_start[i + 1];
				p_start[n - 1].x = p_start[n - 1].x;	//更新蛇头
				p_start[n - 1].y = p_start[n - 1].y + 1;

				if (panduan(p_start, n))	//出现重复节点，游戏结束
				{
					printf("\nGame Over\n");
					Sleep(4000);
					exit(-1);
				}

				print_info(p_start, n, p);	//打印当前位置
				Sleep(100);	//打印一次，停留0.5秒
				system("cls");	//清屏
			}
		}
		else
		{
			while (1)
			{
				*op = p_start[0];	//保存蛇尾坐标信息
				p_start->y += 1;

				if (panduan(p_start, n))	//出现重复节点，游戏结束
				{
					printf("\nGame Over\n");
					Sleep(4000);
					exit(-1);
				}

				print_info(p_start, n, p);	//打印当前位置
				Sleep(500);	//打印一次，停留0.7秒
				system("cls");	//清屏
			}
		}
		return;
	}
}

void addnode(pps_node_t **p_start, pps_node_t *p, int n, pps_node_t op)	//贪吃蛇节点增加，并且更新打印当前节点信息
{
	if (p_start == NULL)
		return;
	pps_node_t *temp = *p_start;
	temp = (pps_node_t *)realloc(*p_start, n * sizeof(pps_node_t));	//拓展新节点存储空间
	if (temp == NULL)
		return;

	temp[n - 1] = *p;	//蛇头坐标
	for (int i = n - 2; i > 0; --i)	//更新中间节点信息
		temp[i] = temp[i - 1];
	temp[0] = op;	//蛇尾信息

	if (panduan(temp, n))	//出现重复节点，游戏结束
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
	pps_node_t *p_start = start();	//获取原始位置
	pps_node_t p;
	p = get_node();	//接收随机节点位置
	int n = 1;	//作为蛇身起始长度
	print_info(p_start, n, p);	//显示游戏开始状态
	pps_node_t op = p_start[0];	//保存尾部节点坐标

	while (1)
	{
		if (p_start[n - 1].x >= Width || p_start[n - 1].x < 0 || p_start[n - 1].y >= Height || p_start[n - 1].y < 0)	//判断出界；退出循环；游戏结束
		{
			printf("\nGame Over\n");
			break;
		}

		//接收用户指令
		char order[10];	//代表贪吃蛇移动方向
		if (p.x == p_start[n - 1].x && p.y == p_start[n - 1].y)	//蛇身长度增加；并且随机重新产生节点
		{
			n++;
			system("cls");	//清屏
			addnode(&p_start, &p, n, op);
			continue;
		}
		scanf("%s", order);
		//清屏
		system("cls");
		//Sleep(10);	//时间停留单位毫秒

		move(order, p_start, n, p, &op);	//贪吃蛇移动
		memset(order, 0, sizeof(order));
	}
	Sleep(4000);	//游戏结束，停留4秒
	free(p_start);	//释放贪吃蛇所占堆空间
	system("pause");
	return 0;
}