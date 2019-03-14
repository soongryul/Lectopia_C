#include <stdio.h>

FILE *fileOpen(char *filename, char *mode);
void fileRead(FILE *fp, int *dataArray, int dataCnt);
int checkJolly(int *, int);

int main()
{
	int testCnt;
	int dataCnt;
	int dataArray[100];
	int cnt;
	FILE *fp;
	fp = fileOpen("C://Users//최성률//Desktop//연습용 과제//Homework74//Homework74//Homework74_jolly.txt", "rt");
	if (fp == NULL) { return 1; }
	fscanf(fp, "%d", &testCnt);
	for (int i = 0; i < testCnt; i++) {
		fscanf(fp, "%d", &dataCnt);
		fileRead(fp, dataArray, dataCnt);
		printf("검사한 수열 : ");
		for (int j = 0; j < dataCnt; j++) {
			printf("%d ", dataArray[j]);
		}
		cnt = checkJolly(dataArray, dataCnt);
		if (cnt) {	printf("(Jolly jumper)\n");	}
		else { printf("(Not jolly jumper)\n");	}
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
	for (int i = 0; i<dataCnt; i++) {
		fscanf(fp, "%d", &dataArray[i]);
	}
}
int checkJolly(int *dataArray, int dataCnt)
{
	int chk[100] = { 0, };
	int chkcnt;
	for (int i = 1; i < dataCnt; i++) {
		chk[i-1] = i;
	}
	for (int i = 0, j = 1; i < dataCnt - 1; i++, j++) {
		if (dataArray[i] > dataArray[j]) {
			chkcnt = dataArray[i] - dataArray[j];
			chk[chkcnt - 1] = 0;
		}
		else if (dataArray[i] < dataArray[j]) {
			chkcnt = dataArray[j] - dataArray[i];
			chk[chkcnt - 1] = 0;
		}
	}
	for (int i = 0; i < dataCnt; i++) {
		//printf("chk[%d] = %d\n", i, chk[i]);
		if (chk[i] != 0) { return 0; }
	}
	return 1;
}