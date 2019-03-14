#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define flush() while(getchar()!='\n')

int **myAlloc(int);
void myDelete(int **, int);
int inputInt(char *msg);
void input(int **ip, int);
void output(int **ip, int);

int main()
{
	int **ip;
	int row_col;
	while (row_col = inputInt("# 행/열의 수 입력(0 입력 시 종료) : ")) {
		ip = myAlloc(row_col);
		input(ip, row_col);
		output(ip, row_col);
		myDelete(ip, row_col);
	}
	return 0;
}

int **myAlloc(int row_col)
{
	int **p;
	p = (int **)malloc(sizeof(int *)*row_col);
	for (int i = 0; i < row_col; i++) {
		p[i] = (int *)malloc(sizeof(int)*row_col);
	}
	return p;
}
void myDelete(int **ip, int row)
{
	for (int i = 0; i < row; i++) {
		free(ip[i]);
	}
	free(ip);
}
int inputInt(char *msg)
{
	int rt;
	while (1) {
		printf(msg);
		if (scanf("%d", &rt) && (rt == 0 || rt > 1)) { break; }
		else { printf("재 입력\n"); flush(); }
	}
	return rt;
}
void input(int **ip, int row_col)
{
	int num = 1;
	int temp = (int)(row_col-1) / 2;
	for (int j = 0; j <= temp; j++) {
		for (int i = j; i < row_col - j; i++) {
			ip[j][i] = num;
			//printf("ip[%d][%d] = %d\n", j, i, num);
			num++;
		}
		for (int i = j + 1; i < row_col - j; i++) {
			ip[i][(row_col -1) - j] = num;
			//printf("ip[%d][%d] = %d\n", i, row_col-j, num);
			num++;
		}
		for (int i = row_col - (j + 2); i >= j; i--) {
			ip[(row_col - 1) - j][i] = num;
			//printf("ip[%d][%d] = %d\n", row_col -j, i, num);
			num++;
		}
		for (int i = row_col - (j + 2); i > j; i--) {
			ip[i][j] = num;
			//printf("ip[%d][%d] = %d\n", i, j, num);
			num++;
		}
	}
}
void output(int **ip, int row_col)
{
	for (int i = 0; i < row_col; i++) {
		for (int j = 0; j < row_col; j++) {
			printf("%3d", ip[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}