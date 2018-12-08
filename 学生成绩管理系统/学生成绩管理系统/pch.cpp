#pragma once
#include"pch.h"
int i = 0;
bool save = false;
int count_file = 0;
int count_file_teachers = 0;
int flag_alter = 0;
void CountDown(int n)
{
	while (n > 0)
	{
		printf("%d ", n);
		Sleep(1000);
		n--;
	}
	printf("\n");
}
void Menu()
{
	system("cls");
	printf(FIRSTMENU1);
	printf(FIRSTMENU2);
	printf(FIRSTMENU3);
	printf(FIRSTMENU4);
	printf(FIRSTMENU5);
	printf(FIRSTMENU6);
	printf(FIRSTMENU7);
	printf(FIRSTMENU8);
	printf(FIRSTMENU9);
}
void ScanfStuIn(STUDENT students[],STUDENT students_display[],int &count_stu)
{
	system("cls");
	int flag = 1, flag_=1; FILE *fp; char ch = '1';  int k = 1, j = 0, n = 0, p = 0, a = 0;//flag用于退出输入的循环,n是用于显示一次头顶菜单
	while (flag)
	{
		while (a==0&&p==0)
		{
			printf(FIRSTMENU1);
			printf(FIRSTMENU2);
			printf(SECONDMENU1_1);
			a = 1;
		}
		if (ch == '1')
		{
			while (1)
			{
				//printf("               Id:"); stringinput(students[i].ID, 15, "Id:");
				printf("               Id:"); stringinput(students[count_file].ID, 15, "Id:");
				if (InspectID(students_display, students[count_file].ID) != 0)
				{
					printf("               Name:"); stringinput(students[count_file].Name, 15, "Name:");//printf("               Name:"); stringinput(students[i].Name, 15, "Name:");
					printf("               Sex:"); stringinput(students[count_file].Sex, 15, "Sex:");//printf("               Sex:"); stringinput(students[i].Sex, 15, "Sex:");
					printf("               Teacher:"); stringinput(students[count_file].teacher, 15, "Teacher:");//printf("               teacher:"); stringinput(students[i].teacher, 15, "teacher:");
					printf("               class:"); stringinput(students[count_file]._class, 15, "class:");//printf("               class:"); stringinput(students[i]._class, 15, "class:");
					//i++;
					count_file++;
					printf("               输入成功\n");
					save = false;
					count_stu++;
					printf(FIRSTMENU9);
					printf(SECONDMENU1_3);
					printf(FIRSTMENU9);
					printf("               请输入你的选择:");
					ch = '0';
					getchar();
					break;//用于缓冲上一个字符
				}
			}
		}
		ch = getchar();
		flag=ScanfStuInError(ch,flag,&p,&a);
	}
	//加一个以学号为基础的统计学生个数函数
}
int ScanfStuInError(char ch,int flag,int *p,int *a)
{
	system("cls");
	if (ch == '0')
	{
		p = 0;
		return 0;
	}
	else if (ch == '1')
	{
		*p = 0;
		*a = 0;

		return 1;
	}
	else
		while (flag)
		{
			printf(FIRSTMENU1);
			printf(FIRSTMENU2);
			printf(SECONDMENU1_1);
			printf("              你的输入不符合要求，请按要求输入\n");
			printf(SECONDMENU1_3);
			*p = 1;
			return 1;
		}
}
void stringinput(char* t, unsigned lens,const char *p)
{

	char str[255];
	do
	{
		scanf("%s", str);
		//进行长度校验，超过lens值重新输入	
		if (strlen(str) > lens)
		{
			printf("               超过规定长度!\n");
			printf("               %s", p);
		}
	} while (strlen(str)>lens);
	//将输入的字条串保存到字符串t中 
	strcpy(t, str);
}
void SaveData(STUDENT students[],int &count_stu,int flag)
{
	int i;
	if (count_stu == 0)
	{
		if (flag == 0&&flag_alter==0)
		{
			system("cls");
			printf(FIRSTMENU1);
			printf(FIRSTMENU2);
			printf("               ******************确认退出中***********************\n");
			printf("                      无可保存的数据，自动退出:");
			CountDown(3);
			exit(0);
		}
		else if (flag_alter == 1)
		{
			system("cls");
			printf(FIRSTMENU1);
			printf(FIRSTMENU2);
			printf("                               保存成功\n");
			flag_alter = 0;
		}
		else
		{
			system("cls");
			printf(FIRSTMENU1);
			printf(FIRSTMENU2);
			//printf("               ******************确认退出中***********************\n");
			printf("                      无可保存的数据，自动返回上一级菜单");
			CountDown(3);
			return;
		}
	}
	system("cls");
	FILE *fp;
	if ((fp = fopen("D:\\demo.txt", "w")) == NULL)
	{
		printf("               文件保存失败\n");
		exit(0);
	}
	fwrite(students, sizeof(STUDENT),count_file, fp);
	//fwrite(students, sizeof(STUDENT), count_stu, fp);//改变思想，每次都重新将所有数据存进去;
	fclose(fp);
	printf(FIRSTMENU1);
	printf(FIRSTMENU2);
	printf(SECONDMENU8_1);
	printf("               保存成功  ");
	save = true;
	count_stu = 0;
	system("pause");
}
int ReadfromFile(STUDENT students[])
{
	system("cls");
	FILE *fp; int i;
	if ((fp = fopen("D:\\demo.txt", "r")) == NULL)
	{
		printf("               文件保存失败\n");
		exit(0);
	}
	for (i = 0; !feof(fp); i++)
	{
		fread(&students[i], sizeof(STUDENT), 1, fp);
	}
	fclose(fp);
    return i - 1;
}
void Display(STUDENT students[], int count_stu)
{
		int i = 0;
		system("cls");
		printf(FIRSTMENU1);
		printf(FIRSTMENU2);
		printf(SECONDMENU2_1);
		printf(HEADER1);
		printf(HEADER2);
		printf(HEADER3);
		for (i; i < count_stu; i++)
		{
			printf("\n");
			printf("    %s", students[i].ID);
			printf("  %s", students[i].Name);
			printf("       %s", students[i].Sex);
			printf("       %s", students[i].teacher);
			printf("       %s", students[i]._class);
			printf("       %.2lf", students[i].myScore.math);
			printf("       %.2lf", students[i].myScore.english);
			printf("       %.2lf", students[i].myScore.cLanguage);
			printf("       %.2lf", students[i].myScore.math+ students[i].myScore.english+ students[i].myScore.cLanguage);
			//printf("\n");
		}
		printf("\n");
	system("pause");
}
void Search(STUDENT students_display[])
{
	int i = 0; char c[N]; char select; int flag = 0, count = 0;
	int xiabiao[N];
	system("cls");
	printf(FIRSTMENU1);
	printf(FIRSTMENU2);
	printf(SECONDMENU3_1);
	printf(SECONDMENU3_2);
	printf(SECONDMENU3_3);
	printf("               *               0 返回上一级菜单                  *\n");
	printf(FIRSTMENU9);
	printf("               请输入你的选择:");
	while (1)
	{
		scanf("%s", c);
		if (c[1] == '\0')
		{
			select = c[0];
			if (select >= '0' && select <= '4')
			{
				switch (select)
				{
				case '1':
					Search_(students_display, xiabiao,count,'1');
					if (count==0)
					{
						printf(FIRSTMENU9);
						printf("               查询不到该信息\n");
						printf(FIRSTMENU9);
						printf("               请输入你的选择:");
					}
					else
					{
						for (i = 0; i < count; i++)
						{
							
							Display(&students_display[*xiabiao], count);//可以查重复的写法
						}
					}
					//按学号查询
					break;//continue;
				case '2':
					//按姓名查询
					Search_(students_display, xiabiao, count, '2');
					if (count == 0)
					{
						printf(FIRSTMENU9);
						printf("               查询不到该信息;");
					}
					else
					{
						MenuSearch();
						for (i = 0; i < count; i++)
						{
							Display(&students_display[xiabiao[i]]);
						}
						system("pause");
					}
					break;//continue;
				case '3':
					Search_(students_display, xiabiao, count, '3');
					if (count == 0)
					{
						printf(FIRSTMENU9);
						printf("               查询不到该信息;");
					}
					else
					{
						MenuSearch();
						for (i = 0; i < count; i++)
						{
							Display(&students_display[xiabiao[i]]);
						}
						system("pause");
					}
					//按班级查询
					break;//continue;
				case '4':
					Search_(students_display, xiabiao, count, '4');
					if (count == 0)
					{
						printf(FIRSTMENU9);
						printf("               查询不到该信息;");
					}
					else
					{
						MenuSearch();
						for (i = 0; i < count; i++)
						{
							Display(&students_display[xiabiao[i]]);
						}
						system("pause");
					}
					//按辅导员查询
					break;//continue;
				case '0':
					return;
				default:
					return;
				}
			}
			else
			{
				printf(FIRSTMENU9);
				printf("               你的输入不符合要求，请按要求输入\n");
				printf("               ");
			}
		}
		else
		{
			printf(FIRSTMENU9);
			printf("               你的输入不符合要求，请按要求输入\n");
			printf("               ");
		}
		break;
	}
}
//p是用来记录找到了多少个人
int* Search_(STUDENT students_display[], int xiabiao[], int &p,char ch)
{
	FILE *fp; char find[N];
	printf(FIRSTMENU9);
	if (ch == '1')
		printf("               请输入你要查询的学号:");
	if (ch == '2')
		printf("               请输入你要查询的姓名:");
	if (ch == '3')
		printf("               请输入你要查询的班级:");
	if (ch == '4')
		printf("               请输入你要查询的辅导员:");
	scanf("%s", find);
	int i, j = 0; p = 0;//j作为数组的下标  p用来计数
	if ((fp = fopen("D:\\demo.txt", "r")) == NULL)
	{
		printf("查询失败\n");
		return NULL;
	}
	for (i = 0; !feof(fp); i++)
	{
		fread(&students_display[i], sizeof(STUDENT), 1, fp);
	}
	fclose(fp);
	if (ch == '1')
	{
		for (i = 0; i < count_file; i++)
		{
			if (strcmp(students_display[i].ID, find) == 0)
			{
				xiabiao[p++] = i;
			}
		}
	}
	else if (ch == '2')
	{
		for (i = 0; i < count_file; i++)
		{
			if (strcmp(students_display[i].Name, find) == 0)
			{
				xiabiao[j] = i;
				j++; p++;
			}
		}
	}
	else if (ch == '3')
	{
		for (i = 0; i < count_file; i++)
		{
			if (strcmp(students_display[i]._class, find) == 0)
			{
				xiabiao[j] = i;
				j++; p++;
				//xiabiao[p++] = i;
			}
		}
	}
	else
	{
		for (i = 0; i < count_file; i++)
		{
			if (strcmp(students_display[i].teacher, find) == 0)
			{
				xiabiao[j] = i;
				j++; p++;
			}
		}
	}
	return xiabiao;
}
int InspectID(STUDENT students_display[], const char *p)
{
	FILE *fp; int j;
	if ((fp = fopen("D:\\demo.txt", "r")) == NULL)
	{
		printf("               文件保存失败\n");
		exit(0);
	}
	for (j = 0; !feof(fp); j++)
	{
		fread(&students_display[j], sizeof(STUDENT), 1, fp);
		if (strcmp(students_display[j].ID,p)==0)
		{
			printf("               你输入的ID已存在,请重新输入:");
			CountDown(3);
			return 0;
		}
	}
	fclose(fp);
	return 1;
}
void UpdataFile(FILE *fp,STUDENT students[])
{
	count_file = 0; STUDENT test;
	int i = 0; /*int wjcd;
	fseek(fp, 0, 2);
	wjcd = ftell(fp);
	fseek(fp, 0, 0);
	while (wjcd != ftell(fp))
	{
		if (fread(&students[i++], sizeof(STUDENT), 1, fp) == 1)
			count_file++;
	}*/
	while (!feof(fp))//如果是在读取函数之前进行判断，则如果文件最后一行是空白行，可能会造成内存错误。baidu
		if (fread(&students[i++], sizeof(STUDENT), 1, fp) == 1)
		{
			count_file++;
		}//为什么多读一行呢*/
}
void Display(STUDENT students[])
{
	printf("    %s", students[i].ID);
	printf("  %s", students[i].Name);
	printf("       %s", students[i].Sex);
	printf("       %s", students[i].teacher);
	printf("       %s", students[i]._class);
	printf("       %.2lf", students[i].myScore.math);
	printf("       %.2lf", students[i].myScore.english);
	printf("       %.2lf", students[i].myScore.cLanguage);
	printf("       %.2lf", students[i].myScore.math + students[i].myScore.english + students[i].myScore.cLanguage);
	printf("\n");
}
void MenuSearch()
{
	system("cls");
	printf(FIRSTMENU1);
	printf(FIRSTMENU2);
	printf(SECONDMENU2_1);
	printf(HEADER1);
	printf(HEADER2);
	printf(HEADER3);
}
void Alter(STUDENT students[])
{
	FILE *fp; int i,flag=0,flag_=1,flag_2=0;//flag用于是否找到了该学生,flag_用于是否结束修改成绩
	double goal = 0;
	char find[N]; char select[N];
	system("cls");
	printf(FIRSTMENU1);
	printf(FIRSTMENU2);
	printf(SECONDMENU4_1);
	printf("               请输入你要修改的学号:");
	stringinput(find, 15, "请重新输入:");
	for (i = 0; i <count_file; i++)
	{
		if (strcmp(students[i].ID, find)==0)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
	{
		printf(SECONDMENU4_1);
		printf(SECONDMENU4_2);
		printf(SECONDMENU4_3);
		while (flag_)
		{
			printf(FIRSTMENU9);
			printf("               你要修改成绩的学号为:%s\n", find);
			Display(&students[i]);
			printf("               请输入你要修改的科目:");
			scanf(" %s", select);
			if (select[1] == '\0')
			{
				flag_2 = 1;
				flag_alter = 1;
				if (select[0] == '1')//数学
				{
					while (1)
					{
						printf(FIRSTMENU9);
						printf("               请输入你要修改的分数:");
						scanf("%lf", &goal);
						if (goal < 0 || goal>100)
						{
							printf(FIRSTMENU9);
							printf("              你输入的分数有错误，请重新输入:\n");
							continue;
						}
						printf(FIRSTMENU9);
						printf("               修改成功\n");
						break;
					}
					students[i].myScore.math = goal;
				}
				else if (select[0] == '2')//英语
				{
					while (1)
					{
						printf(FIRSTMENU9);
						printf("               请输入你要修改的分数:");
						scanf("%lf", &goal);
						if (goal < 0 || goal>100)
						{
							printf(FIRSTMENU9);
							printf("              你输入的分数有错误，请重新输入:\n");
							continue;
						}
						printf(FIRSTMENU9);
						printf("               修改成功\n");
						break;
					}
					students[i].myScore.english = goal;
				}
				else if (select[0] == '3')//C语言
				{
					while (1)
					{
						printf(FIRSTMENU9);
						printf("               请输入你要修改的分数:");
						scanf("%lf", &goal);
						if (goal < 0 || goal>100)
						{
							printf(FIRSTMENU9);
							printf("              你输入的分数有错误，请重新输入:\n");
							continue;
						}
						printf(FIRSTMENU9);
						printf("               修改成功\n");
						break;
					}
					students[i].myScore.cLanguage = goal;
				}
				else if (select[0] == '0')
				{
					return;
				}
				else 
				{
					flag_2 = 0;
					flag_alter = 0;
					printf("               你的输入不符合要求，请按要求输入:\n");
					printf(SECONDMENU4_2);
					printf(SECONDMENU4_3);
				}
			}
			else
			{
				printf("               你的输入不符合要求，请按要求输入:\n");
				printf(SECONDMENU4_2);
				printf(SECONDMENU4_3);
			}
			if (flag_2==1)
			{
				printf(FIRSTMENU9);
				printf("               是否继续修改:\n");
				printf("               1 继续修改    其他 退出");
				scanf("%s", &select);
				if (select[0] == '1')
					flag_ = 1;
				else
					flag_ = 0;
			}
		}
		
	}
	else
	{
		printf(FIRSTMENU9);
		printf("               没有查询到要修改的学号,请重新输入:");
		CountDown(3);
		Alter(students);//递归调用
	}
}
void Ranking(STUDENT students[])
{
	system("cls");
	printf(FIRSTMENU1);
	printf(FIRSTMENU2);
	printf(SECONDMENU5_1);
	if (count_file == 0)
	{
		printf("               当前无可排名的学生\n");
		return;
	}
	STUDENT students_ranking[N];
	int i; char select[N];
	for (i = 0; i < count_file; i++)
	{
		students_ranking[i] = students[i];
	}
	printf(SECONDMENU5_2);
	printf(SECONDMENU5_3);
	printf(SECONDMENU5_4);
	while (1)
	{
		printf("               请输入你的选择:");
		scanf("%s", select);
		if (select[1] == '\0')
		{
			if (select[0] == '1')
			{
				//用冒泡排序
				BubbleSort(students, count_file);
				break;
			}
			else if (select[0] == '2')
			{
				//用堆排序
				Heapsort(students, count_file);
				break;
			}
			else if (select[0] == '3')
			{
				InsertSort(students, count_file);
				//用直接插入排序
				break;
			}
			else if (select[0] == '4')
			{
				//用直接插入排序2
				InsertSort2(students, count_file);
				break;
			}
			else if (select[0] == '0')
			{
				break;
			}
			else
			{

			}
		}
		else
		{
			printf("               你的输入有误,请重新输入\n");
			printf(SECONDMENU5_2);
			printf(SECONDMENU5_3);
		}
	}
}
void Delete(STUDENT students[])
{
	system("cls");
	char delete_[N];	int flag = 0;		int i = 0;//flag用于判断是否找到学生
	int j = 0;
	char select[N];
	printf(FIRSTMENU1);
	printf(FIRSTMENU2);
	printf(SECONDMENU6_1);
	printf("               请输入你删除的学生学号:");
	scanf(" %s", delete_);
	for (i = 0; i < count_file; i++)
	{
		if (strcmp(students[i].ID, delete_) == 0)
		{
			flag = 1;
			break;
		}
	}
	if (flag)
	{
		printf(FIRSTMENU9);
		printf("               你要删除的学生信息\n");
		Display(&students[i]);
		printf(FIRSTMENU9);
		printf("               请慎重选择是否删除该信息\n");
		printf(FIRSTMENU9);
		printf("               *        1 确认删除           其他 取消           *\n");
		printf(FIRSTMENU9);
		printf("               ");
		scanf(" %s", select);
		if (select[1] == '\0'&&select[0] == '1')
		{
			for (j = i; j < count_file; j++)
			{
				students[j] = students[j + 1];
			}
			count_file--;
			printf(FIRSTMENU9);
			printf("               删除成功\n");
			flag_alter = 1;
			//这里还要考虑保存的问题
			system("pause");
			return;
		}
		else
			return;
	}
	else
	{
		printf(FIRSTMENU9);
		printf("               没有找到要删除的学生,请确认该学生是否存在");
		CountDown(3);
		return;
	}
}
void Sort(STUDENT students[])
{
	//先排班级在排学号
	int i,j,k=0,l=0;
	int flag = 1;
	double num[N];
	STUDENT students_sort[N];
	const char *p[30]; /*= { "0","0","0","0","0" }*/
	const char *str[30];
	for (i = 0; i < 30; i++)
	{
		p[i] = { "0" };
		str[i] = { "0" };
	}
	for (i = 0; i < count_file; i++)
	{
		for (j = 0; j < 30; j++)
		{
			if (strcmp(students[i]._class, p[j] )==0)
				{
					flag = 0;
					break;
				}
			else
				{
					flag = 1;
				}
		}
		if (flag == 1)
		{
			p[k++] = students[i]._class;
		}
	}
	//这里是排好班级先
	for (j = 0; j < k; j++)//从第一个班级开始
	{
		for (i = 0; i < count_file; i++)
		{
			if (strcmp(students[i]._class, p[j]) == 0)
			{
				students_sort[l++] = students[i];
			}
			else{}
		}
	}
	for (i = 0; i < count_file; i++)
	{
		num[i] = atof(students_sort[i].ID);
	}
	//先对里面的数字进行排序,然后再将里面的数据拿出
	for (i = 0; i < count_file; i++)//最后做这一步
	{
		students[i] = students_sort[i];
	}
	printf(FIRSTMENU1);
	printf(FIRSTMENU2);
	printf("               排序成功\n");
	system("pause");
}
void InsertSort(STUDENT a[], int n)
{
	int i, j;
	STUDENT students_sort[N];
	for (i = 0; i < count_file; i++)
	{
		students_sort[i] = a[i];
	}
	STUDENT temp;
	for (i = 0; i < n - 1; i++)
	{
		temp = students_sort[i + 1];
		j = i;
		while (j > -1 && temp.myScore.cLanguage> students_sort[j].myScore.cLanguage)
		{
			students_sort[j + 1] = students_sort[j];
			j--;
		}
		students_sort[j + 1] = temp;
	}
	Display(students_sort, count_file);
}
void BubbleSort(STUDENT a[], int n)
{
	STUDENT students_sort[N],temp_;
	for (i = 0; i < count_file; i++)
	{
		students_sort[i] = a[i];
	}
	int i, j, tag = 1;
	double temp;
	for (i = 1; i < n&&tag == 1; i++)
	{
		tag = 0;
		for (j = 0; j < n - i; j++)
		{
			if (students_sort[j].myScore.math < students_sort[j + 1].myScore.math)
			{
				tag = 1; 
				temp_= students_sort[j];
				students_sort[j] = students_sort[j + 1];
				students_sort[j + 1] = temp_;
			}
		}
	}
	Display(students_sort, count_file);
}
void CreatHeap(STUDENT a[], int n, int h)
{
	//调整非叶结点a[h]以满足最大堆定义，n为数组元素个数
	int i, j, tag;//tag用来判断结束条件
	STUDENT temp;
	i = h;
	j = 2 * i + 1;
	temp = a[i];
	tag = 0;
	while (j < n&&tag != 1)
	{
		if (j < n - 1 && a[j].myScore.english > a[j + 1].myScore.english)
			j++;
		if (temp.myScore.english < a[j].myScore.english)
			tag = 1;
		else
		{
			a[i] = a[j];
			i = j;
			j = 2 * i + 1;
		}
	}
	a[i] = temp;
}
void InitCreatHeap(STUDENT a[], int n)
{
	//将数组a中调整为最大堆
	int i;
	for (i = (n - 2) / 2; i >= 0; i--)
		CreatHeap(a, n, i);
}
void Heapsort(STUDENT a[], int n)
{
	int i;
	STUDENT temp;
	STUDENT students_sort[N];
	for (i = 0; i < count_file; i++)
	{
		students_sort[i] = a[i];
	}
	InitCreatHeap(students_sort, n);
	for (i = n - 1; i > 0; i--)
	{
		temp = students_sort[0];
		students_sort[0] = students_sort[i];
		students_sort[i] = temp;
		CreatHeap(students_sort, i, 0);
	}
	Display(students_sort, count_file);
}
void InsertSort2(STUDENT a[], int n)
{
	int i, j;
	STUDENT students_sort[N];
	for (i = 0; i < count_file; i++)
	{
		students_sort[i] = a[i];
	}
	STUDENT temp;
	for (i = 0; i < n - 1; i++)
	{
		temp = students_sort[i + 1];
		j = i;
		while (j > -1 && (temp.myScore.cLanguage+temp.myScore.english+temp.myScore.math) > students_sort[j].myScore.cLanguage
			+students_sort[j].myScore.english+ students_sort[j].myScore.math)
		{
			students_sort[j + 1] = students_sort[j];
			j--;
		}
		students_sort[j + 1] = temp;
	}
	Display(students_sort, count_file);
}