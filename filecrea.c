#include <stdio.h>



int main(void)
{
	FILE *stream;
	int i;
	char *a = "abc";
	char fl[100] = "\0";



	for (i = 0; i < 5; i++) {

		sprintf(fl, "C:\\Users\\황재민\\Desktop\\2학년 2학기 창업프로젝트\\2학년 2학기 창업프로젝트\\지역리뷰\\file000%d.txt", i);



		if ((stream = fopen(fl, "wt")) == NULL) {
			fprintf(stderr, "Cannot open output file.\n");
			return 1;
		}



		fwrite(a, sizeof(a), 1, stream);



		fclose(stream);
	}

	return 0;

}

//지역 파일에는 place_name이 있지만 리뷰파일이 없으면 파일 생성
for (i = 0; i < NUM; i++)
{
	sprintf(fl, "C:\\Users\\황재민\\Desktop\\2학년 2학기 창업프로젝트\\2학년 2학기 창업프로젝트\\지역리뷰\\%s.txt", temp[i].place_name);

	if ((fp[i] = fopen(fl, "at")) == NULL) {
		fprintf(stderr, "Cannot open output file.\n");
		return 1;
	}
	fclose(fp[i]);
}