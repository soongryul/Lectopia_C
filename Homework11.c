#include <stdio.h>
void flush();
int inputInt(char *msg);

int main()
{
	int num;
	num = inputInt("ASCII code ���� �Է��Ͻÿ� : ");
	printf("%d�� \'%c\'�� ASCII code �Դϴ�.\n", num, num);

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