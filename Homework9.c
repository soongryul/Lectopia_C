#include <stdio.h>
void flush();
int inputInt(char *msg);

int main()
{
	int number;
	number = inputInt("�������� �Է��ϼ��� : ");
	printf("�Էµ� ���� 8������ %#o �Դϴ�.\n", number);
	printf("�Էµ� ���� 16������ %#x �Դϴ�.\n", number);

	return 0;
}

void flush()
{
	while (getchar() != '\n') {}
	return;
}

int inputInt(char *msg)
{
	int rt, res;
	while (1) {
		printf("%s", msg);
		res = scanf("%d", &rt);
		if (res == 1) { break; }
		else { flush(); }
	}
	return rt;
}