#include <stdio.h>
double inputDouble(char *msg);
void print(double f);
void myflush();

int main()
{
	print(inputDouble("화씨 온도를 입력하세요 : "));
	return 0;
}

double inputDouble(char *msg)
{
	int res;
	double rt;
	while (1) {
		printf("%s", msg);
		res = scanf("%lf", &rt);
		if (res == 1) { break; }
		else { myflush(); }
	}
	return rt;
}
void myflush()
{
	while (getchar != 'n') { ; }
	return;
}
void print(double f)
{
	f = 5.0 / 9.0*(f - 32.0);
	printf("섭씨 온도는 %.1lf도 입니다.\n", f);
	return;
}