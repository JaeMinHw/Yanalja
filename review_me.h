#pragma once

void menu();
void where_review();
void review_con();
void review_add();
void review_de();
// ���� �Լ�						UI �ڽ� �����
void review_con()
{

	char ans3[2];
	printf("1. ���� �߰� \n");
	printf("2. ���� ���� \n");
	while (1)
	{
	
		
		scanf("%s", ans3);
		if (strcmp(ans3,"1")==0)
		{
			system("cls");
			printf("���� �߰��� �����ϼ̽��ϴ�.\n");
			review_add(); 	// �߰� �Լ� ȣ��
		}
		else if (strcmp(ans3, "2") == 0)
		{
			system("cls");
			printf("���� ������ �����ϼ̽��ϴ�.\n");
			review_de();	// ���� �Լ� ȣ��
		}
		else if (strcmp(ans3, "q") == 0)
		{
			system("cls");
			break;
		}
		else
		{
			printf("%s �߸��� �Է��Դϴ�.\n", ans3);
			printf("1,2 �Ǵ� �ڷ� ���÷��� q�� �Է����ּ���\n");
		}
		
	}
	menu();
	
}




