#include <stdio.h>
#include <string.h>

void flush();
FILE *fileOpen(char *filename, char *mode);
void fileRead(FILE *fp, char(*pointArray)[20]);
void sort(char(*pointArray)[20]);
void print(char(*ary)[20], int cnt);
void inputData(char(*dataArray)[20], int data_cnt);
int check(char(*pointArray)[20], char(*dataArray)[20], int *point_cnt, int data_cnt);

int main()
{
	FILE *fp;
	char pointArray[5][20];
	char dataArray[11][20] = { "pointer", };
	int score = 0, point_cnt=5, data_cnt = 0;
	fp = fileOpen("C://Users//최성률//Desktop//연습용 과제//Homework84//Homework84//Homework84_pointWord.txt", "rt");
	if (fp == NULL) { return 1; }
	fileRead(fp, pointArray);
	sort(pointArray);
	printf("# 포인트 단어를 파일로부터 입력 받는 중입니다....\n\n");
	while (1) {
		if (data_cnt == 10 || score == 100) { break; }
		printf("* 포인트 단어 : ");
		print(pointArray, point_cnt);
		printf("* 사용자 입력 단어 : ");
		print(dataArray, data_cnt + 1);
		inputData(dataArray, data_cnt++);
		score += check(pointArray, dataArray, &point_cnt, data_cnt);
	}
	printf("** 당신의 점수는 %d점 입니다.\n", score);
	fclose(fp);
	return 0;
}

void flush()
{
	while (getchar() != '\n');
}
FILE *fileOpen(char *filename, char *mode)
{
	FILE *fp;
	if ((fp = fopen(filename, mode)) == NULL) { printf("File open error!\n"); }
	return fp;
}
void fileRead(FILE *fp, char (*pointArray)[20])
{
	for (int i = 0; i < 5; i++) {
		fscanf(fp, "%s", pointArray[i]);
	}
}
void sort(char(*pointArray)[20])
{
	char temp[20];
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (strcmp(pointArray[i], pointArray[j]) == 1) {
				strcpy(temp, pointArray[i]);
				strcpy(pointArray[i], pointArray[j]);
				strcpy(pointArray[j], temp);
			}
		}
	}
}
void print(char(*ary)[20], int cnt)
{
	for (int i = 0; i < cnt; i++) {
		printf("%s / ", ary[i]);
	}
	printf("\n");
}
void inputData(char(*dataArray)[20], int data_cnt)
{
	char temp[20];
	int fin = strlen(dataArray[data_cnt]) - 1;
	while (1) {
		printf("끝말잇기 단어 입력(%d회차) : ", data_cnt + 1);
		scanf("%s", temp);
		if (dataArray[data_cnt][fin] == temp[0]) { strcpy(dataArray[data_cnt + 1], temp); break; }
		else { flush(); printf("잘못 입력하셨습니다.\n"); }
	}
	printf("\n");
}
int check(char(*pointArray)[20], char(*dataArray)[20], int *point_cnt, int data_cnt)
{
	for (int i = 0; i < *point_cnt; i++) {
		if (strcmp(pointArray[i], dataArray[data_cnt]) == 0) {
			(*point_cnt)--;
			for (int j = i; j < *point_cnt; j++) {
				strcpy(pointArray[j], pointArray[j + 1]);
			}
			pointArray[*point_cnt][0] = '\0';
			return 20;
		}
	}
	return 0;
}