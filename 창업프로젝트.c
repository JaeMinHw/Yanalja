/* 창업 프로젝트 야날자
201811780 
황재민
2021년 월 일*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h> 
#include <conio.h> //getch 함수를 사용하기 위해

#include"bit_map.h"
#include"menu1.h"


#define ESC 0x1b
#define NUM 3

//goto(x,y) 콘솔 내 커서 이동
void gotoxy(short a_x, short a_y)
{
	COORD caret_pos = { a_x - 1,a_y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), caret_pos);
}

// 콘솔 텍스트 색상 변경해주는 함수
void setColor(unsigned short text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}



// 장소 검색
void search_place(char S[])
{
	//리턴값이 있다면 해당 지역 별점, 리뷰, 주소를 출력하는 함수 호출
}


// 주소와 별점, 간단리뷰, 상세리뷰 출력



// 리뷰 파일 불러오기
void print_review()
{

}


// 주소와 별점, 간단리뷰, 상세리뷰 출력


// 장소 목록 전체 불러오기
void read_place()
{

}


// 리뷰 추가
void insert_review()
{

}

// 리뷰 수정
void modify_review()
{

}


// 리뷰 저장 후 종료
void save_review()
{

}


struct area { 
	int num; // 장소 번호
	char name[5]; //UA형식
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

// 주소와 별점 및 간단리뷰 출력
void menu1_addr()
{
	FILE *fp;
	FILE *fp2;
	FILE *fp3;
	int i = 0;

	map_print();

	if ((fp = fopen("where_area.txt", "r+t")) == NULL)
	{
		printf("파일 오픈 에러");
		exit(1);
	}
	if ((fp3 = fopen("short_review.txt", "r+t")) == NULL)
	{
		printf("파일 오픈 에러");
		exit(1);
	}
	if ((fp2 = fopen("star_review.txt", "r+t")) == NULL)
	{
		printf("파일2 오픈 에러");
		exit(1);

	}


	gotoxy(0, 60);
	for(i=0;i<NUM;i++) // 주소는 다 출력하되 리뷰는 있는 것만 출력 0,0이런거 없애기
	{
		fscanf(fp, "%d %s %s %s %s %s %s", &temp[i].num,  &temp[i].name, &temp[i].place_name, &temp[i].place_do, &temp[i].place_si, &temp[i].place_gu, &temp[i].place_dong );	
		fgets(temp2[i].short_review, 40, fp3);
		fscanf(fp2, "%s %d ",&temp2[i].name, &temp2[i].star);
	
	}
	printf("\n\n");
	for(i=0;i<NUM;i++)
	{
		printf("%2d. %6s :  %s %s %s %s \n", temp[i].num, temp[i].place_name, temp[i].place_do, temp[i].place_si, temp[i].place_gu, temp[i].place_dong );
		printf("      별점 : %d   %s\n", temp2[i].star,temp2[i].short_review);
		
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
		printf("파일 오픈 에러");
		exit(1);
	}
	if ((fp2 = fopen("star_review.txt", "r+t")) == NULL)
	{
		printf("파일 오픈 에러");
		exit(1);
	}
	if ((fp3 = fopen("short_review.txt", "r+t")) == NULL)
	{
		printf("파일 오픈 에러");
		exit(1);
	}
	if ((fp4 = fopen("long_review.txt", "r+t")) == NULL)
	{
		printf("파일 오픈 에러");
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
		
		printf("어디 지역에 계신가요?");
		scanf("%s", &are);
		if (strcmp(are, "end") == 0)
			break;
		
		for (i = 0; i < NUM; i++)
		{
			if (strcmp(are, temp[i].place_name) == 0)
			{
				system("cls");
				save = i;
				printf("%s에 관한 장소입니다.\n", are);
				printf("%2d. %6s :  %s %s %s %s \n\n\n", temp[i].num, temp[i].place_name, temp[i].place_do, temp[i].place_si, temp[i].place_gu, temp[i].place_dong);
				
			}
			else
			{
				if (strcmp(are, temp[i].place_do) == 0)
				{
					system("cls");
					save = i;
					printf("%s에 관한 장소입니다.\n", are);
					printf("%2d. %6s :  %s %s %s %s \n\n\n", temp[i].num, temp[i].place_name, temp[i].place_do, temp[i].place_si, temp[i].place_gu, temp[i].place_dong);
				}
				else
				{
					if (strcmp(are, temp[i].place_si) == 0)
					{
						system("cls");
						save = i;
						printf("%s에 관한 장소입니다.\n", are);
						printf("%2d. %6s :  %s %s %s %s \n\n\n", temp[i].num, temp[i].place_name, temp[i].place_do, temp[i].place_si, temp[i].place_gu, temp[i].place_dong);
					}
					else
					{
						if (strcmp(are, temp[i].place_gu) == 0)
						{
							system("cls");
							save = i;
							printf("%s에 관한 장소입니다.\n", are);
							printf("%2d. %6s :  %s %s %s %s \n\n\n", temp[i].num, temp[i].place_name, temp[i].place_do, temp[i].place_si, temp[i].place_gu, temp[i].place_dong);
						}
						else
						{
							if (strcmp(are, temp[i].place_dong) == 0)
							{
								system("cls");
								save = i;
								printf("%s에 관한 장소입니다.\n", are);
								printf("%2d. %6s :  %s %s %s %s \n\n\n", temp[i].num, temp[i].place_name, temp[i].place_do, temp[i].place_si, temp[i].place_gu, temp[i].place_dong);
							}

						}

					}
				}

			}
			
		}
		
		if (save == -1)
		{
			printf("%s에서 날릴 수 있는 구역은 없습니다.",are);
		}	
		
		
	} 
	
	fclose(fp);
	
	
}


// 메뉴
void menu()
{

	int y = 8;
	gotoxy(20, 5);
	printf("야날자\n");

	gotoxy(10, 6);
	printf("- 나만의 드론 비행 장소 ");

	gotoxy(11, y++);
	printf("┌────────────────────┐");
	gotoxy(11, y++);
	printf("│ 1. 전체 가능한 구역│");
	gotoxy(11, y++);
	printf("└────────────────────┘");


	gotoxy(11, y++);
	printf("┌────────────────────┐");
	gotoxy(11, y++);
	printf("│ 2. 지역 검색       │");
	gotoxy(11, y++);
	printf("└────────────────────┘");

	gotoxy(11, y++);
	printf("┌────────────────────┐");
	gotoxy(11, y++);
	printf("│ 3. 리뷰 목록       │");
	gotoxy(11, y++);
	printf("└────────────────────┘");

	gotoxy(11, y++);
	printf("┌────────────────────┐");
	gotoxy(11, y++);
	printf("│ 4. 저장하고 종료   │");
	gotoxy(11, y++);
	printf("└────────────────────┘");

	gotoxy(10, 25);
	setColor(12);
	printf("허가 구역 외 비행은 벌금 및");

	gotoxy(8, 26);
	printf("과태료 처분을 받을 수 있습니다.");
	gotoxy(11, 22);
	setColor(15);
}


// 종료

int main()
{
	int ans;

	menu();

	do
	{
	
		scanf("%d", &ans);
		//입력 받으면 화면 지우고 해당 작업 실행

		if (ans == 1)
		{
			system("cls"); // 화면 지우기
			printf("1. 전체 가능한 구역을 선택하셨습니다.\n");
			menu1_addr();
			printf("\n\n 지역 검색은 2번입니다. \n\n");
		}
		else if (ans == 2)
		{
			system("cls"); // 화면 지우기
			printf("2. 지역 검색을 선택하셨습니다.\n");
			sear_ch();
		}
		else if (ans == 3)
		{
			system("cls"); // 화면 지우기
			printf("3. 리뷰 목록을 선택하셨습니다.\n");
		}
		else if (ans == 4)
		{
			system("cls"); // 화면 지우기
			printf("저장 후 종료를 선택하셨습니다.\n");
			break;
		}
		else
		{
			system("cls"); // 화면 지우기
			printf("\n잘못된 입력입니다. 번호를 확인해주세요\n");
			menu();
		}
	} while (ans != 4);
	
	printf("저장되었습니다.");
	Sleep(1000);
	exit(1);
	// 1초 기다리고 종료
}

