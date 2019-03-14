#include <stdio.h>
#define N 100

void swap(int *ary, int size);

int main()
{
	int ary[N], size = sizeof(ary) / sizeof(ary[0]);
	for (int i = 0; i < size; i++) {
		ary[i] = i + 1;
	}
	printf("ó�� �迭�� ����� �� : ");
	for (int i = 0; i < sizeof(ary) / sizeof(ary[0]); i++) {
		printf("%4d", ary[i]);
	}
	printf("\n�ٲ� �迭�� ����� �� : ");
	swap(ary, size);
	for (int i = 0; i < sizeof(ary) / sizeof(ary[0]); i++) {
		printf("%4d", ary[i]);
	}
	printf("\n");
	return 0;
}

void swap(int *ary, int size)
{
	int temp;
	for (int i = 0; i < size/2; i++) {
		temp = ary[i];
		ary[i] = ary[size - 1 - i];
		ary[size - 1 - i] = temp;
	}
}