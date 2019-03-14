#include <stdio.h>

void flush();
int inputInt(char *msg);

int main()
{
	int line;
	while (1) {
		line = inputInt("# 출력 라인 수를 입력하시오 : ");
		if (line == -1) { break; }
		for (int i = 0; i < line; i++) {
			for (int j = 0; j <= i; j++) {
				printf("*");
			}
			printf("%*c", line-i, ' ');
			printf("%*c", line-i, ' ');
			for (int j = 0; j <= i; j++) {
				printf("*");
			}
			printf("\n");
		}
	}
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
		if (res == 0) { flush(); return -1; }
		else if (res == 1 & rt > 0) { flush(); break; }
		else { flush(); }
	}
	return rt;
}