#include <stdio.h>
void flush();
int inputInt(char *);

int main()
{
	int num, temp = 0;
	num = inputInt("# 정수 값을 입력하세요 : ");
	while (num != 0) {
		printf("*");
		num--;
		temp++;
		if (temp % 5 == 0 && num != 0) { printf("\n"); }
	}
	printf("\n");
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
		if (res == 1 && rt >= 0) { flush(); break; }
		else { flush(); }
	}
	return rt;
}