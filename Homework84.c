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
	fp = fileOpen("C://Users//�ּ���//Desktop//������ ����//Homework84//Homework84//Homework84_pointWord.txt", "rt");
	if (fp == NULL) { return 1; }
	fileRead(fp, pointArray);
	sort(pointArray);
	printf("# ����Ʈ �ܾ ���Ϸκ��� �Է� �޴� ���Դϴ�....\n\n");
	while (1) {
		if (data_cnt == 10 || score == 100) { break; }
		printf("* ����Ʈ �ܾ� : ");
		print(pointArray, point_cnt);
		printf("* ����� �Է� �ܾ� : ");
		print(dataArray, data_cnt + 1);
		inputData(dataArray, data_cnt++);
		score += check(pointArray, dataArray, &point_cnt, data_cnt);
	}
	printf("** ����� ������ %d�� �Դϴ�.\n", score);
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
		printf("�����ձ� �ܾ� �Է�(%dȸ��) : ", data_cnt + 1);
		scanf("%s", temp);
		if (dataArray[data_cnt][fin] == temp[0]) { strcpy(dataArray[data_cnt + 1], temp); break; }
		else { flush(); printf("�߸� �Է��ϼ̽��ϴ�.\n"); }
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