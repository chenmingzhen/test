#include"pch.h"
#include"SequenceList.h"
void ListInitialize(SequenceList *L)/*初始化循序表*/
{
	L->size = 0;
}
int ListLength(SequenceList L)/*计算顺序表长度*/
{
	return L.size;
}
int ListInsert(SequenceList *L, int i, STUDENT x)/*插入元素*/
{
	int j;
	if (L->size >= N)
	{
		printf("顺序表已满\n");
		return 0;
	}
	else if (i<0 || i>L->size)
	{
		printf("参数i非法\n");
		return 0;
	}
	else
	{
		for (j = L->size; j > i; j--)
			L->list[j] = L->list[j - 1];
		L->list[i] = x;
		L->size++;
		return 1;
	}
}
int ListDelete(SequenceList *L, int i, STUDENT *x)/*删除元素*/
{
	int j;
	if (L->size <= 0)
	{
		printf("顺序表已空无数据可删除\n");
		return 0;
	}
	else if (i<0 || i>L->size - 1)
	{
		printf("参数i不合法\n");
		return 0;
	}
	else
	{
		*x = L->list[i];
		for (j = i + 1; j <= L->size; j++)
		{
			L->list[j - 1] = L->list[j];
		}
		L->size--;
		return 1;
	}
}
int ListGet(SequenceList L, int i, STUDENT *x)/*获取元素*/
{
	if (i<0 || i>L.size - 1)
	{
		printf("参数i不合法\n");
		return 0;
	}
	else
	{
		*x = L.list[i];
		return 1;
	}
}

