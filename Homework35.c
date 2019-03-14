#include <stdio.h>

void flush();
int inputCode(char *msg);
int inputInt(char *msg);
int Cal(int ton, int code);
void print(int cost, int ton, int code);

int main()
{
	int code, ton, cost;
	code = inputCode("* ����� �ڵ带 �Է��Ͻÿ�(1:������/ 2:�����/ 3:������) : ");
	ton = inputInt("* ��뷮�� �Է��Ͻÿ�(ton����) : ");
	cost = Cal(ton, code);
	printf("\n");
	print(cost, ton, code);
	return 0;
}

void flush()
{
	while (getchar() != '\n');
	return;
}

int inputCode(char *msg)
{
	int rt, res;
	while (1) {
		printf(msg);
		res = scanf("%d", &rt);
		if (res == 1 && rt >= 1 && rt <= 3) { flush(); break; }
		else { flush(); printf("�� �Է�\n"); }
	}
	return rt;
}

int inputInt(char *msg)
{
	int rt, res;
	while (1) {
		printf(msg);
		res = scanf("%d", &rt);
		if (res == 1 && rt > 0) { flush(); break; }
		else { flush(); printf("�� �Է�\n"); }
	}
	return rt;
}

int Cal(int ton, int code)
{
	switch (code) {
	case 1: return ton * 50;
	case 2: return ton * 45;
	case 3: return ton * 30;
	}
}

void print(int cost, int ton, int code)
{
	switch (code) {
	case 1:printf("# ����� �ڵ� : %d(������)\n", code); break;
	case 2:printf("# ����� �ڵ� : %d(�����)\n", code); break;
	case 3:printf("# ����� �ڵ� : %d(������)\n", code); break;
	}
	printf("# ��뷮 : %d ton\n", ton);
	printf("# �� ������� : %.lf��\n", cost + (double)cost*0.05);
	return;
}