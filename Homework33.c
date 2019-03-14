#include <stdio.h>

int inputUInt(char *msg);
double inputDouble(char *msg);
int ipow(int num, int N);
double fpow(double fnum, int N);

int main()
{
	int num, N;
	double fnum;
	num = inputUInt("* 양의 정수 밑을 입력 하시오 : ");
	N = inputUInt("* 양의 승을 입력하시오 : ");
	printf("%d의 %d승은 %d입니다.\n\n", num, N, ipow(num, N));
	fnum = inputDouble("* 양의 실수 밑을 입력 하시오 : ");
	N = inputUInt("* 양의 승을 입력하시오 : ");
	printf("%.2lf의 %d승은 %.3lf입니다.\n\n", fnum, N, fpow(fnum, N));
	return 0;
}

void flush()
{
	while (getchar() != '\n');
	return;
}

int inputUInt(char *msg)
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

double inputDouble(char *msg)
{
	double rt;
	int res;
	while (1) {
		printf(msg);
		res = scanf("%lf", &rt);
		if (res == 1 && rt > 0) { flush(); break; }
		else { flush(); printf("재 입력\n"); }
	}
	return rt;
}

int ipow(int num, int N)
{
		int sum = 1;
		for (int i = 0; i < N; i++) {
			sum *= num;
		}
		return sum;
}

double fpow(double fnum, int N)
{
	double sum = 1;
	for (int i = 0; i < N; i++) {
		sum *= fnum;
	}
	return sum;
}