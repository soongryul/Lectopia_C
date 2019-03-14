#include <stdio.h>
void flush();
int inputInt(char *);
int yearCheck(int);
void output(int, int);

int main()
{
	int year, rt;
	year = inputInt("년도를 입력하시오 : ");
	rt = yearCheck(year);
	output(year, rt);
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

int yearCheck(int year)
{
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 4 == 0) { return 1; }
			else { return 0; }
		}
		else { return 1; }
	}
	else { return 0; }
}

void output(int year, int rt)
{
	if (rt == 0) { printf("%d년은 평년(Common year)입니다.\n", year); }
	else{ printf("%d년은 윤년(Leap year)입니다.\n", year); }
	return;
}