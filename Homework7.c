#include <stdio.h>
double inputDouble(char *msg);
void myflush();

int main()
{
	double km, km_h, time, sec;
	int hour, min;
	km = inputDouble("주행거리 : ");
	km_h = inputDouble("시속 : ");
	time = km / km_h;
	hour = (int)time;
	time -= hour;
	time *= 60.0;
	min = (int)time;
	time -= min;
	sec = time * 60.0;
	printf("%.lf km ==> %d시간 %d분 %.3lf초 소요됨.\n", km, hour, min, sec);
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
	while (getchar() != 'n');
	return;
}