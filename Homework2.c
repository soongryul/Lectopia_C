#include <stdio.h>
int inputInt(char *msg);
void myflush();
void cal(int m);

int main()
{
	int money;
	money = inputInt("�뵷 �Է� : ");
	cal(money);
	return 0;
}

int inputInt(char *msg) {
	int res, a;
	while (1) {
		printf("%s", msg);
		res = scanf("%d", &a);
		if (res == 1) { break; }
		else { printf("�߸� �Է�\n"); myflush(); }
	}
	return a;
}

void myflush() {
	while (getchar() == '\n') {};
	return;
}

void cal(int m) {
	int n;
	printf("50000���� : %d\n", n = m / 50000);
	m -= n * 50000;
	printf("10000���� : %d\n", n = m / 10000);
	m -= n * 10000;
	printf("5000���� : %d\n", n = m / 5000);
	m -= n * 5000;
	printf("1000���� : %d\n", n = m / 1000);
	m -= n * 1000;
	printf("500���� : %d\n", n = m / 500);
	m -= n * 500;
	printf("100���� : %d\n", n = m / 100);
	m -= n * 100;
	printf("50���� : %d\n", n = m / 50);
	m -= n * 50;
	printf("10���� : %d\n", n = m / 10);
	m -= n * 10;
	return;
}