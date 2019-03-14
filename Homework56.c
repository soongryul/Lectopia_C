#include <stdio.h>

FILE *fileOpen(char *filename, char *mode);
int fileRead(FILE *fp, int *dataArray);
void sort(int datacnt, int *dataArray);
void print(int datacnt, int *dataArray);

int main(int argc, char *argv)
{
	int testCnt;
	int dataCnt;
	int dataArray[100];
	int i, j, k;
	FILE *fp;
	fp = fileOpen("C://Users//최성률//Desktop//연습용 과제//Homework56//Homework56//Homework56_sortData.txt", "rt");
	if (fp == NULL) { return 1; }

	fscanf(fp, "%d", &testCnt);
	for (i = 0; i < testCnt; i++) {
		dataCnt = fileRead(fp, dataArray);
		printf("# 소트 전 데이터 : ");
		print(dataCnt, dataArray);
		sort(dataCnt, dataArray);
		printf("# 소트 후 데이터 : ");
		print(dataCnt, dataArray);
		printf("\n");
	}

	fclose(fp);
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
void sort(int dataCnt, int *dataArray)
{
	int temp;
	for (int i = 0; i < dataCnt; i++) {
		for (int j = i + 1; j < dataCnt; j++) {
			if (dataArray[i] > dataArray[j]) { 
				temp = dataArray[i];
				dataArray[i] = dataArray[j];
				dataArray[j] = temp;
			}
		}
	}
}
void print(int dataCnt, int *dataArray)
{
	for (int i = 0; i < dataCnt; i++) {
		printf("%-3d", dataArray[i]);
	}
	printf("\n");
}