#include <stdio.h>

int main()
{
	double a, b, c, d, e;

	printf("- 1�� �л��� Ű��? ");
	scanf("%lf", &a);
	printf("- 2�� �л��� Ű��? ");
	scanf("%lf", &b);
	printf("- 3�� �л��� Ű��? ");
	scanf("%lf", &c);
	printf("- 4�� �л��� Ű��? ");
	scanf("%lf", &d);
	printf("- 5�� �л��� Ű��? ");
	scanf("%lf", &e);
	printf("�ټ� ���� ��� Ű�� %.1lf cm �Դϴ�. \n", (a + b + c + d + e) / 5);
	return 0;
}