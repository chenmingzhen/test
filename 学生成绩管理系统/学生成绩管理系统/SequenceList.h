#pragma once
typedef struct
{
	STUDENT list[N];
	int size;
}SequenceList;
void ListInitialize(SequenceList *L);/*��ʼ��ѭ���*/
int ListLength(SequenceList L);/*����˳�����*/
int ListInsert(SequenceList *L, int i, STUDENT x);/*����Ԫ��*/
int ListDelete(SequenceList *L, int i, STUDENT *x);/*ɾ��Ԫ��*/
int ListGet(SequenceList L, int i, STUDENT *x);/*��ȡԪ��*/


