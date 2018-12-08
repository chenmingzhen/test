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
#define FIRSTMENU2 "                              学生成绩管理系统\n"
#define FIRSTMENU3 "               ********************主菜单*************************\n"
#define FIRSTMENU4 "               *        1 输入学生信息       2 显示学生信息      *\n"
#define FIRSTMENU5 "               *        3 查询学生信息       4 修改学生信息      *\n"
#define FIRSTMENU6 "               *        5 显示排名信息       6 删除学生信息      *\n"
#define FIRSTMENU7 "               *        7 信息排序           8 保存学生信息      *\n"
#define FIRSTMENU8 "               *        0 退出系统                               *\n"
#define FIRSTMENU9 "               ***************************************************\n"
#define SECONDMENU1_1 "               *****************输入学生信息**********************\n"
#define SECONDMENU1_2 "               请开始输入信息 注意每个类型的信息之间的空格\n"
#define SECONDMENU1_3 "               *        1 继续输入           0 返回上一级菜单    *\n"
#define SECONDMENU8_1 "               *****************保存学生信息**********************\n"
#define SECONDMENU2_1 "               *****************显示学生信息**********************\n"
#define SECONDMENU3_1 "               *****************查询学生信息**********************\n"
#define SECONDMENU3_2 "               *        1 按学号查询        2 按姓名查询         *\n"
#define SECONDMENU3_3 "               *        3 按班级查询        4 按辅导员查询       *\n"
#define SECONDMENU4_1 "               *****************修改学生信息**********************\n"
#define SECONDMENU4_2 "               *        1 修改数学           2 修改英语          *\n"
#define SECONDMENU4_3 "               *        3 修改C语言          0 返回上一级菜单    *\n"
#define SECONDMENU5_1 "               *****************显示排名信息**********************\n"
#define SECONDMENU5_2 "               *        1 高数排名           2 英语排名          *\n"
#define SECONDMENU5_3 "               *        3 C语言排名          4 总评排名          *\n"
#define SECONDMENU5_4 "               *        0 返回上一级菜单                         *\n"
#define SECONDMENU6_1 "               *****************删除学生信息**********************\n"
#define HEADER1 "    --------------------------------学生信息-----------------------------------------------\n"
#define HEADER2 "   |学号      |姓名      |性别      |辅导员    |       班级        |    高数    |    英语    |    C语言   |    总分    |\n"
#define HEADER3 "   |----------|----------|----------|----------|-------------------|------------|------------|------------|------------|\n"
void Menu();
void ScanfStuIn(STUDENT students[], STUDENT students_display[], int &count_stu);
int ScanfStuInError(char ch, int flag, int *p,int *a);
void stringinput(char* t, unsigned lens,const char *p);
void  CountDown(int n);
void SaveData(STUDENT students[],int &count_stu,int flag);//flag用于这个函数是直接调用还是退出是调用
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