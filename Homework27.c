#include <stdio.h>
void flush();
int inputInt(char *);

int main()
{
	int weight;
	for (int i = 0; i != 10;) {
		weight = inputInt("# 계란의 무게를 입력하세요(단위 : g) : ");
		if (weight >= 150 && weight <= 500) { i++; printf("* 현재 달걀의 수 : %d\n", i); }
		else if (weight < 150) { printf("메추리알 가지고 장난하지 마시오~ ^^\n"); }
		else{ printf("타조알 가지고 장난하지 마시오~ ^^\n"); }
	}
	printf("\n*** 달걀 포장이 끝났습니다.\n");
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
		else { printf("재 입력\n"); flush(); }
	}
	return rt;
}