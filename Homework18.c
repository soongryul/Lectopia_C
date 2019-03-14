#include <stdio.h>
void flush();
int inputInt(char *);
void print(int, int);

int main()
{
	int age, num;
	age = inputInt("입장객의 나이를 입력하시오 : ");
	num = inputInt("입장객의 수를 입력하시오 : ");
	print(age, num);

	return 0;
}

void flush()
{
	while (getchar() != '\n');
	return;
}

int inputInt(char *msg)
{
	int rt, res;
	while (1) {
		printf(msg);
		res = scanf("%d", &rt);
		if (res == 1 && rt > 0) { flush(); break; }
		else { flush(); }
	}
	return rt;
}
void print(int age, int num)
{
	int temp, money;
	if (age < 7) { money = 500 * num; }
	else if (age >= 8 && age <= 13) { money = 700 * num; }
	else if (age >= 14 && age <= 19) { money = 1000 * num; }
	else if (age >= 20 && age <= 55) { money = 1500 * num; }
	else if (age >= 56) { money = 500 * num; }
	if (num >= 5) { temp = (int)(money*0.1); }
	else { temp = 0; }
	printf("\n입장료 => %d원\n할인금액 => %d원\n결제금액 => %d원\n", money, temp, money - temp);

	return;
}