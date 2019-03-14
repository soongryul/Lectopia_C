#include <stdio.h>

void product(int(*matA)[4], int(*matB)[4], int(*matC)[4]);
void print(int(*matA)[4], int(*matB)[4], int(*matC)[4]);

int main()
{
	int matA[4][4] = { {0, 1, 2, 3}, {1, -2, 1, 2}, {2, 5, -3, 2}, {0, -3, 1, 4} };
	int matB[4][4] = { {1, -1, 2, 0}, {1, -1, 1, 2}, {-1, 0, 3, 1}, {2, -1, 2, 8} };
	int matC[4][4] = { 0 };
	product(matA, matB, matC);
	print(matA, matB, matC);
	return 0;
}

void product(int(*matA)[4], int(*matB)[4], int(*matC)[4])
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int m = 0; m < 4; m++) {
				matC[i][j] += matA[i][m] * matB[m][j];
			}
		}
	}
}
void print(int(*matA)[4], int(*matB)[4], int(*matC)[4])
{
	printf("[Matrix A]\t[Matrix B]\t[C = A * B]\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%-3d", matA[i][j]);
		}
		printf("\t");
		for (int j = 0; j < 4; j++) {
			printf("%-3d", matB[i][j]);
		}
		printf("\t");
		for (int j = 0; j < 4; j++) {
			printf("%-3d", matC[i][j]);
		}
		printf("\n");
	}
}