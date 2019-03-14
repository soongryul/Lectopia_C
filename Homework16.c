#include <stdio.h>
void flush();
int inputInt(char *msg);
int calMoney(int);
void print(int);

int main()
{
	int st_num, money;
	st_num = inputInt("역수를 입력하시오 : ");
	money = calMoney(st_num);
	print(money);

	return 0;
}

void flush()
{
	while (getchar() != '\n') {}
	return;
}

int inputInt(char *msg)
{
	int rt, res;
	while (1) {
		printf(msg);
		res = scanf("%d", &rt);
		if (res == 1 && rt > 0) { break; }
		else { flush(); }
	}
	return rt;
}

int calMoney(int num)
{
	if (num < 1) { return 0; }
	else if (num >= 1 && num <= 5) { return 600; }
	else if (num >= 6 && num <= 10) { return 800; }
	else { return 800 + 100 * ((num - 9) / 2); }
}

void print(int m)
{
	printf("요금 : %d원\n", m);
	return;
}