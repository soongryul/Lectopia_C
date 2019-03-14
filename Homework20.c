#include <stdio.h>
void flush();
int inputInt(char *);
int gpCal(int);
int taxCal(int);
void print(int, int);
int main()
{
	int hour, gp, tax;
	hour = inputInt("* 1���ϰ��� �ٹ��ð��� �Է��Ͻÿ� : ");
	gp = gpCal(hour);
	tax = taxCal(gp);
	print(gp, tax);
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
		if (res == 1 && rt > 0) { flush(); break; }
		else { flush(); }
	}
	return rt;
}

int gpCal(int hour)
{
	if (hour <= 40) { return 3000 * hour; }
	else { return 3000 * 40 + 4500 * (hour - 40); }
}

int taxCal(int gp)
{
	if (gp <= 100000) { return (int)(gp*0.15); }
	else{ return (int)15000+((gp-100000)*0.25); }
}

void print(int gp, int tax)
{
	int c = 1, temp = gp;
	while (temp / 10 != 0) {
		temp /= 10;
		c++;
	}
	printf("# �� ���� : %d��\n", gp);
	printf("# ��   �� : %*d��\n", c, tax);
	printf("# �� ���� : %d��\n", gp - tax);
	return;
}