#include"pch.h"
#include"SequenceList.h"
void ListInitialize(SequenceList *L)/*��ʼ��ѭ���*/
{
	L->size = 0;
}
int ListLength(SequenceList L)/*����˳�����*/
{
	return L.size;
}
int ListInsert(SequenceList *L, int i, STUDENT x)/*����Ԫ��*/
{
	int j;
	if (L->size >= N)
	{
		printf("˳�������\n");
		return 0;
	}
	else if (i<0 || i>L->size)
	{
		printf("����i�Ƿ�\n");
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
int ListDelete(SequenceList *L, int i, STUDENT *x)/*ɾ��Ԫ��*/
{
	int j;
	if (L->size <= 0)
	{
		printf("˳����ѿ������ݿ�ɾ��\n");
		return 0;
	}
	else if (i<0 || i>L->size - 1)
	{
		printf("����i���Ϸ�\n");
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
int ListGet(SequenceList L, int i, STUDENT *x)/*��ȡԪ��*/
{
	if (i<0 || i>L.size - 1)
	{
		printf("����i���Ϸ�\n");
		return 0;
	}
	else
	{
		*x = L.list[i];
		return 1;
	}
}

