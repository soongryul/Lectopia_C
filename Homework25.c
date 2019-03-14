#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void flush();
int inputInt(char *);
int print(int);

int main()
{
	int r_num;
	srand((unsigned int)time(NULL));
	r_num = rand() % (100) + 1;
	printf("%d\n", r_num);
	printf("우와~ 맞았당~~~ 추카추카~~ %d 번째 만에 맞추셨습니다.\n", print(r_num));
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
		if (res == 1 && rt >= 1 && rt <= 100) { flush(); break; }
		else { printf("재 입력\n"); flush(); }
	}
	return rt;
}

int print(int r_num)
{
	int num, count = 0, temp1 = 0, temp2 = 100;
	while (1) {
		num = inputInt("# 숫자를 입력하시오 : ");
		count++;
		if (num != r_num) {
			if (num > r_num) { temp2 = num; }
			else { temp1 = num; }
			printf("%d 보다는 크고 %d 보다는 작습니다.\n", temp1, temp2);
		}
		else { break; }
	}
	return count;
}