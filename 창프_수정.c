/* â�� ������Ʈ �߳���
201811780
Ȳ���
2021�� �� ��*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h> 
#include <conio.h> //getch �Լ��� ����ϱ� ����
#include <time.h>

#include"menu1.h"
#include"mapping.h"
#include"review_me.h"

void menu();
void sear_name(int i);
void sear_ch();
void where_review();

void menu1_addr();
void updata_file();

void map_print();


#define NUM 5

//goto(x,y) �ܼ� �� Ŀ�� �̵�
void gotoxy(short a_x, short a_y)
{
	COORD caret_pos = { a_x - 1,a_y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), caret_pos);
}

// �ܼ� �ؽ�Ʈ ���� �������ִ� �Լ�
void setColor(unsigned short text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}



struct area {
	int num; // ��� ��ȣ
	char name[6]; //UA����
	char place_name[15];
	char place_do[10];
	char place_si[10];
	char place_gu[10];
	char place_dong[15];
};

struct review {
	char time[30];
	char star[10];
	char short_review[40];
	char long_review[200];
};

struct area temp[NUM];
struct review temp2[NUM];


int main()
{

	int ans;
	menu();

	

	while (1)
	{
		
		scanf("%d", &ans);
		//�Է� ������ ȭ�� ����� �ش� �۾� ����

		if (ans == 1)
		{
			system("cls"); // ȭ�� �����
			printf("1. ��ü ������ ������ �����ϼ̽��ϴ�.\n");
			menu1_addr();
		}
		else if (ans == 2)
		{
			system("cls"); // ȭ�� �����
			printf("2. ���� �˻��� �����ϼ̽��ϴ�.\n");
			sear_ch();
		}
		else if (ans == 3)
		{
			system("cls"); // ȭ�� �����
			printf("3. ���� ����� �����ϼ̽��ϴ�.\n");
			review_con();
		}
		else if (ans == 4)
		{
			system("cls"); // ȭ�� �����
			printf("���� �� ���Ḧ �����ϼ̽��ϴ�.\n");
			break;
		}
		else if (ans == 1234)
		{
			system("cls");
			printf("���� ������Ʈ�� �����ϼ̽��ϴ�.");
			updata_file();
		}
		else
		{
			system("cls");
			setColor(12);
			printf("\n�߸��� �Է��Դϴ�. ��ȣ�� Ȯ�����ּ���\n");
			setColor(15);
			menu();
		}
	
	} 

	printf("����Ǿ����ϴ�.");
	Sleep(1000);
	exit(1);
	// 1�� ��ٸ��� ����
	

}

// �޴�
void menu()
{

	int y = 8;
	gotoxy(20, 5);
	printf("�߳���\n");

	gotoxy(10, 6);
	printf("- ������ ��� ���� ��� ");

	gotoxy(11, y++);
	printf("��������������������������������������������");
	gotoxy(11, y++);
	printf("�� 1. ��ü ������ ������");
	gotoxy(11, y++);
	printf("��������������������������������������������");


	gotoxy(11, y++);
	printf("��������������������������������������������");
	gotoxy(11, y++);
	printf("�� 2. ���� �˻�       ��");
	gotoxy(11, y++);
	printf("��������������������������������������������");

	gotoxy(11, y++);
	printf("��������������������������������������������");
	gotoxy(11, y++);
	printf("�� 3. ���� ���       ��");
	gotoxy(11, y++);
	printf("��������������������������������������������");

	gotoxy(11, y++);
	printf("��������������������������������������������");
	gotoxy(11, y++);
	printf("�� 4. �����ϰ� ����   ��");
	gotoxy(11, y++);
	printf("��������������������������������������������");

	gotoxy(11, y++);
	printf("��������������������������������������������");
	gotoxy(11, y++);
	printf("��    ���� ������Ʈ   ��");
	gotoxy(11, y++);
	printf("��������������������������������������������");

	gotoxy(10, 25);
	setColor(12);
	printf("�㰡 ���� �� ������ ���� ��");

	gotoxy(8, 26);
	printf("���·� ó���� ���� �� �ֽ��ϴ�.");
	gotoxy(11, 23);
	setColor(15);
}


void sear_name(int i)
{
	FILE *fp;
	char tmp[100];
	char fl[100];
	sprintf(fl, "C:\\Users\\Ȳ���\\Desktop\\2�г� 2�б� â��������Ʈ\\2�г� 2�б� â��������Ʈ\\��������\\%s.txt", temp[i].place_name);

	if ((fp = fopen(fl, "r+t")) == NULL)
	{
		printf("%s ���� ���� ����", temp[i].place_name);
		//exit(1);
	}
	else
	{
		while (fgets(tmp, 100, fp))
			printf("%s", tmp);
	}
	printf("\n\n\n");
	fclose(fp);
}



// �����˻� �Լ�
void sear_ch()
{
	//%s���� �Է¹޾� ��� ������ ����ü area���� �� Ȯ���� ��, ���� ����ü �ȿ� �ִٸ� place_name�� ������ place_name ������ ����. �� �� �ּҿ� ���並 �� ����Ѵ�. 
	FILE *fp;

	char are[10];
	int i = 0;
	int save = -1;

	if ((fp = fopen("where_area.txt", "r+t")) == NULL)
	{
		printf("���� ���� ����");
		exit(1);
	}

	for (i = 0; i < NUM; i++)
	{
		fscanf(fp, "%d %s %s %s %s %s %s", &temp[i].num, &temp[i].name, &temp[i].place_name, &temp[i].place_do, &temp[i].place_si, &temp[i].place_gu, &temp[i].place_dong);

	}




	while (1)
	{

		printf("��� ������ ��Ű���?");
		scanf("%s", are);
		if (strcmp(are, "q") == 0) {
			system("cls");
			menu();
			break;
		}


		for (i = 0; i < NUM; i++)
		{
			if (strcmp(are, temp[i].place_name) == 0)
			{
				system("cls");
				save = i;
				printf("%s�� ���� ����Դϴ�.\n", are);
				printf("%2d. %6s :  %s %s %s %s \n\n\n", temp[i].num, temp[i].place_name, temp[i].place_do, temp[i].place_si, temp[i].place_gu, temp[i].place_dong);
				sear_name(i);

			}
			else
			{
				if (strcmp(are, temp[i].place_do) == 0)
				{
					system("cls");
					save = i;
					printf("%s�� ���� ����Դϴ�.\n", are);
					printf("%2d. %6s :  %s %s %s %s \n\n\n", temp[i].num, temp[i].place_name, temp[i].place_do, temp[i].place_si, temp[i].place_gu, temp[i].place_dong);
					sear_name(i);
				}
				else
				{
					if (strcmp(are, temp[i].place_si) == 0)
					{
						system("cls");
						save = i;
						printf("%s�� ���� ����Դϴ�.\n", are);
						printf("%2d. %6s :  %s %s %s %s \n\n\n", temp[i].num, temp[i].place_name, temp[i].place_do, temp[i].place_si, temp[i].place_gu, temp[i].place_dong);
						sear_name(i);
					}
					else
					{
						if (strcmp(are, temp[i].place_gu) == 0)
						{
							system("cls");
							save = i;
							printf("%s�� ���� ����Դϴ�.\n", are);
							printf("%2d. %6s :  %s %s %s %s \n\n\n", temp[i].num, temp[i].place_name, temp[i].place_do, temp[i].place_si, temp[i].place_gu, temp[i].place_dong);
							sear_name(i);
						}
						else
						{
							if (strcmp(are, temp[i].place_dong) == 0)
							{
								system("cls");
								save = i;
								printf("%s�� ���� ����Դϴ�.\n", are);
								printf("%2d. %6s :  %s %s %s %s \n\n\n", temp[i].num, temp[i].place_name, temp[i].place_do, temp[i].place_si, temp[i].place_gu, temp[i].place_dong);
								sear_name(i);
							}

						}

					}
				}

			}

		}

		if (save == -1)
		{
			system("cls");
			printf("%s���� ���� �� �ִ� ������ �����ϴ�.\n", are);
			Sleep(300);

		}
		save = -1;


	}
	fclose(fp);

}

// �ּҿ� ���� ��� �Լ�
void where_review()
{
	FILE *fpa;
	FILE *fp[NUM];
	char tmp[100];
	char fl[100];
	int i;
	int y = 3;

	if ((fpa = fopen("where_area.txt", "r+t")) == NULL)
	{
		printf("���� ���� ����");
		exit(1);
	}

	// �ּҴ� �� ����ϵ� ����� �ִ� �͸� ��� 0,0�̷��� ���ֱ�




	// place_name ���� �ҷ�����


	for (i = 0; i < NUM; i++)
	{
		printf("��������������������������������������������������������������������������������������������������������������������������������������\n");
		fscanf(fpa, "%d %s %s %s %s %s %s", &temp[i].num, &temp[i].name, &temp[i].place_name, &temp[i].place_do, &temp[i].place_si, &temp[i].place_gu, &temp[i].place_dong);
		sprintf(fl, "C:\\Users\\Ȳ���\\Desktop\\2�г� 2�б� â��������Ʈ\\2�г� 2�б� â��������Ʈ\\��������\\%s.txt", temp[i].place_name);
		printf("  %2d. %7s :  %s %s %s %s \n", temp[i].num, temp[i].place_name, temp[i].place_do, temp[i].place_si, temp[i].place_gu, temp[i].place_dong);
		printf("��������������������������������������������������������������������������������������������������������������������������������������\n");

		
		if ((fp[i] = fopen(fl, "r+t")) == NULL)
		{
			printf("%s ���� ���� ����", temp[i].place_name);
			//exit(1);
		}
		else
		{

			while (fgets(tmp, 100, fp[i]))
				printf("%s", tmp);
		}
		printf("\n -------------------------------------------------------------");
		printf("\n\n\n");
		fclose(fp[i]);


	}

	fclose(fpa);

	


}


void menu1_addr()
{
	//map_print();


	where_review(); // �ּ� ���� ���
	// �ڽ� �����
	printf("������������������������������������������������������������������������������������������������\n");
	printf("�� ���� �˻����� �̵��Ͻ÷��� 2�� �Է����ּ���. �� \n");
	printf("������������������������������������������������������������������������������������������������\n");
	char a;
	printf("�ڷ� ���÷��� q�� �����ּ���\n");
	//�ڷΰ��� q
	while (1)
	{

		scanf("%c", &a);

		if (a == 'q') {
			system("cls");
			menu();
			break;
		}

		else if (a == '2')
		{
			system("cls");
			printf("2. ���� �˻��� �����ϼ̽��ϴ�.\n");
			sear_ch();
			break;
		}

		else
		{
			setColor(12);
			printf("�߸��Է��ϼ̽��ϴ�.\n");
			setColor(15);
		}


	}


}


//���� ����
void updata_file()
{
	FILE *fpa;

	FILE *fp[NUM];
	char fl[100];
	int i;

	if ((fpa = fopen("where_area.txt", "r+t")) == NULL)
	{
		printf("���� ���� ����");
		exit(1);
	}

	for (i = 0; i<NUM; i++) // �ּҴ� �� ����ϵ� ����� �ִ� �͸� ��� 0,0�̷��� ���ֱ�
	{
		fscanf(fpa, "%d %s %s %s %s %s %s", &temp[i].num, &temp[i].name, &temp[i].place_name, &temp[i].place_do, &temp[i].place_si, &temp[i].place_gu, &temp[i].place_dong);

	}

	//���� ���Ͽ��� place_name�� ������ ���������� ������ ���� ����
	for (i = 0; i < NUM; i++)
	{
		sprintf(fl, "C:\\Users\\Ȳ���\\Desktop\\2�г� 2�б� â��������Ʈ\\2�г� 2�б� â��������Ʈ\\��������\\%s.txt", temp[i].place_name);

		if ((fp[i] = fopen(fl, "r")) == NULL) {
			fprintf(stderr, "Cannot open output file.\n");

		}
		fclose(fp[i]);
	}
	Sleep(2000);
	menu();
}


//���� �߰�
void review_add()
{
	FILE *fpa3;
	char fl[100];
	char name3[10];
	// ���� ��� �����ֱ�
	where_review();
	int i = 0;
	int save;

	// � ���� �߰��Ұ���
	printf("��� ����� ���並 �߰��Ͻðڽ��ϱ�? \n");
	printf("�ڷ� ����� q�Դϴ�.\n");

	while (1)
	{
		
		scanf("%s", name3);
		if (strcmp(name3, "q") == 0)
		{
			system("cls");
			break;
		}
		else 
		{
			while(1)
			{
				
				for (i = 0; i < NUM; i++)
				{
					save = 0;
					if (strcmp(name3, temp[i].place_name) == 0)
					{
						save = 1;
					}
					

					if (save == 1)
					{
						sprintf(fl, "C:\\Users\\Ȳ���\\Desktop\\2�г� 2�б� â��������Ʈ\\2�г� 2�б� â��������Ʈ\\��������\\%s.txt", temp[i].place_name);

						if ((fpa3 = fopen(fl, "r")) == NULL)
						{
							fprintf(stderr, "Cannot open output file.\n");

							break;
						}
						else
						{
							fpa3 = freopen(fl, "a", fpa3);
							printf("%s : �ð��� �Է����ּ���(ex 21.11.16) \n",temp[i].place_name);
							rewind(stdin);
							gets(temp2[i].time);
							if (strcmp(temp2[i].time, "end") == 0)
								break;
							printf("������ �Է����ּ��� : ");
							rewind(stdin);
							scanf("%s", temp2[i].star);

							printf("���� ����(20�� �̳�) : ");
							rewind(stdin);
							gets(temp2[i].short_review);

							printf("�� ����(100�� �̳�) : ");
							gets(temp2[i].long_review);

							fprintf(fpa3, "\n%s", temp2[i].time); // �ٹٲ��� �ȵǸ� ���� �޾Ƽ� \n�� fprintf���ֱ�
							fprintf(fpa3, "\n%s", temp2[i].star);
							fprintf(fpa3, "\n%s", temp2[i].short_review);
							fprintf(fpa3, "\n%s\n", temp2[i].long_review);

							printf("�߰��Ǿ����ϴ�.");
							fclose(fpa3);
							printf("�� �߰��Ͻ÷��� �Է����ּ���");
							break;
						}
						break;
					}
				
				
				}
				
				if (save == 0)
				{
					printf("���Ͻô� ��Ҵ� �������� �ʽ��ϴ�. �ٽ��ѹ� Ȯ���� �Է����ּ���\n");
					break;
				}
				system("cls");
				where_review();
				printf("��� ����� ���並 �߰��Ͻðڽ��ϱ�? \n");
				printf("�ڷ� ����� q�Դϴ�.\n");
				break;
				
		
			}
		}

	}


	printf("1. ���� �߰� \n");
	printf("2. ���� ���� \n");
}



// ���� ����
void review_de()
{
	char name4[10];
	int i;
	where_review();

	printf("��� ����� ���並 �����Ͻðڽ��ϱ�? \n");
	printf("�ڷ� ����� q�Դϴ�.\n");
	while (1)
	{
		scanf("%s", name4);
		if (name4 == 'q') 
		{
			system("cls");
			break;
		}
		else
		{
			for (i = 0; i < NUM; i++)
			{
				if (strcmp(name4, temp[i].place_name) == 0)
				{
					//  �� ������� ����ü�� �ְ� �ϳ� �����ϱ�

				}
			}
		}
	}
}
