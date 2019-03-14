#include <stdio.h>

FILE *fileOpen(char *filename, char *mode);
void fileRead(FILE *fp, int *dataArray, int dataCnt);
int checkSum(int *dataArray, int dataCnt);

int main(int argc, char *argv)
{
	int testCnt;
	int dataCnt;
	int dataArray[100];
	int i, j, k;
	FILE *fp;
	fp = fileOpen("C://Users//최성률//Desktop//연습용 과제//Homework72//Homework72//Homework72_grading.txt", "rt");
	if (fp == NULL) { return 1; }
	fscanf(fp, "%d", &testCnt);
	for (int i = 0; i < testCnt; i++) {
		fscanf(fp, "%d", &dataCnt);
		fileRead(fp, dataArray, dataCnt);
		printf("문제 수 : %d문항\n", dataCnt);
		printf("채점 결과 : ");
		for (int i = 0; i < dataCnt; i++) {
			printf("%2d", dataArray[i]);
		}
		printf("\n점수 : %d\n\n", checkSum(dataArray, dataCnt));
	}
	return 0;
}

FILE *fileOpen(char *filename, char *mode)
{
	FILE *fp;
	if ((fp = fopen(filename, mode)) == NULL) { printf("File open error!\n"); }
	return fp;
}
void fileRead(FILE *fp, int *dataArray, int dataCnt)
{
	for (int i = 0; i < dataCnt; i++) {
		fscanf(fp, "%d", &dataArray[i]);
	}
}
int checkSum(int *dataArray, int dataCnt)
{
	int sum = 0;
	for (int i = 0; i < dataCnt - 1; i++) {
		if (dataArray[i] && dataArray[i+1]) {
			dataArray[i + 1] = dataArray[i] + 1;
		}
	}
	for (int i = 0; i < dataCnt; i++) {
		sum += dataArray[i];
	}
	return sum;
}