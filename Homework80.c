#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>

typedef struct _student {
	char name[20];
	int rank, sum;
	double ave;
	int kor, eng, mat;
}Student;

Student *myAlloc(int stu_num);
void myDelete(Student *sp);
int inputNum(char *msg);
int inputScore(char *msg);
void inputName(Student *p);
void input(Student *p);
int inputMenuNum(char *msg);
void menuPrint(Student *p);
int compare(Student *p, int stu_num);
void printScore(Student *p, int stu_num);
void sortStudent(Student *p, int stu_num);

int main()
{
	Student *sp;
	int menu_num = 1, num;
	int stu_num = inputNum("�л� �� : ");
	sp = myAlloc(stu_num);
	for (int i = 0; i < stu_num; i++) {
		printf("[%d ��° �л�(%d �� �� ����)]\n", i + 1, stu_num - i - 1);
		inputName(&sp[i]);
		input(&sp[i]);
	}
	while (1) {
		menuPrint(sp);
		menu_num = inputMenuNum("�Է� : ");
		printf("========================================================================\n");
		if (menu_num == 3) { break; }
		switch (menu_num) {
		case 1:
			while (1) {
				num = compare(sp, stu_num);
				if (num == -2) { break; }
				else if (num == -1) { printf("�׷� ��� �����ϴ�\n"); }
				else { input(&sp[num]); }
			}
			break;
		case 2: printScore(sp, stu_num); break;
		}
	}
	myDelete(sp);
	return 0;
}

Student *myAlloc(int stu_num)
{
	Student *sp;
	sp = (Student *)malloc(sizeof(Student) * stu_num);
	assert(sp != NULL);
	return sp;
}
void myDelete(Student *p)
{
	free(p);
}
int inputNum(char *msg)
{
	int rt;
	while (1) {
		printf(msg);
		scanf("%d", &rt);
		if (getchar() == '\n' && rt > 0) { break; }
		else { fflush(stdin); printf("#�� �Է�\n"); }
	}
	return rt;
}
int inputScore(char *msg)
{
	int rt;
	while (1) {
		printf(msg);
		scanf("%d", &rt);
		if (getchar() == '\n' && rt >= 0 && rt <= 100) { break; }
		else { fflush(stdin); printf("#�� �Է�\n"); }
	}
	return rt;
}
void inputName(Student *p)
{
	char str[20];
	printf("�л� �̸� : ");
	fgets(str, sizeof(str), stdin);
	str[strlen(str) - 1] = '\0';
	strcpy(p->name, str);
}
void input(Student *p)
{
	p->kor = inputScore("���� ���� : ");
	p->eng = inputScore("���� ���� : ");
	p->mat = inputScore("���� ���� : ");
	p->sum = p->kor + p->eng + p->mat;
	p->ave = (double)(p->sum) / 3;
	printf("\n");
}
void menuPrint(Student *p)
{
	printf("==================================M*E*N*U===============================\n");
	printf("\t1:���� ���� �޴�\t2:��ü ���� ���\t3:����\n");
}
int inputMenuNum(char *msg)
{
	int rt;
	while (1) {
		printf(msg);
		scanf("%d", &rt);
		if (getchar() == '\n' && rt >= 1 && rt <= 3) { break; }
		else { fflush(stdin); printf("#�� �Է�\n"); }
	}
	return rt;
}
int compare(Student *p, int stu_num)
{
	char str[20];
	int i;
	printf("������ �л� �̸��� �Է��ϼ���(���� �޴� ����[quit]) : ");
	fgets(str, sizeof(str), stdin);
	str[strlen(str) - 1] = '\0';
	if (strcmp(str, "quit") == 0) { return -2; }
	for (i = 0; i < stu_num; i++) {
		if (strcmp(p[i].name, str) == 0) { return i; }
	}
	return -1;
}
void printScore(Student *p, int stu_num)
{
	sortStudent(p, stu_num);
	p[0].rank = 1;
	for (int i = 1; i < stu_num; i++) {
		if (p[i].sum != p[i - 1].sum) { p[i].rank = i + 1; }
		else { p[i].rank = p[i - 1].rank; }
	}
	printf("==================================��ü ����=============================\n");
	printf("\t[ ����\t����\t����\t����\t����\t����\t��� ]\n");
	for (int i = 0; i < stu_num; i++) {
		printf("\t  %d\t%s\t%d\t%d\t%d\t%d\t%.2lf\n", p[i].rank, p[i].name, p[i].kor, p[i].eng, p[i].mat, p[i].sum, p[i].ave);
	}
	printf("\n");
}
void sortStudent(Student *p, int stu_num)
{
	Student temp;
	for (int i = 0; i < stu_num - 1; i++) {
		for (int j = i + 1; j < stu_num; j++) {
			if (p[i].sum < p[j].sum) {
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}