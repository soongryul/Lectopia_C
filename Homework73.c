#include <stdio.h>

FILE *fileOpen(char *filename, char *mode);
void fileRead(FILE *fp, int *dataArray);
int check(int *dataArray);

int main()
{
	int testCnt;
	int dataCnt;
	int dataArray[100];
	int cnt;
	FILE *fp;
	fp = fileOpen("C://Users//최성률//Desktop//연습용 과제//Homework73//Homework73//Homework73_overlap.txt", "rt");
	if (fp == NULL) { return 1; }

	fscanf(fp, "%d", &testCnt);
	for (int i = 0; i < testCnt; i++) {
		fileRead(fp, dataArray);
		printf("검사한 숫자 : ");
		for (int i = 0; i < 10; i++) {
			printf("%2d", dataArray[i]);
		}
		printf("\n한 번만 사용된 숫자 : ");
		cnt = check(dataArray);
		for (int i = 0; i < cnt; i++) {
			printf("%2d", dataArray[i]);
		}
		printf("\n\n");
	}
	return 0;
}

FILE *fileOpen(char *filename, char *mode)
{
	FILE *fp;
	if ((fp = fopen(filename, mode)) == NULL) { printf("File open error!\n"); }
	return fp;
}
void fileRead(FILE *fp, int *dataArray)
{
	for(int i=0; i<10; i++) {
		fscanf(fp, "%d", &dataArray[i]);
	}
}
int check(int *dataArray)
{
	int cnt = 0, num = 0;
	int temp[10] = { 0, };
	for (int i = 0; i < 10; i++) {
		for (int j = 9; j >= 0; j--) {
			if (i != j && dataArray[i] != dataArray[j]) { cnt++; }
		}
		if (cnt == 9) { temp[num] = dataArray[i]; num++; }
		cnt = 0;
	}
	for (int i = 0; i < 10; i++) {
		dataArray[i] = temp[i];
	}
	return num;
}