#include <stdio.h>
#include <malloc.h>
#include <assert.h>

FILE *fileOpen(char *filename, char *mode);
int *myAlloc(int stu_num);
void myDelete(int *stu);
void print(FILE *fp, int stu_num, int *stu);

int main()
{
	int testCnt, stu_num;
	int *stu;
	FILE *fp;
	fp = fileOpen("C://Users//최성률//Desktop//연습용 과제//Homework78//Homework78//Homework78_line.txt", "rt");
	if (fp == NULL) { return 1; }
	fscanf(fp, "%d", &testCnt);
	for (int i = 1; i <= testCnt; i++) {
		fscanf(fp, "%d", &stu_num);
		stu = myAlloc(stu_num);
		print(fp, stu_num, stu);
		printf("%2d반 학생의 순서 출력 : ", i);
		for (int j = 0; j < stu_num; j++) {
			printf("%2d", stu[j]);
		}
		printf("\n");
		myDelete(stu);
	}
	return 0;
}

FILE *fileOpen(char *filename, char *mode)
{
	FILE *fp;
	if ((fp = fopen(filename, mode)) == NULL) { printf("File open error!\n"); }
	return fp;
}
int *myAlloc(int stu_num)
{
	int *p;
	p = (int *)malloc(sizeof(int)*stu_num);
	assert(p != NULL);
	return p;
}
void myDelete(int *stu)
{
	free(stu);
}
void print(FILE *fp, int stu_num, int *stu)
{
	int num, temp;
	for (int i = 0; i < stu_num; i++) {
		stu[i] = i + 1;
	}
	for (int i = 0; i < stu_num; i++) {
		fscanf(fp, "%d", &num);
		if (num > 0) {
			for (int j = 0; j < num; j++) {
				temp = stu[i - j];
				stu[i - j] = stu[i - j - 1];
				stu[i - j - 1] = temp;
			}
		}
	}
}