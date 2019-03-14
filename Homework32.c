#include <stdio.h>

void flush();
char menu();
int inputInt(char *msg);
int deposit();
int withdraw();

int main()
{
	int sum = 0, ch = 0, temp;
	while (ch!='q') {
		ch = menu();
		switch (ch) {
		case 'i':
			temp = deposit();
			sum += temp;
			break;
		case 'o':
			temp = withdraw();
			if (sum > temp) { sum -= temp; }
			else { printf("* �ܾ��� �����մϴ�.\n"); }
			break;
		case'q':
			; break;
		}
		temp = 0;
		printf("* ���� �ܾ��� %d�� �Դϴ�.\n\n", sum);
	}
	return 0;
}

void flush()
{
	while (getchar() != '\n');
	return;
}

char menu()
{
	int res;
	char rt;
	while (1) {
		printf("# �޴��� �����Ͻÿ�(i-�Ա�, o-���, q-����) : ");
		res = scanf("%c", &rt);
		if (res == 1 && (rt == 'i' || rt == 'o' || rt == 'q')) { flush(); break; }
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
		if (res == 1 && rt >= 0) { flush(); break; }
		else { flush(); printf("�� �Է�\n"); }
	}
	return rt;
}

int deposit()
{
	int money;
	money = inputInt("# �Աݾ��� �Է��ϼ��� : ");
	return money;
}

int withdraw()
{
	int money;
	money = inputInt("# ��ݾ��� �Է��ϼ��� : ");
	return money;
}