#include <stdio.h>
int inputInt(char *msg);
void myflush();
void print(double m);
int main()
{
	int result;
	double money;
	result = inputInt("���� ��뷮�� �Է��ϼ���(kw) : ");
	money = 660 + result * 88.5;
	money = money * 0.09 + money;
	print(money);
	return 0;
}

int inputInt(char *msg)
{
	int res, a;
	while (1) {
		printf("%s", msg);
		res = scanf("%d", &a);
		if (res == 1) { break; }
		else { myflush(); }
	}
	return a;
}

void myflush()
{
	while (getchar() != 'n') {}
	return;
}

void print(double m)
{
	printf("���� ������� %lf�� �Դϴ�.\n", m);
	return;
}