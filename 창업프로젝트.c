/* â�� ������Ʈ �߳���
201811780 
Ȳ���
2021�� �� ��*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h> 
#include <conio.h> //getch �Լ��� ����ϱ� ����

#include"bit_map.h"
#include"menu1.h"


#define ESC 0x1b
#define NUM 3

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



// ��� �˻�
void search_place(char S[])
{
	//���ϰ��� �ִٸ� �ش� ���� ����, ����, �ּҸ� ����ϴ� �Լ� ȣ��
}


// �ּҿ� ����, ���ܸ���, �󼼸��� ���



// ���� ���� �ҷ�����
void print_review()
{

}


// �ּҿ� ����, ���ܸ���, �󼼸��� ���


// ��� ��� ��ü �ҷ�����
void read_place()
{

}


// ���� �߰�
void insert_review()
{

}

// ���� ����
void modify_review()
{

}


// ���� ���� �� ����
void save_review()
{

}


struct area { 
	int num; // ��� ��ȣ
	char name[5]; //UA����
	char place_name[15];
	char place_do[10];
	char place_si[10];
	char place_gu[10];
	char place_dong[15];
};




struct review {
	char name[7];
	int star;
	char short_review[40];
	char long_review[200];
};


struct area temp[NUM];
struct review temp2[NUM];

// �ּҿ� ���� �� ���ܸ��� ���
void menu1_addr()
{
	FILE *fp;
	FILE *fp2;
	FILE *fp3;
	int i = 0;

	map_print();

	if ((fp = fopen("where_area.txt", "r+t")) == NULL)
	{
		printf("���� ���� ����");
		exit(1);
	}
	if ((fp3 = fopen("short_review.txt", "r+t")) == NULL)
	{
		printf("���� ���� ����");
		exit(1);
	}
	if ((fp2 = fopen("star_review.txt", "r+t")) == NULL)
	{
		printf("����2 ���� ����");
		exit(1);

	}


	gotoxy(0, 60);
	for(i=0;i<NUM;i++) // �ּҴ� �� ����ϵ� ����� �ִ� �͸� ��� 0,0�̷��� ���ֱ�
	{
		fscanf(fp, "%d %s %s %s %s %s %s", &temp[i].num,  &temp[i].name, &temp[i].place_name, &temp[i].place_do, &temp[i].place_si, &temp[i].place_gu, &temp[i].place_dong );	
		fgets(temp2[i].short_review, 40, fp3);
		fscanf(fp2, "%s %d ",&temp2[i].name, &temp2[i].star);
	
	}
	printf("\n\n");
	for(i=0;i<NUM;i++)
	{
		printf("%2d. %6s :  %s %s %s %s \n", temp[i].num, temp[i].place_name, temp[i].place_do, temp[i].place_si, temp[i].place_gu, temp[i].place_dong );
		printf("      ���� : %d   %s\n", temp2[i].star,temp2[i].short_review);
		
	}


	fclose(fp);
	fclose(fp3);
	fclose(fp2);

}

void sear_ch()
{
	FILE *fp;
	FILE *fp2;
	FILE *fp3;
	FILE *fp4;
	char are[10];
	int i = 0;
	int save = -1;

	
	
	if ((fp = fopen("where_area.txt", "r+t")) == NULL)
	{
		printf("���� ���� ����");
		exit(1);
	}
	if ((fp2 = fopen("star_review.txt", "r+t")) == NULL)
	{
		printf("���� ���� ����");
		exit(1);
	}
	if ((fp3 = fopen("short_review.txt", "r+t")) == NULL)
	{
		printf("���� ���� ����");
		exit(1);
	}
	if ((fp4 = fopen("long_review.txt", "r+t")) == NULL)
	{
		printf("���� ���� ����");
		exit(1);
	}
	

	for (i = 0; i < NUM; i++)
	{
		fscanf(fp, "%d %s %s %s %s %s %s", &temp[i].num, &temp[i].name, &temp[i].place_name, &temp[i].place_do, &temp[i].place_si, &temp[i].place_gu, &temp[i].place_dong);
		fgets(temp2[i].short_review, 40, fp3);
		fscanf(fp2, "%s %d ", &temp2[i].name, &temp2[i].star);

	}
	

	

	while(1)
	{
		
		printf("��� ������ ��Ű���?");
		scanf("%s", &are);
		if (strcmp(are, "end") == 0)
			break;
		
		for (i = 0; i < NUM; i++)
		{
			if (strcmp(are, temp[i].place_name) == 0)
			{
				system("cls");
				save = i;
				printf("%s�� ���� ����Դϴ�.\n", are);
				printf("%2d. %6s :  %s %s %s %s \n\n\n", temp[i].num, temp[i].place_name, temp[i].place_do, temp[i].place_si, temp[i].place_gu, temp[i].place_dong);
				
			}
			else
			{
				if (strcmp(are, temp[i].place_do) == 0)
				{
					system("cls");
					save = i;
					printf("%s�� ���� ����Դϴ�.\n", are);
					printf("%2d. %6s :  %s %s %s %s \n\n\n", temp[i].num, temp[i].place_name, temp[i].place_do, temp[i].place_si, temp[i].place_gu, temp[i].place_dong);
				}
				else
				{
					if (strcmp(are, temp[i].place_si) == 0)
					{
						system("cls");
						save = i;
						printf("%s�� ���� ����Դϴ�.\n", are);
						printf("%2d. %6s :  %s %s %s %s \n\n\n", temp[i].num, temp[i].place_name, temp[i].place_do, temp[i].place_si, temp[i].place_gu, temp[i].place_dong);
					}
					else
					{
						if (strcmp(are, temp[i].place_gu) == 0)
						{
							system("cls");
							save = i;
							printf("%s�� ���� ����Դϴ�.\n", are);
							printf("%2d. %6s :  %s %s %s %s \n\n\n", temp[i].num, temp[i].place_name, temp[i].place_do, temp[i].place_si, temp[i].place_gu, temp[i].place_dong);
						}
						else
						{
							if (strcmp(are, temp[i].place_dong) == 0)
							{
								system("cls");
								save = i;
								printf("%s�� ���� ����Դϴ�.\n", are);
								printf("%2d. %6s :  %s %s %s %s \n\n\n", temp[i].num, temp[i].place_name, temp[i].place_do, temp[i].place_si, temp[i].place_gu, temp[i].place_dong);
							}

						}

					}
				}

			}
			
		}
		
		if (save == -1)
		{
			printf("%s���� ���� �� �ִ� ������ �����ϴ�.",are);
		}	
		
		
	} 
	
	fclose(fp);
	
	
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

	gotoxy(10, 25);
	setColor(12);
	printf("�㰡 ���� �� ������ ���� ��");

	gotoxy(8, 26);
	printf("���·� ó���� ���� �� �ֽ��ϴ�.");
	gotoxy(11, 22);
	setColor(15);
}


// ����

int main()
{
	int ans;

	menu();

	do
	{
	
		scanf("%d", &ans);
		//�Է� ������ ȭ�� ����� �ش� �۾� ����

		if (ans == 1)
		{
			system("cls"); // ȭ�� �����
			printf("1. ��ü ������ ������ �����ϼ̽��ϴ�.\n");
			menu1_addr();
			printf("\n\n ���� �˻��� 2���Դϴ�. \n\n");
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
		}
		else if (ans == 4)
		{
			system("cls"); // ȭ�� �����
			printf("���� �� ���Ḧ �����ϼ̽��ϴ�.\n");
			break;
		}
		else
		{
			system("cls"); // ȭ�� �����
			printf("\n�߸��� �Է��Դϴ�. ��ȣ�� Ȯ�����ּ���\n");
			menu();
		}
	} while (ans != 4);
	
	printf("����Ǿ����ϴ�.");
	Sleep(1000);
	exit(1);
	// 1�� ��ٸ��� ����
}

