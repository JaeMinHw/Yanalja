#include <stdio.h>



int main(void)
{
	FILE *stream;
	int i;
	char *a = "abc";
	char fl[100] = "\0";



	for (i = 0; i < 5; i++) {

		sprintf(fl, "C:\\Users\\Ȳ���\\Desktop\\2�г� 2�б� â��������Ʈ\\2�г� 2�б� â��������Ʈ\\��������\\file000%d.txt", i);



		if ((stream = fopen(fl, "wt")) == NULL) {
			fprintf(stderr, "Cannot open output file.\n");
			return 1;
		}



		fwrite(a, sizeof(a), 1, stream);



		fclose(stream);
	}

	return 0;

}

//���� ���Ͽ��� place_name�� ������ ���������� ������ ���� ����
for (i = 0; i < NUM; i++)
{
	sprintf(fl, "C:\\Users\\Ȳ���\\Desktop\\2�г� 2�б� â��������Ʈ\\2�г� 2�б� â��������Ʈ\\��������\\%s.txt", temp[i].place_name);

	if ((fp[i] = fopen(fl, "at")) == NULL) {
		fprintf(stderr, "Cannot open output file.\n");
		return 1;
	}
	fclose(fp[i]);
}