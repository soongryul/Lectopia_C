#include <stdio.h>

int main()
{
	int num1, num2, res;
	while (1) {
		printf("# �� ���� ������ �Է��ϼ��� : ");
		res = scanf("%d %d", &num1, &num2);
		if (res != 2) { fflush(stdin); break; }
		if (num1 >= num2) { printf("%d - %d = %d\n", num1, num2, num1 - num2); }
		else if (num1 < num2) { printf("%d - %d = %d\n", num2, num1, num2 - num1); }
	}
	return 0;
}