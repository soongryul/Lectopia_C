#include <stdio.h>
#include <string.h>

typedef struct _person {
	char name[15];
	int dataArray[10];
	int score;
}Person;

FILE *fileOpen(char *filename, char *mode);
void fileRead(FILE *fp, Person *student);
void check(Person *student, int *checkArray);

int main()
{
	FILE *fp;
	Person student[3];
	int checkArray[10] = { 1, 2, 3, 3, 4, 2, 3, 4, 1, 4 };
	fp = fileOpen("C://Users//최성률//Desktop//연습용 과제//Homework85//Homework85//Homework85_answer.txt", "rt");
	if (fp == NULL) { return 1; }
	fileRead(fp, student);
	check(student, checkArray);
	printf("[ 이  름 ]\t[ 점 수 ]\t[ 1 2 3 4 5 6 7 8 9 10 ]\n");
	for (int i = 0; i < 3; i++) {
		printf("%d. %s\t", i + 1, student[i].name);
		printf("  (%3d)\t\t ", student[i].score);
		for (int j = 0; j < 10; j++) {
			if (student[i].dataArray[j] == 10) { printf("%2c", 'O'); }
			else { printf("%2c", 'X'); }
		}
		printf("\n");
	}
	fclose(fp);
	fp = fileOpen("C://Users//최성률//Desktop//연습용 과제//Homework85//Homework85//Homework85_res.txt", "w+t");
	if (fp == NULL) { return 1; }
	for (int i = 0; i < 3; i++) {
		fprintf(fp, "%s\n", student[i].name);
		for (int j = 0; j < 10; j++) {
			if (student[i].dataArray[j] == 10) { fprintf(fp, "%2c", 'O'); }
			else { fprintf(fp, "%2c", 'X'); }
		}
		fprintf(fp, "\t%d\n", student[i].score);
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
void fileRead(FILE *fp, Person *student)
{
	for (int i = 0; i < 3; i++) {
		fgets(student[i].name, sizeof(student[i].name), fp);
		student[i].name[strlen(student[i].name) - 1] = '\0';
		for (int j = 0; j < 10; j++) {
			fscanf(fp, "%d", &student[i].dataArray[j]);
		}
		fscanf(fp, "%c");
	}
}
void check(Person *student, int *checkArray)
{
	for (int i = 0; i < 3; i++) {
		student[i].score = 0;
		for (int j = 0; j < 10; j++) {
			if (student[i].dataArray[j] == checkArray[j]) {
				student[i].dataArray[j] = 10;
				student[i].score += 10;
			}
			else {
				student[i].dataArray[j] = 0;
			}
		}
	}
}