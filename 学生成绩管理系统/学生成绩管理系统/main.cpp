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
	fp = fopen("D:\\demo.txt", "a+");//�򿪱���ѧ����Ϣ���ļ�
	if (fp == NULL)
	{
		printf("               �ļ���ʧ��\n");
		exit(0);
	}
	UpdataFile(fp, students);//students�����ݵİ�
	fclose(fp);
	Menu();
	while (1)
	{
			system("cls");
			Menu();
		printf("               ���������ѡ��:");
		
		scanf(" %s",c);
		if (c[1] == '\0'&&isdigit(c[0]) != 0)
		{
			select = c[0];
			if (isdigit(select) != 0)//�ж������ǲ�������
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
						//��ʾѧ����Ϣ
						break;
					case '3':
						Search(students_dispaly);
						//��ѯѧ����Ϣ
						break;
					case '4':
						Alter(students);
						//�޸�ѧ����Ϣ
						break;
					case '5':
						Ranking(students);
						//��ʾ������Ϣ
						break;
					case '6':
						Delete(students);
						//ɾ��ѧ����Ϣ
						break;
					case '7':
						//ʵ�ֵ��˰�����
						Sort(students);
						break;
					case '8':
						SaveData(students, count_stu, 1);
						break;
					default:
						//�������
						break;
					}
				}
				else if (select == '0')
				{
					//��Ҫ�ж��Ƿ񱣴�������
					if (save==true)
					{
						system("cls");
						printf(FIRSTMENU1);
						printf(FIRSTMENU2);
						printf("               �˳��ɹ� ��л���ʹ��");
						break;
					}
					else
					{
						system("cls");
						printf(FIRSTMENU1);
						printf(FIRSTMENU2);
						printf("               ******************ȷ���˳���***********************\n");
						printf("                               ������ݻ�û�б���\n");
						printf("                           1 ������˳�  ���� ֱ���˳�\n");
						printf("                           ѡ��:");
						scanf(" %s", c);
						select = c[0];
						if (c[1] == '\0'&&select == '1')
						{
							SaveData(students, count_stu,0);
							printf("                           ����ɹ�,�ȴ��˳�:");
							CountDown(3);
							exit(0);
						}
						else
						{
							printf("                           �ȴ��˳�:");
							CountDown(3);
							exit(0);
						}
					}
				}
				else
				{
					printf("               ��������д�������������:");
				}
			}
		}
		else
		{
			printf("               ��������д�������������:");
			CountDown(3);//����ʱ
		}
	}
	system("pause");
}
