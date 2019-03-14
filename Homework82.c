#include <stdio.h>
#include <time.h>
#include <Windows.h>

int timer(struct tm *now);

int main()
{
	struct tm *now;
	time_t now_t;
	time(&now_t);
	now = localtime(&now_t);
	while (timer(now)) {
		Sleep(1000);
		system("cls");
	}
	return 0;
}

int timer(struct tm *now)
{
	int sec = clock() / 1000;
	if (sec == 11) { return 0; }
	else {
		printf("현재의 날짜와 시간\n");
		printf("%5d년", now->tm_year + 1900);
		printf("%3d월", now->tm_mon + 1);
		printf("%3d일", now->tm_mday);
		printf("%3d시", now->tm_hour);
		printf("%3d분", now->tm_min);
		printf("%3d초\n", now->tm_sec + sec);
		return 1;
	}
}