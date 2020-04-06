#include <string.h>
#include <string>
#pragma once
using namespace std;
struct LNode{
	int data;
	LNode* next;
};
struct Train
{
char number[20];    // 车次号
char starting[20];    // 起点站
char terminal[20];   // 终点站
char departure_time[50];   // 发车时间
int rest;    // 余票量
LNode* tickets;   // 可售的全部车票链表
LNode* kaishi;
};
typedef Train ElemType;
struct List
{
   ElemType list[100];
   int size;
};
