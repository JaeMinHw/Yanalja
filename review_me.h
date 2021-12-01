#pragma once

void menu();
void where_review();
void review_con();
void review_add();
void review_de();
// 리뷰 함수						UI 박스 만들기
void review_con()
{

	char ans3[2];
	printf("1. 리뷰 추가 \n");
	printf("2. 리뷰 삭제 \n");
	while (1)
	{
	
		
		scanf("%s", ans3);
		if (strcmp(ans3,"1")==0)
		{
			system("cls");
			printf("리뷰 추가를 선택하셨습니다.\n");
			review_add(); 	// 추가 함수 호출
		}
		else if (strcmp(ans3, "2") == 0)
		{
			system("cls");
			printf("리뷰 삭제를 선택하셨습니다.\n");
			review_de();	// 삭제 함수 호출
		}
		else if (strcmp(ans3, "q") == 0)
		{
			system("cls");
			break;
		}
		else
		{
			printf("%s 잘못된 입력입니다.\n", ans3);
			printf("1,2 또는 뒤로 가시려면 q를 입력해주세요\n");
		}
		
	}
	menu();
	
}




