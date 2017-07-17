#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#pragma warning(disable:4996)

#define Width 50
#define Height 20

typedef struct pps_node_t
{
	int x;
	int y;
}pps_node_t;

__declspec(dllexport)pps_node_t get_node();	//随机获取蛇身节点 Width*Height范围；打印并返回节点

__declspec(dllexport)pps_node_t *start();	//开始游戏；初始化蛇身起始位置

__declspec(dllexport)void print_info(pps_node_t *p_start, int n, pps_node_t p);	//贪吃蛇位置

__declspec(dllexport)int panduan(const pps_node_t *p_start, int n);	//判断贪吃蛇节点是否有重合，有返回1；没有返回0

__declspec(dllexport)void move(const char *c, pps_node_t *p_start, int n, pps_node_t p, pps_node_t *op);	//移动更新位置

__declspec(dllexport)void addnode(pps_node_t **p_start, pps_node_t *p, int n, pps_node_t op);	//贪吃蛇节点增加，并且更新打印当前节点信息

__declspec(dllexport)int StartGame();