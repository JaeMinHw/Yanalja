/* 璽機 Щ煎薛お 撿陳濠
201811780
�窕蝜�
2021喇 錯 橾*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h> 
#include <conio.h> //getch л熱蒂 餌辨ж晦 嬪п
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

//goto(x,y) 夔樂 頂 醴憮 檜翕
void gotoxy(short a_x, short a_y)
{
	COORD caret_pos = { a_x - 1,a_y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), caret_pos);
}

// 夔樂 臢蝶お 儀鼻 滲唳п輿朝 л熱
void setColor(unsigned short text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}



struct area {
	int num; // 濰模 廓��
	char name[6]; //UA⑽衝
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
		//殮溘 嫡戲賊 �飛� 雖辦堅 п渡 濛機 褒ч

		if (ans == 1)
		{
			system("cls"); // �飛� 雖辦晦
			printf("1. 瞪羹 陛棟и 掘羲擊 摹鷗ж樟蝗棲棻.\n");
			menu1_addr();
		}
		else if (ans == 2)
		{
			system("cls"); // �飛� 雖辦晦
			printf("2. 雖羲 匐儀擊 摹鷗ж樟蝗棲棻.\n");
			sear_ch();
		}
		else if (ans == 3)
		{
			system("cls"); // �飛� 雖辦晦
			printf("3. 葬箔 跡煙擊 摹鷗ж樟蝗棲棻.\n");
			review_con();
		}
		else if (ans == 4)
		{
			system("cls"); // �飛� 雖辦晦
			printf("盪濰 �� 謙猿蒂 摹鷗ж樟蝗棲棻.\n");
			break;
		}
		else if (ans == 1234)
		{
			system("cls");
			printf("だ橾 機等檜お蒂 摹鷗ж樟蝗棲棻.");
			updata_file();
		}
		else
		{
			system("cls");
			setColor(12);
			printf("\n澀跤脹 殮溘殮棲棻. 廓�ㄧ� �挫恉媮祤撚踊n");
			setColor(15);
			menu();
		}
	
	} 

	printf("盪濰腎歷蝗棲棻.");
	Sleep(1000);
	exit(1);
	// 1蟾 晦棻葬堅 謙猿
	

}

// 詭景
void menu()
{

	int y = 8;
	gotoxy(20, 5);
	printf("撿陳濠\n");

	gotoxy(10, 6);
	printf("- 釭虜曖 萄煩 綠ч 濰模 ");

	gotoxy(11, y++);
	printf("忙式式式式式式式式式式式式式式式式式式式式忖");
	gotoxy(11, y++);
	printf("弛 1. 瞪羹 陛棟и 掘羲弛");
	gotoxy(11, y++);
	printf("戌式式式式式式式式式式式式式式式式式式式式戎");


	gotoxy(11, y++);
	printf("忙式式式式式式式式式式式式式式式式式式式式忖");
	gotoxy(11, y++);
	printf("弛 2. 雖羲 匐儀       弛");
	gotoxy(11, y++);
	printf("戌式式式式式式式式式式式式式式式式式式式式戎");

	gotoxy(11, y++);
	printf("忙式式式式式式式式式式式式式式式式式式式式忖");
	gotoxy(11, y++);
	printf("弛 3. 葬箔 跡煙       弛");
	gotoxy(11, y++);
	printf("戌式式式式式式式式式式式式式式式式式式式式戎");

	gotoxy(11, y++);
	printf("忙式式式式式式式式式式式式式式式式式式式式忖");
	gotoxy(11, y++);
	printf("弛 4. 盪濰ж堅 謙猿   弛");
	gotoxy(11, y++);
	printf("戌式式式式式式式式式式式式式式式式式式式式戎");

	gotoxy(11, y++);
	printf("忙式式式式式式式式式式式式式式式式式式式式忖");
	gotoxy(11, y++);
	printf("弛    だ橾 機等檜お   弛");
	gotoxy(11, y++);
	printf("戌式式式式式式式式式式式式式式式式式式式式戎");

	gotoxy(10, 25);
	setColor(12);
	printf("ъ陛 掘羲 諼 綠ч擎 弊旎 塽");

	gotoxy(8, 26);
	printf("婁鷓猿 籀碟擊 嫡擊 熱 氈蝗棲棻.");
	gotoxy(11, 23);
	setColor(15);
}


void sear_name(int i)
{
	FILE *fp;
	char tmp[100];
	char fl[100];
	sprintf(fl, "C:\\Users\\�窕蝜垥\Desktop\\2з喇 2з晦 璽機Щ煎薛お\\2з喇 2з晦 璽機Щ煎薛お\\雖羲葬箔\\%s.txt", temp[i].place_name);

	if ((fp = fopen(fl, "r+t")) == NULL)
	{
		printf("%s だ橾 螃Ъ 縑楝", temp[i].place_name);
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



// 雖羲匐儀 л熱
void sear_ch()
{
	//%s高擊 殮溘嫡嬴 橫替 夠檣雖 掘褻羹 area縑憮 棻 �挫恉� ��, 虜擒 掘褻羹 寰縑 氈棻賊 place_name擊 陛螳諦 place_name だ橾擊 翱棻. 斜 �� 輿模諦 葬箔蒂 棻 轎溘и棻. 
	FILE *fp;

	char are[10];
	int i = 0;
	int save = -1;

	if ((fp = fopen("where_area.txt", "r+t")) == NULL)
	{
		printf("だ橾 螃Ъ 縑楝");
		exit(1);
	}

	for (i = 0; i < NUM; i++)
	{
		fscanf(fp, "%d %s %s %s %s %s %s", &temp[i].num, &temp[i].name, &temp[i].place_name, &temp[i].place_do, &temp[i].place_si, &temp[i].place_gu, &temp[i].place_dong);

	}




	while (1)
	{

		printf("橫蛤 雖羲縑 啗褐陛蹂?");
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
				printf("%s縑 婦и 濰模殮棲棻.\n", are);
				printf("%2d. %6s :  %s %s %s %s \n\n\n", temp[i].num, temp[i].place_name, temp[i].place_do, temp[i].place_si, temp[i].place_gu, temp[i].place_dong);
				sear_name(i);

			}
			else
			{
				if (strcmp(are, temp[i].place_do) == 0)
				{
					system("cls");
					save = i;
					printf("%s縑 婦и 濰模殮棲棻.\n", are);
					printf("%2d. %6s :  %s %s %s %s \n\n\n", temp[i].num, temp[i].place_name, temp[i].place_do, temp[i].place_si, temp[i].place_gu, temp[i].place_dong);
					sear_name(i);
				}
				else
				{
					if (strcmp(are, temp[i].place_si) == 0)
					{
						system("cls");
						save = i;
						printf("%s縑 婦и 濰模殮棲棻.\n", are);
						printf("%2d. %6s :  %s %s %s %s \n\n\n", temp[i].num, temp[i].place_name, temp[i].place_do, temp[i].place_si, temp[i].place_gu, temp[i].place_dong);
						sear_name(i);
					}
					else
					{
						if (strcmp(are, temp[i].place_gu) == 0)
						{
							system("cls");
							save = i;
							printf("%s縑 婦и 濰模殮棲棻.\n", are);
							printf("%2d. %6s :  %s %s %s %s \n\n\n", temp[i].num, temp[i].place_name, temp[i].place_do, temp[i].place_si, temp[i].place_gu, temp[i].place_dong);
							sear_name(i);
						}
						else
						{
							if (strcmp(are, temp[i].place_dong) == 0)
							{
								system("cls");
								save = i;
								printf("%s縑 婦и 濰模殮棲棻.\n", are);
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
			printf("%s縑憮 陳萵 熱 氈朝 掘羲擎 橈蝗棲棻.\n", are);
			Sleep(300);

		}
		save = -1;


	}
	fclose(fp);

}

// 輿模諦 葬箔 轎溘 л熱
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
		printf("だ橾 螃Ъ 縑楝");
		exit(1);
	}

	// 輿模朝 棻 轎溘ж腎 葬箔朝 氈朝 匙虜 轎溘 0,0檜楛剪 橈擁晦




	// place_name だ橾 碳楝螃晦


	for (i = 0; i < NUM; i++)
	{
		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
		fscanf(fpa, "%d %s %s %s %s %s %s", &temp[i].num, &temp[i].name, &temp[i].place_name, &temp[i].place_do, &temp[i].place_si, &temp[i].place_gu, &temp[i].place_dong);
		sprintf(fl, "C:\\Users\\�窕蝜垥\Desktop\\2з喇 2з晦 璽機Щ煎薛お\\2з喇 2з晦 璽機Щ煎薛お\\雖羲葬箔\\%s.txt", temp[i].place_name);
		printf("  %2d. %7s :  %s %s %s %s \n", temp[i].num, temp[i].place_name, temp[i].place_do, temp[i].place_si, temp[i].place_gu, temp[i].place_dong);
		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

		
		if ((fp[i] = fopen(fl, "r+t")) == NULL)
		{
			printf("%s だ橾 螃Ъ 縑楝", temp[i].place_name);
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


	where_review(); // 輿模 葬箔 轎溘
	// 夢蝶 虜菟晦
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛 雖羲 匐儀戲煎 檜翕ж衛溥賊 2蒂 殮溘п輿撮蹂. 弛 \n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	char a;
	printf("菴煎 陛衛溥賊 q蒂 揚楝輿撮蹂\n");
	//菴煎陛晦 q
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
			printf("2. 雖羲 匐儀擊 摹鷗ж樟蝗棲棻.\n");
			sear_ch();
			break;
		}

		else
		{
			setColor(12);
			printf("澀跤殮溘ж樟蝗棲棻.\n");
			setColor(15);
		}


	}


}


//だ橾 儅撩
void updata_file()
{
	FILE *fpa;

	FILE *fp[NUM];
	char fl[100];
	int i;

	if ((fpa = fopen("where_area.txt", "r+t")) == NULL)
	{
		printf("だ橾 螃Ъ 縑楝");
		exit(1);
	}

	for (i = 0; i<NUM; i++) // 輿模朝 棻 轎溘ж腎 葬箔朝 氈朝 匙虜 轎溘 0,0檜楛剪 橈擁晦
	{
		fscanf(fpa, "%d %s %s %s %s %s %s", &temp[i].num, &temp[i].name, &temp[i].place_name, &temp[i].place_do, &temp[i].place_si, &temp[i].place_gu, &temp[i].place_dong);

	}

	//雖羲 だ橾縑朝 place_name檜 氈雖虜 葬箔だ橾檜 橈戲賊 だ橾 儅撩
	for (i = 0; i < NUM; i++)
	{
		sprintf(fl, "C:\\Users\\�窕蝜垥\Desktop\\2з喇 2з晦 璽機Щ煎薛お\\2з喇 2з晦 璽機Щ煎薛お\\雖羲葬箔\\%s.txt", temp[i].place_name);

		if ((fp[i] = fopen(fl, "r")) == NULL) {
			fprintf(stderr, "Cannot open output file.\n");

		}
		fclose(fp[i]);
	}
	Sleep(2000);
	menu();
}


//葬箔 蹺陛
void review_add()
{
	FILE *fpa3;
	char fl[100];
	char name3[10];
	// 葬箔 跡煙 爾罹輿晦
	where_review();
	int i = 0;
	int save;

	// 橫雯 葬箔 蹺陛й勒雖
	printf("橫替 濰模曖 葬箔蒂 蹺陛ж衛啊蝗棲梱? \n");
	printf("菴煎 陛晦朝 q殮棲棻.\n");

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
						sprintf(fl, "C:\\Users\\�窕蝜垥\Desktop\\2з喇 2з晦 璽機Щ煎薛お\\2з喇 2з晦 璽機Щ煎薛お\\雖羲葬箔\\%s.txt", temp[i].place_name);

						if ((fpa3 = fopen(fl, "r")) == NULL)
						{
							fprintf(stderr, "Cannot open output file.\n");

							break;
						}
						else
						{
							fpa3 = freopen(fl, "a", fpa3);
							printf("%s : 衛除擊 殮溘п輿撮蹂(ex 21.11.16) \n",temp[i].place_name);
							rewind(stdin);
							gets(temp2[i].time);
							if (strcmp(temp2[i].time, "end") == 0)
								break;
							printf("滌薄擊 殮溘п輿撮蹂 : ");
							rewind(stdin);
							scanf("%s", temp2[i].star);

							printf("除欽 葬箔(20濠 檜頂) : ");
							rewind(stdin);
							gets(temp2[i].short_review);

							printf("鼻撮 葬箔(100濠 檜頂) : ");
							gets(temp2[i].long_review);

							fprintf(fpa3, "\n%s", temp2[i].time); // 還夥翎檜 寰腎賊 評煎 嫡嬴憮 \n紫 fprintfп輿晦
							fprintf(fpa3, "\n%s", temp2[i].star);
							fprintf(fpa3, "\n%s", temp2[i].short_review);
							fprintf(fpa3, "\n%s\n", temp2[i].long_review);

							printf("蹺陛腎歷蝗棲棻.");
							fclose(fpa3);
							printf("渦 蹺陛ж衛溥賊 殮溘п輿撮蹂");
							break;
						}
						break;
					}
				
				
				}
				
				if (save == 0)
				{
					printf("錳ж衛朝 濰模朝 襄營ж雖 彊蝗棲棻. 棻衛и廓 �挫恛� 殮溘п輿撮蹂\n");
					break;
				}
				system("cls");
				where_review();
				printf("橫替 濰模曖 葬箔蒂 蹺陛ж衛啊蝗棲梱? \n");
				printf("菴煎 陛晦朝 q殮棲棻.\n");
				break;
				
		
			}
		}

	}


	printf("1. 葬箔 蹺陛 \n");
	printf("2. 葬箔 餉薯 \n");
}



// 葬箔 餉薯
void review_de()
{
	char name4[10];
	int i;
	where_review();

	printf("橫替 濰模曖 葬箔蒂 餉薯ж衛啊蝗棲梱? \n");
	printf("菴煎 陛晦朝 q殮棲棻.\n");
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
					//  斜 葬箔菟擊 掘褻羹縑 厥堅 ж釭 餉薯ж晦

				}
			}
		}
	}
}
