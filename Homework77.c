#include <stdio.h>

FILE *fileOpen(char *filename, char *mode);
void fileRead(FILE *, int *);
void print(int a, int b, int c, int *car1, int *car2, int *car3);
void sort(int *);

int main()
{
	int testCnt;
	int a, b, c;
	int car1[2];
	int car2[2];
	int car3[2];
	FILE *fp;
	fp = fileOpen("C://Users//최성률//Desktop//연습용 과제//Homework77//Homework77//Homework77_parking_info.txt", "rt");
	if (fp == NULL) { return 1; }
	fscanf(fp, "%d", &testCnt);
	for (int i = 0; i < testCnt; i++) {
		fscanf(fp, "%d", &a);
		fscanf(fp, "%d", &b);
		fscanf(fp, "%d", &c);
		fileRead(fp, car1);
		fileRead(fp, car2);
		fileRead(fp, car3);
		print(a, b, c, car1, car2, car3);
	}
	return 0;
}

FILE *fileOpen(char *filename, char *mode)
{
	FILE *fp;
	if ((fp = fopen(filename, mode)) == NULL) { printf("File open error!\n"); }
	return fp;
}
void fileRead(FILE *fp, int *car)
{
	for (int i = 0; i < 2; i++) {
		fscanf(fp, "%d", &car[i]);
	}
}
void print(int a, int b, int c, int *car1, int *car2, int *car3)
{
	int temp[100] = { 0, };
	int range[6];
	int sum = 0;
	range[0] = car1[0];
	range[1] = car1[1];
	range[2] = car2[0];
	range[3] = car2[1];
	range[4] = car3[0];
	range[5] = car3[1];
	sort(range);
	for (int i = car1[0]; i < car1[1]; i++) {
		temp[i] += 1;
	}
	for (int i = car2[0]; i < car2[1]; i++) {
		temp[i] += 1;
	}
	for (int i = car3[0]; i < car3[1]; i++) {
		temp[i] += 1;
	}
	for (int i = range[0]; i < range[5]; i++) {
		switch (temp[i]) {
		case 1: sum += a * temp[i]; break;
		case 2: sum += b * temp[i]; break;
		case 3: sum += c * temp[i]; break;
		}
	}
	printf("A 요금 : %d / B 요금 : %d / C 요금 : %d\n", a, b, c);
	printf("총 주차 요금 : %d원\n\n", sum);
}
void sort(int *temp)
{
	int tp;
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 6; j++) {
			if (temp[i] > temp[j]) {
				tp = temp[i];
				temp[i] = temp[j];
				temp[j] = tp;
			}
		}
	}
}