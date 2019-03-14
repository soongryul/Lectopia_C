#include <stdio.h>

void flush();
int inputCode(char *msg);
int inputInt(char *msg);
int Cal(int ton, int code);
void print(int cost, int ton, int code);

int main()
{
	int code, ton, cost;
	code = inputCode("* 사용자 코드를 입력하시오(1:가정용/ 2:상업용/ 3:공업용) : ");
	ton = inputInt("* 사용량을 입력하시오(ton단위) : ");
	cost = Cal(ton, code);
	printf("\n");
	print(cost, ton, code);
	return 0;
}

void flush()
{
	while (getchar() != '\n');
	return;
}

int inputCode(char *msg)
{
	int rt, res;
	while (1) {
		printf(msg);
		res = scanf("%d", &rt);
		if (res == 1 && rt >= 1 && rt <= 3) { flush(); break; }
		else { flush(); printf("재 입력\n"); }
	}
	return rt;
}

int inputInt(char *msg)
{
	int rt, res;
	while (1) {
		printf(msg);
		res = scanf("%d", &rt);
		if (res == 1 && rt > 0) { flush(); break; }
		else { flush(); printf("재 입력\n"); }
	}
	return rt;
}

int Cal(int ton, int code)
{
	switch (code) {
	case 1: return ton * 50;
	case 2: return ton * 45;
	case 3: return ton * 30;
	}
}

void print(int cost, int ton, int code)
{
	switch (code) {
	case 1:printf("# 사용자 코드 : %d(가정용)\n", code); break;
	case 2:printf("# 사용자 코드 : %d(상업용)\n", code); break;
	case 3:printf("# 사용자 코드 : %d(공업용)\n", code); break;
	}
	printf("# 사용량 : %d ton\n", ton);
	printf("# 총 수도요금 : %.lf원\n", cost + (double)cost*0.05);
	return;
}