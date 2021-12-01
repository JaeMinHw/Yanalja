#pragma once
#define A  29 // 가로 길이
#define S  29 // 세로 길이

void map_print()
{
	FILE *fp = fopen("지도.txt", "rt");
	char map[A][S];

	int i, j = 0;

	fread(&map, S*A, 1, fp); //찾아보기 (read쓸지 get쓸지



	for (i = 0; i < S; i++)
	{
		for (j = 0; j < A; j++)
		{
			if (map[i][j] == 49) //1에 대한 아스키코드값
				printf("■");
			else if (map[i][j] == 48) //0에 대한 아스키코드값
				printf("□");
			

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