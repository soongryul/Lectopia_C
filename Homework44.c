#include <stdio.h>

int main()
{
	int i, j, k;
	printf("<2중 for문을 이용한 출력>\n");
	for (i = 1; i <= 9; i++) {
		for (j = 2; j <= 5; j++) {
			printf("%d * %d = %2d\t", j, i, j*i);
		}
		printf("\n");
	}
	printf("\n");
	for (i = 1; i <= 9; i++) {
		for (j = 6; j <= 9; j++) {
			printf("%d * %d = %2d\t", j, i, j*i);
		}
		printf("\n");
	}
	printf("------------------------------------------------------------------------------------------\n");
	printf("<3중 for문을 이용한 출력>\n");
	for (i = 0; i < 2; i++) {
		for (j = 1; j <= 9; j++) {
			for (k = 2 + (i * 4); k <= 5 + (i * 4); k++) {
				printf("%d * %d = %2d\t", k, j, k*j);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}