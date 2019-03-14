#include <stdio.h>

int main()
{
	int res, num, sum = 0;
	for (int i = 1; i <= 5;) {
		printf("0 보다 큰 수를 입력하시오(%d 번째) : ", i);
		res = scanf("%d", &num);
		if (res == 1 && num > 0) { sum += num; i++; }
	}
	printf("입력된 값의 총 합 : %d\n", sum);
	return 0;
}