#include <stdio.h>
void flush();
int inputInt(char *);
int dayCal(int);
void print(int, int);

int main()
{
	int deep, day;
	deep = inputInt("* �칰�� ���̸� �Է��Ͻÿ�(cm����) : ");
	day = dayCal(deep);
	print(deep, day);
	return 0;
}

void flush()
{
	while (getchar() != '\n');
	return;
}

int inputInt(char *msg)
{
	int rt, res;
	while (1) {
		printf(msg);
		res = scanf("%d", &rt);
		if (res == 1 && rt >= 0) { flush(); break; }
		else { flush(); }
	}
	return rt;
}

int dayCal(int d)
{
	int day = 0;
	if (d == 0) { return 0; }
	while (1) {
		d -= 50;
		if (d <= 0) { day++; break; }
		else { d += 20; day++; }
	}
	return day;
}

void print(int deep, int day)
{
	printf("%.2lf ���� ������ �칰�� Ż���ϱ� ���ؼ��� %d���� �ɸ��ϴ�.\n", (double)deep / 100, day);
	return;
}