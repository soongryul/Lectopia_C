#include <stdio.h>

int main()
{
	int res, num, sum = 0;
	for (int i = 1; i <= 5;) {
		printf("0 ���� ū ���� �Է��Ͻÿ�(%d ��°) : ", i);
		res = scanf("%d", &num);
		if (res == 1 && num > 0) { sum += num; i++; }
	}
	printf("�Էµ� ���� �� �� : %d\n", sum);
	return 0;
}