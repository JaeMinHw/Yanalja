/* 창업 프로젝트 야날자
201811780
황재민
2021년 월 일*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h> 
#include <conio.h> //getch 함수를 사용하기 위해
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



struct area {
	int num; // 장소 번호
	char name[6]; //UA형식
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
		//입력 받으면 화면 지우고 해당 작업 실행

		if (ans == 1)
		{
			system("cls"); // 화면 지우기
			printf("1. 전체 가능한 구역을 선택하셨습니다.\n");
			menu1_addr();
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
			review_con();
		}
		else if (ans == 4)
		{
			system("cls"); // 화면 지우기
			printf("저장 후 종료를 선택하셨습니다.\n");
			break;
		}
		else if (ans == 1234)
		{
			system("cls");
			printf("파일 업데이트를 선택하셨습니다.");
			updata_file();
		}
		else
		{
			system("cls");
			setColor(12);
			printf("\n잘못된 입력입니다. 번호를 확인해주세요\n");
			setColor(15);
			menu();
		}
	
	} 

	printf("저장되었습니다.");
	Sleep(1000);
	exit(1);
	// 1초 기다리고 종료
	

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

	gotoxy(11, y++);
	printf("┌────────────────────┐");
	gotoxy(11, y++);
	printf("│    파일 업데이트   │");
	gotoxy(11, y++);
	printf("└────────────────────┘");

	gotoxy(10, 25);
	setColor(12);
	printf("허가 구역 외 비행은 벌금 및");

	gotoxy(8, 26);
	printf("과태료 처분을 받을 수 있습니다.");
	gotoxy(11, 23);
	setColor(15);
}


void sear_name(int i)
{
	FILE *fp;
	char tmp[100];
	char fl[100];
	sprintf(fl, "C:\\Users\\황재민\\Desktop\\2학년 2학기 창업프로젝트\\2학년 2학기 창업프로젝트\\지역리뷰\\%s.txt", temp[i].place_name);

	if ((fp = fopen(fl, "r+t")) == NULL)
	{
		printf("%s 파일 오픈 에러", temp[i].place_name);
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



// 지역검색 함수
void sear_ch()
{
	//%s값을 입력받아 어느 곳인지 구조체 area에서 다 확인한 후, 만약 구조체 안에 있다면 place_name을 가져와 place_name 파일을 연다. 그 후 주소와 리뷰를 다 출력한다. 
	FILE *fp;

	char are[10];
	int i = 0;
	int save = -1;

	if ((fp = fopen("where_area.txt", "r+t")) == NULL)
	{
		printf("파일 오픈 에러");
		exit(1);
	}

	for (i = 0; i < NUM; i++)
	{
		fscanf(fp, "%d %s %s %s %s %s %s", &temp[i].num, &temp[i].name, &temp[i].place_name, &temp[i].place_do, &temp[i].place_si, &temp[i].place_gu, &temp[i].place_dong);

	}




	while (1)
	{

		printf("어디 지역에 계신가요?");
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
				printf("%s에 관한 장소입니다.\n", are);
				printf("%2d. %6s :  %s %s %s %s \n\n\n", temp[i].num, temp[i].place_name, temp[i].place_do, temp[i].place_si, temp[i].place_gu, temp[i].place_dong);
				sear_name(i);

			}
			else
			{
				if (strcmp(are, temp[i].place_do) == 0)
				{
					system("cls");
					save = i;
					printf("%s에 관한 장소입니다.\n", are);
					printf("%2d. %6s :  %s %s %s %s \n\n\n", temp[i].num, temp[i].place_name, temp[i].place_do, temp[i].place_si, temp[i].place_gu, temp[i].place_dong);
					sear_name(i);
				}
				else
				{
					if (strcmp(are, temp[i].place_si) == 0)
					{
						system("cls");
						save = i;
						printf("%s에 관한 장소입니다.\n", are);
						printf("%2d. %6s :  %s %s %s %s \n\n\n", temp[i].num, temp[i].place_name, temp[i].place_do, temp[i].place_si, temp[i].place_gu, temp[i].place_dong);
						sear_name(i);
					}
					else
					{
						if (strcmp(are, temp[i].place_gu) == 0)
						{
							system("cls");
							save = i;
							printf("%s에 관한 장소입니다.\n", are);
							printf("%2d. %6s :  %s %s %s %s \n\n\n", temp[i].num, temp[i].place_name, temp[i].place_do, temp[i].place_si, temp[i].place_gu, temp[i].place_dong);
							sear_name(i);
						}
						else
						{
							if (strcmp(are, temp[i].place_dong) == 0)
							{
								system("cls");
								save = i;
								printf("%s에 관한 장소입니다.\n", are);
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
			printf("%s에서 날릴 수 있는 구역은 없습니다.\n", are);
			Sleep(300);

		}
		save = -1;


	}
	fclose(fp);

}

// 주소와 리뷰 출력 함수
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
		printf("파일 오픈 에러");
		exit(1);
	}

	// 주소는 다 출력하되 리뷰는 있는 것만 출력 0,0이런거 없애기




	// place_name 파일 불러오기


	for (i = 0; i < NUM; i++)
	{
		printf("┌─────────────────────────────────────────────────────────────────┐\n");
		fscanf(fpa, "%d %s %s %s %s %s %s", &temp[i].num, &temp[i].name, &temp[i].place_name, &temp[i].place_do, &temp[i].place_si, &temp[i].place_gu, &temp[i].place_dong);
		sprintf(fl, "C:\\Users\\황재민\\Desktop\\2학년 2학기 창업프로젝트\\2학년 2학기 창업프로젝트\\지역리뷰\\%s.txt", temp[i].place_name);
		printf("  %2d. %7s :  %s %s %s %s \n", temp[i].num, temp[i].place_name, temp[i].place_do, temp[i].place_si, temp[i].place_gu, temp[i].place_dong);
		printf("└─────────────────────────────────────────────────────────────────┘\n");

		
		if ((fp[i] = fopen(fl, "r+t")) == NULL)
		{
			printf("%s 파일 오픈 에러", temp[i].place_name);
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


	where_review(); // 주소 리뷰 출력
	// 박스 만들기
	printf("┌──────────────────────────────────────────────┐\n");
	printf("│ 지역 검색으로 이동하시려면 2를 입력해주세요. │ \n");
	printf("└──────────────────────────────────────────────┘\n");
	char a;
	printf("뒤로 가시려면 q를 눌러주세요\n");
	//뒤로가기 q
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
			printf("2. 지역 검색을 선택하셨습니다.\n");
			sear_ch();
			break;
		}

		else
		{
			setColor(12);
			printf("잘못입력하셨습니다.\n");
			setColor(15);
		}


	}


}


//파일 생성
void updata_file()
{
	FILE *fpa;

	FILE *fp[NUM];
	char fl[100];
	int i;

	if ((fpa = fopen("where_area.txt", "r+t")) == NULL)
	{
		printf("파일 오픈 에러");
		exit(1);
	}

	for (i = 0; i<NUM; i++) // 주소는 다 출력하되 리뷰는 있는 것만 출력 0,0이런거 없애기
	{
		fscanf(fpa, "%d %s %s %s %s %s %s", &temp[i].num, &temp[i].name, &temp[i].place_name, &temp[i].place_do, &temp[i].place_si, &temp[i].place_gu, &temp[i].place_dong);

	}

	//지역 파일에는 place_name이 있지만 리뷰파일이 없으면 파일 생성
	for (i = 0; i < NUM; i++)
	{
		sprintf(fl, "C:\\Users\\황재민\\Desktop\\2학년 2학기 창업프로젝트\\2학년 2학기 창업프로젝트\\지역리뷰\\%s.txt", temp[i].place_name);

		if ((fp[i] = fopen(fl, "r")) == NULL) {
			fprintf(stderr, "Cannot open output file.\n");

		}
		fclose(fp[i]);
	}
	Sleep(2000);
	menu();
}


//리뷰 추가
void review_add()
{
	FILE *fpa3;
	char fl[100];
	char name3[10];
	// 리뷰 목록 보여주기
	where_review();
	int i = 0;
	int save;

	// 어떤 리뷰 추가할건지
	printf("어느 장소의 리뷰를 추가하시겠습니까? \n");
	printf("뒤로 가기는 q입니다.\n");

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
						sprintf(fl, "C:\\Users\\황재민\\Desktop\\2학년 2학기 창업프로젝트\\2학년 2학기 창업프로젝트\\지역리뷰\\%s.txt", temp[i].place_name);

						if ((fpa3 = fopen(fl, "r")) == NULL)
						{
							fprintf(stderr, "Cannot open output file.\n");

							break;
						}
						else
						{
							fpa3 = freopen(fl, "a", fpa3);
							printf("%s : 시간을 입력해주세요(ex 21.11.16) \n",temp[i].place_name);
							rewind(stdin);
							gets(temp2[i].time);
							if (strcmp(temp2[i].time, "end") == 0)
								break;
							printf("별점을 입력해주세요 : ");
							rewind(stdin);
							scanf("%s", temp2[i].star);

							printf("간단 리뷰(20자 이내) : ");
							rewind(stdin);
							gets(temp2[i].short_review);

							printf("상세 리뷰(100자 이내) : ");
							gets(temp2[i].long_review);

							fprintf(fpa3, "\n%s", temp2[i].time); // 줄바꿈이 안되면 따로 받아서 \n도 fprintf해주기
							fprintf(fpa3, "\n%s", temp2[i].star);
							fprintf(fpa3, "\n%s", temp2[i].short_review);
							fprintf(fpa3, "\n%s\n", temp2[i].long_review);

							printf("추가되었습니다.");
							fclose(fpa3);
							printf("더 추가하시려면 입력해주세요");
							break;
						}
						break;
					}
				
				
				}
				
				if (save == 0)
				{
					printf("원하시는 장소는 존재하지 않습니다. 다시한번 확인후 입력해주세요\n");
					break;
				}
				system("cls");
				where_review();
				printf("어느 장소의 리뷰를 추가하시겠습니까? \n");
				printf("뒤로 가기는 q입니다.\n");
				break;
				
		
			}
		}

	}


	printf("1. 리뷰 추가 \n");
	printf("2. 리뷰 삭제 \n");
}



// 리뷰 삭제
void review_de()
{
	char name4[10];
	int i;
	where_review();

	printf("어느 장소의 리뷰를 삭제하시겠습니까? \n");
	printf("뒤로 가기는 q입니다.\n");
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
					//  그 리뷰들을 구조체에 넣고 하나 삭제하기

				}
			}
		}
	}
}
