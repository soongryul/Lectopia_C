#include <stdio.h>

void flush();
int yearCheck(int year);
int input(int *year, int *month, int *day);
int check(int, int, int);
int daySum(int year, int month, int day);
void print(int year, int month, int day, int sum);

int main()
{
	int temp, sum, year, month, day;
	while (1) {
		temp = input(&year, &month, &day);
		if (temp == -1) { break; }
		sum = daySum(year, month, day);
		print(year, month, day, sum);
	}
	return 0;
}

int yearCheck(int year)//return 값 1: 윤년, 0: 평년
{
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) { return 1; }
			else { return 0; }
		}
		else { return 1; }
	}
	else { return 0; }
}

void flush()
{
	while (getchar() != '\n');
}

int input(int *year, int *month, int *day)
{
	int tp1, tp2, tp3;
	while (1) {
		printf("* 년 월 일을 입력하시오 : ");
		scanf("%d %d %d", &tp1, &tp2, &tp3);
		if (getchar() == '\n') {
			if (check(tp1, tp2, tp3) == 1) {
				*year = tp1;
				*month = tp2;
				*day = tp3;
				break;
			}
			else { printf("재 입력\n"); }
		}
		else { return -1; }
	}
	return 1;
}

int check(int y, int m, int d)
{
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (y > 1899 && m > 0 && m < 13 && d > 0) {
		if (yearCheck(y) == 1) { month[1] += 1; }
		if (d > month[m - 1]) { return -1; }
	}
	else { return -1; }
	return 1;
}

int daySum(int year, int month, int day)
{
	int mon[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int sum = 0;
	for (int i = 1900; i < year; i++) {
		if (yearCheck(i) == 1) { sum += 366; }
		else { sum += 365; }
	}
	//printf("%d\n", sum);
	if (yearCheck(year) == 1) { mon[1] += 1; }
	for (int i = 1; i < month; i++) {
		sum += mon[i-1];
	}
	//printf("%d\n", sum);
	sum += day;
	//printf("%d\n", sum);
	return sum;
}

void print(int year, int month, int day, int sum)
{
	switch (sum % 7) {
	case 0: printf("%d년 %d월 %d일은 일요일입니다.\n\n", year, month, day); break;
	case 1: printf("%d년 %d월 %d일은 월요일입니다.\n\n", year, month, day); break;
	case 2: printf("%d년 %d월 %d일은 화요일입니다.\n\n", year, month, day); break;
	case 3: printf("%d년 %d월 %d일은 수요일입니다.\n\n", year, month, day); break;
	case 4: printf("%d년 %d월 %d일은 목요일입니다.\n\n", year, month, day); break;
	case 5: printf("%d년 %d월 %d일은 금요일입니다.\n\n", year, month, day); break;
	case 6: printf("%d년 %d월 %d일은 토요일입니다.\n\n", year, month, day); break;
	}
}