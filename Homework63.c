#include <stdio.h>

FILE *fileOpen(char *filename, char *mode);
int fileRead(FILE *fp, int *dataArray);
void print_Histogram(int *dataArray, int dataCnt);

int main(int argc, char *argv)
{
	int testCnt;
	int dataCnt;
	int dataArray[30];
	int i, j, k;
	FILE *fp;
	fp = fileOpen("C://Users//최성률//Desktop//연습용 과제//Homework63//Homework63//Homework63_histogram.txt", "rt");
	if (fp == NULL) { return 1; }
	fscanf(fp, "%d", &testCnt);

	for (i = 0; i < testCnt; i++) {
		dataCnt = fileRead(fp, dataArray);
		print_Histogram(dataArray, dataCnt);
	}

	return 0;
}

FILE *fileOpen(char *filename, char *mode)
{
	FILE *fp;
	if ((fp = fopen(filename, mode)) == NULL) { printf("File open error!\n"); }
	return fp;
}
int fileRead(FILE *fp, int *dataArray)
{
	int dataCnt = 0;
	while (1) {
		fscanf(fp, "%d", &dataArray[dataCnt]);
		if (dataArray[dataCnt] == 0) { break; }
		dataCnt++;
	}
	return dataCnt;
}
void print_Histogram(int *dataArray, int dataCnt)
{
	int max = 0;
	for (int i = 0; i < dataCnt; i++) {
		if (dataArray[i] > max) { max = dataArray[i]; }
	}
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < dataCnt; j++) {
			if (dataArray[j] >= max - i) { printf(" *"); }
			else { printf("  "); }
		}
		printf("\n");
	}
	for (int i = 0; i < dataCnt; i++) {
		printf("%2d", dataArray[i]);
	}
	printf("\n");
	printf("-------------------------------------------------------------------\n\n\n");
}