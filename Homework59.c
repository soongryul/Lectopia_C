#include <stdio.h>

void inputArray(int(*ary)[4], int row, int col);

int main()
{
	int ary[3][4];
	int sum = 0;
	int row = sizeof(ary) / sizeof(ary[3]);
	int col = sizeof(ary[3]) / sizeof(ary[3][4]);
	inputArray(ary, row, col);
	for (int i = 0; i < row; i++) {
		printf("%-5d행 : ", i);
		for (int j = 0; j < col; j++) {
			printf("%-5d", ary[i][j]);
			sum += ary[i][j];
		}
		printf("\%5d행의 합 : %d\n", i, sum);
		sum = 0;
	}
	printf("열의 합 : ");
	for (int m = 0; m < col; m++) {
		for (int n = 0; n < row; n++) {
			sum += ary[n][m];
		}
		printf("%-5d", sum);
		sum = 0;
	}
	printf("\n");
	return 0;
}

void inputArray(int(*ary)[4], int row, int col)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("num[%d][%d] = ", i, j);
			scanf("%d", &ary[i][j]);
			fflush(stdin);
		}
	}
}