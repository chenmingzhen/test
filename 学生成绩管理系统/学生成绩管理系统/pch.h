#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<conio.h>
#define N 30
typedef struct
{
double math;
double english;
double cLanguage;
}SCORE;
typedef struct Student
{
	char Name[N] = {'\0'};
	char Sex[N] = { '\0' };
	char ID[N] = { '\0' };
	char teacher[N] = { '\0' };
	char _class[N] = { '\0' };
	SCORE myScore = {0,0,0};
}STUDENT;
#include"SequenceList.h"
typedef struct
{
	char Name[N];
	SequenceList p;
}TEACHER;
#define FIRSTMENU1 "               ---------------------------------------------------\n"
#define FIRSTMENU2 "                              ѧ���ɼ�����ϵͳ\n"
#define FIRSTMENU3 "               ********************���˵�*************************\n"
#define FIRSTMENU4 "               *        1 ����ѧ����Ϣ       2 ��ʾѧ����Ϣ      *\n"
#define FIRSTMENU5 "               *        3 ��ѯѧ����Ϣ       4 �޸�ѧ����Ϣ      *\n"
#define FIRSTMENU6 "               *        5 ��ʾ������Ϣ       6 ɾ��ѧ����Ϣ      *\n"
#define FIRSTMENU7 "               *        7 ��Ϣ����           8 ����ѧ����Ϣ      *\n"
#define FIRSTMENU8 "               *        0 �˳�ϵͳ                               *\n"
#define FIRSTMENU9 "               ***************************************************\n"
#define SECONDMENU1_1 "               *****************����ѧ����Ϣ**********************\n"
#define SECONDMENU1_2 "               �뿪ʼ������Ϣ ע��ÿ�����͵���Ϣ֮��Ŀո�\n"
#define SECONDMENU1_3 "               *        1 ��������           0 ������һ���˵�    *\n"
#define SECONDMENU8_1 "               *****************����ѧ����Ϣ**********************\n"
#define SECONDMENU2_1 "               *****************��ʾѧ����Ϣ**********************\n"
#define SECONDMENU3_1 "               *****************��ѯѧ����Ϣ**********************\n"
#define SECONDMENU3_2 "               *        1 ��ѧ�Ų�ѯ        2 ��������ѯ         *\n"
#define SECONDMENU3_3 "               *        3 ���༶��ѯ        4 ������Ա��ѯ       *\n"
#define SECONDMENU4_1 "               *****************�޸�ѧ����Ϣ**********************\n"
#define SECONDMENU4_2 "               *        1 �޸���ѧ           2 �޸�Ӣ��          *\n"
#define SECONDMENU4_3 "               *        3 �޸�C����          0 ������һ���˵�    *\n"
#define SECONDMENU5_1 "               *****************��ʾ������Ϣ**********************\n"
#define SECONDMENU5_2 "               *        1 ��������           2 Ӣ������          *\n"
#define SECONDMENU5_3 "               *        3 C��������          4 ��������          *\n"
#define SECONDMENU5_4 "               *        0 ������һ���˵�                         *\n"
#define SECONDMENU6_1 "               *****************ɾ��ѧ����Ϣ**********************\n"
#define HEADER1 "    --------------------------------ѧ����Ϣ-----------------------------------------------\n"
#define HEADER2 "   |ѧ��      |����      |�Ա�      |����Ա    |       �༶        |    ����    |    Ӣ��    |    C����   |    �ܷ�    |\n"
#define HEADER3 "   |----------|----------|----------|----------|-------------------|------------|------------|------------|------------|\n"
void Menu();
void ScanfStuIn(STUDENT students[], STUDENT students_display[], int &count_stu);
int ScanfStuInError(char ch, int flag, int *p,int *a);
void stringinput(char* t, unsigned lens,const char *p);
void  CountDown(int n);
void SaveData(STUDENT students[],int &count_stu,int flag);//flag�������������ֱ�ӵ��û����˳��ǵ���
int ReadfromFile(STUDENT students[]);
void Display(STUDENT students[], int count_stu);
void Search(STUDENT students_display[]);
int* Search_(STUDENT students_display[], int xiabiao[], int &p, char ch);
int InspectID(STUDENT students_display[], const char *p);
void UpdataFile(FILE *fp,STUDENT students[]);
void Display(STUDENT students[]);
void MenuSearch();
void Alter(STUDENT students[]);
void Ranking(STUDENT students[]);
void Delete(STUDENT students[]);
void Sort(STUDENT students[]);
void InsertSort(STUDENT a[], int n);
void BubbleSort(STUDENT a[], int n);
void CreatHeap(STUDENT a[], int n, int h);
void InitCreatHeap(STUDENT a[], int n);
void Heapsort(STUDENT a[], int n);
void InsertSort2(STUDENT a[], int n);