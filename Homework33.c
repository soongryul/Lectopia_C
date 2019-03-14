#include <stdio.h>

int inputUInt(char *msg);
double inputDouble(char *msg);
int ipow(int num, int N);
double fpow(double fnum, int N);

int main()
{
	int num, N;
	double fnum;
	num = inputUInt("* ���� ���� ���� �Է� �Ͻÿ� : ");
	N = inputUInt("* ���� ���� �Է��Ͻÿ� : ");
	printf("%d�� %d���� %d�Դϴ�.\n\n", num, N, ipow(num, N));
	fnum = inputDouble("* ���� �Ǽ� ���� �Է� �Ͻÿ� : ");
	N = inputUInt("* ���� ���� �Է��Ͻÿ� : ");
	printf("%.2lf�� %d���� %.3lf�Դϴ�.\n\n", fnum, N, fpow(fnum, N));
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
		else { flush(); printf("�� �Է�\n"); }
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
		else { flush(); printf("�� �Է�\n"); }
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