#include <stdio.h>
void cal(double y);

int main()
{
	double year = 365.2422;
	cal(year);
	return 0;
}

void cal(double y) {
	int h, m;
	double res;
	res = y;
	y -= 365;
	y *= 24 * 3600;
	h = y / 3600;
	y -= h * 3600;
	m = y / 60;
	y -= m * 60;
	printf("%.4lf일은 %.lf일 %d시간 %d분 %.2lf초 입니다.\n", res, res, h, m, y);
	return;
}