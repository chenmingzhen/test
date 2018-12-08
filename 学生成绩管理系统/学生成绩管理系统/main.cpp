#include"pch.h"
extern bool save;
extern int count_file;
extern int count_file_teachers;
void main(int a)
{
	char select; int n = 0, count_stu = 0,count_tea=0; int flag = 0; int i,k;
	char c[N];
	FILE *fp;
	STUDENT students[N], students_dispaly[N];
	TEACHER teachers[N],teacher_void[N];
	fp = fopen("D:\\demo.txt", "a+");//打开保存学生信息的文件
	if (fp == NULL)
	{
		printf("               文件打开失败\n");
		exit(0);
	}
	UpdataFile(fp, students);//students有数据的啊
	fclose(fp);
	Menu();
	while (1)
	{
			system("cls");
			Menu();
		printf("               请输入你的选择:");
		
		scanf(" %s",c);
		if (c[1] == '\0'&&isdigit(c[0]) != 0)
		{
			select = c[0];
			if (isdigit(select) != 0)//判断输入是不是数字
			{
				//fflush(stdin);
				if (select > '0' && select <= '8')
				{
					switch (select)
					{
					case '1':
						ScanfStuIn(students,students_dispaly,count_stu);
						break;
					case '2':
						//Display(students_dispaly, ReadfromFile(students_dispaly));
						Display(students, count_file);
						//显示学生信息
						break;
					case '3':
						Search(students_dispaly);
						//查询学生信息
						break;
					case '4':
						Alter(students);
						//修改学生信息
						break;
					case '5':
						Ranking(students);
						//显示排名信息
						break;
					case '6':
						Delete(students);
						//删除学生信息
						break;
					case '7':
						//实现到了班排序
						Sort(students);
						break;
					case '8':
						SaveData(students, count_stu, 1);
						break;
					default:
						//输入错误
						break;
					}
				}
				else if (select == '0')
				{
					//还要判断是否保存了数据
					if (save==true)
					{
						system("cls");
						printf(FIRSTMENU1);
						printf(FIRSTMENU2);
						printf("               退出成功 感谢你的使用");
						break;
					}
					else
					{
						system("cls");
						printf(FIRSTMENU1);
						printf(FIRSTMENU2);
						printf("               ******************确认退出中***********************\n");
						printf("                               你的数据还没有保存\n");
						printf("                           1 保存后退出  其他 直接退出\n");
						printf("                           选择:");
						scanf(" %s", c);
						select = c[0];
						if (c[1] == '\0'&&select == '1')
						{
							SaveData(students, count_stu,0);
							printf("                           保存成功,等待退出:");
							CountDown(3);
							exit(0);
						}
						else
						{
							printf("                           等待退出:");
							CountDown(3);
							exit(0);
						}
					}
				}
				else
				{
					printf("               你的输入有错误，请重新输入:");
				}
			}
		}
		else
		{
			printf("               你的输入有错误，请重新输入:");
			CountDown(3);//倒计时
		}
	}
	system("pause");
}
