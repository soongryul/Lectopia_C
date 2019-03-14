#include <stdio.h>

void flush();
void inputArray(double *ary);
double calMax(double *ary);
double calMin(double *ary);
void print(double, double);

int main()
{
	double ary[5], max, min;
	inputArray(ary);
	printf("\n");
	max = calMax(ary);
	min = calMin(ary);
	print(max, min);
	return 0;
}

void flush()
{
	while (getchar() != '\n');
}

void inputArray(double *ary)
{
	for (int i = 0; i < 5; i++) {
		while (1) {
			printf("%d번 방 값 : ", i);
			scanf("%lf", ary + i);
			if (getchar() == '\n') { break; }
			else { flush(); }
		}
	}
}

double calMax(double *ary)
{
	double max = 0;
	for (int i = 0; i < 5; i++) {
		if (max < ary[i]) { max = ary[i]; }
	}
	return max;
}

double calMin(double *ary)
{
	double min = 0;
	for (int i = 0; i < 5; i++) {
		if (min > ary[i]) { min = ary[i]; }
	}
	return min;
}

void print(double max, double min)
{
	printf("가장 큰 값 : %.2lf\n가장 작은 값 : %.2lf\n", max, min);
}