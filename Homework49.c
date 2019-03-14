#include <stdio.h>

FILE *fileOpen(char *filename, char *mode);
int fileRead(FILE *fp, int *dataArray);

int main(int argc, char *argv)
{
	int testCnt;
	int dataCnt;
	int cnt;
	int dataArray[100];
	int i, j, k;
	FILE *fp;
	fp = fileOpen("C://Users//�ּ���//Desktop//������ ����//Homework49//Homework49//Homework49_number_list.txt", "rt");
	if (fp == NULL) { return 1; }

	fscanf(fp, "%d", &testCnt);
	for (i = 0; i < testCnt; i++) {
		dataCnt = fileRead(fp, dataArray);
		cnt = 0;
		printf("# ���� : ");
		for (j = 0; j < dataCnt; j++) {
			printf("%-3d", dataArray[j]);
			for (k = 0; k < dataCnt; k++) {
				if (dataArray[j] * 2 == dataArray[k]) {
					cnt++;
				}
			}
		}
		printf("\n2�� ���� �����ϴ� ������ ������ %d�� �Դϴ�.\n\n", cnt);
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