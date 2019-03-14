#include <stdio.h>
int inputInt(char *msg);
void myflush();
void cal(int t);

int main()
{
	int time;
	time = inputInt("시간 입력 : ");
	cal(time);
	return 0;
}

int inputInt(char *msg) {
	int res, a;
	while (1) {
		printf("%s", msg);
		res = scanf("%d", &a);
		if (res == 1) { myflush(); break; }
		else { printf("잘못 입력\n"); myflush(); }
	}
	return a;
}

void myflush() {
	while (getchar() == '\n')
	return;
}

void cal(int t) {
	int h, m, res;
	res = t;
	h = t / 3600;
	t -= h * 3600;
	m = t / 60;
	t -= m * 60;
	printf("%d초는 %d시간 %d분 %d초 입니다.\n", res, h, m, t);
	return;
}