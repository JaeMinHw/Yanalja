#pragma once
#define A  29 // ���� ����
#define S  29 // ���� ����

void map_print()
{
	FILE *fp = fopen("����.txt", "rt");
	char map[A][S];

	int i, j = 0;

	fread(&map, S*A, 1, fp); //ã�ƺ��� (read���� get����



	for (i = 0; i < S; i++)
	{
		for (j = 0; j < A; j++)
		{
			if (map[i][j] == 49) //1�� ���� �ƽ�Ű�ڵ尪
				printf("��");
			else if (map[i][j] == 48) //0�� ���� �ƽ�Ű�ڵ尪
				printf("��");
			

			if (j != 0)
			 {
				if (j % (A-1) == 0)
				{
					printf("\n");
					
				}
			}
		}
	}

	fclose(fp);

	printf("\n");
}