#include <stdio.h>
#include <math.h>

void flush();
int inputInt(char *msg);
int primeNumber(int number);

int main()
{
	int num, cnt = 0;
	num = inputInt("* ���� �� �ϳ��� �Է��Ͻÿ� : ");
	printf("1~%d������ �Ҽ� ���� ������ �����ϴ�.\n", num);
	for (int i = 2; i <= num; i++) {
		if (primeNumber(i)==1) {
			printf("%-6d", i); 
			cnt++; 
			if (cnt % 5 == 0) { printf("\n"); }
		}
	}
	printf("\n1~%d������ �� �Ҽ��� %d�� �Դϴ�.\n", num, cnt);
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
		if (res == 1 && rt > 1) { break; }
		else { flush(); }
	}
	return rt;
}

int primeNumber(int number)
{
	for (int i = 2; i <= sqrt(number); i++) {
		if (number%i == 0) { return 0; }
	}
	return 1;
}