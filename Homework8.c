#include <stdio.h>

int main()
{
	int a, b, c;
	printf("����, ����, ���� ������ �Է��ϼ��� : ");
	scanf("%d %d %d", &a, &b, &c);
	printf("������ %d�̰� ����� %.2lf\n ", a + b + c, (double)(a + b + c) / 3);

	return 0;
}