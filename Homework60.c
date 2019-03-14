#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inputArray(int (*ary)[5]);
void partSum(int(*ary)[5], int *sum1, int *sum2, int *sum3);
void print(int(*ary)[5], int sum1, int sum2, int sum3);

int main()
{
	int ary[5][5];
	int sum1 = 0, sum2 = 0, sum3 = 0;
	srand((unsigned int)time(NULL));
	inputArray(ary);
	partSum(ary, &sum1, &sum2, &sum3);
	print(ary, sum1, sum2, sum3);
	return 0;
}

void inputArray(int(*ary)[5])
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			ary[i][j] = rand() % 20 + 1;
		}
	}
}
void partSum(int(*ary)[5], int *sum1, int *sum2, int *sum3)
{
	for (int i = 0; i < 5; i++) {
		*sum1 += ary[i][i];
	}
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 5; j++) {
			*sum2 += ary[i][j];
		}
	}
	for (int i = 4; i >0 ; i--) {
		for (int j = i - 1; j >= 0; j--) {
			*sum3 += ary[i][j];
		}
	}
}
void print(int(*ary)[5], int sum1, int sum2, int sum3)
{
	for (int i = 0; i < 5; i++) {
		printf("%d¹ø Çà : ", i);
		for (int j = 0; j < 5; j++) {
			printf("%-3d", ary[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("sum1 = %-3d\n", sum1);
	printf("sum2 = %-3d\n", sum2);
	printf("sum3 = %-3d\n", sum3);
}