#include <stdio.h>

void flush();
char menu();
int inputInt(char *msg);
int deposit();
int withdraw();

int main()
{
	int sum = 0, ch = 0, temp;
	while (ch!='q') {
		ch = menu();
		switch (ch) {
		case 'i':
			temp = deposit();
			sum += temp;
			break;
		case 'o':
			temp = withdraw();
			if (sum > temp) { sum -= temp; }
			else { printf("* 잔액이 부족합니다.\n"); }
			break;
		case'q':
			; break;
		}
		temp = 0;
		printf("* 현재 잔액은 %d원 입니다.\n\n", sum);
	}
	return 0;
}

void flush()
{
	while (getchar() != '\n');
	return;
}

char menu()
{
	int res;
	char rt;
	while (1) {
		printf("# 메뉴를 선택하시오(i-입금, o-출금, q-종료) : ");
		res = scanf("%c", &rt);
		if (res == 1 && (rt == 'i' || rt == 'o' || rt == 'q')) { flush(); break; }
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
		if (res == 1 && rt >= 0) { flush(); break; }
		else { flush(); printf("재 입력\n"); }
	}
	return rt;
}

int deposit()
{
	int money;
	money = inputInt("# 입금액을 입력하세요 : ");
	return money;
}

int withdraw()
{
	int money;
	money = inputInt("# 출금액을 입력하세요 : ");
	return money;
}