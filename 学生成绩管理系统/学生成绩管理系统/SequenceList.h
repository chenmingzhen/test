#pragma once
typedef struct
{
	STUDENT list[N];
	int size;
}SequenceList;
void ListInitialize(SequenceList *L);/*初始化循序表*/
int ListLength(SequenceList L);/*计算顺序表长度*/
int ListInsert(SequenceList *L, int i, STUDENT x);/*插入元素*/
int ListDelete(SequenceList *L, int i, STUDENT *x);/*删除元素*/
int ListGet(SequenceList L, int i, STUDENT *x);/*获取元素*/


