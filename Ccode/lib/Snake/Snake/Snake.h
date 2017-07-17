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

__declspec(dllexport)pps_node_t get_node();	//�����ȡ����ڵ� Width*Height��Χ����ӡ�����ؽڵ�

__declspec(dllexport)pps_node_t *start();	//��ʼ��Ϸ����ʼ��������ʼλ��

__declspec(dllexport)void print_info(pps_node_t *p_start, int n, pps_node_t p);	//̰����λ��

__declspec(dllexport)int panduan(const pps_node_t *p_start, int n);	//�ж�̰���߽ڵ��Ƿ����غϣ��з���1��û�з���0

__declspec(dllexport)void move(const char *c, pps_node_t *p_start, int n, pps_node_t p, pps_node_t *op);	//�ƶ�����λ��

__declspec(dllexport)void addnode(pps_node_t **p_start, pps_node_t *p, int n, pps_node_t op);	//̰���߽ڵ����ӣ����Ҹ��´�ӡ��ǰ�ڵ���Ϣ

__declspec(dllexport)int StartGame();