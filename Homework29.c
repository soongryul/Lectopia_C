#include <stdio.h>
void flush();
int inputInt(char *);
int transNumber(int);
void print(int, int, int);

int main()
{
	int p1, p2, n;
	p1 = inputInt("시작 값(P1) : ");
	p2 = inputInt("끝 값(P2) : ");
	n = inputInt("고집수(N) : ");
	print(p1, p2, n);
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
		else { flush(); printf("재 입력\n"); }
	}
	return rt;
}

int transNumber(int num)
{
	int rt = 1, count = 1, temp, j;
	temp = num;
	while (temp / 10 != 0) {
		count++;
		temp /= 10;
	}
	for (j = 0; j < count; j++) {
		temp = num % 10;
		rt *= temp;
		num /= 10;
	}
	return rt;
}

void print(int p1, int p2, int n)
{
	int temp, count_n, count = 0;
	for (int i = p1; i <= p2; i++) {
		temp = i;
		count_n = 0;
		while (1) {
			temp = transNumber(temp);
			count_n++;
			if (temp / 10 == 0) { break; }
		}
		if (count_n == n) { printf("%d\n", i); count++; }
	}
	printf("총 개수 : %d개\n", count);
}