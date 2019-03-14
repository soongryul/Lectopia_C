#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#define BLACK 0
#define LIGHTGRAY 7
#define LIGHTBLUE 9
#define LIGHTRED 12
#define WHITE 15

#define sun gotoxy(temp1, temp2)
#define mon gotoxy(temp1 + 5, temp2)
#define tue gotoxy(temp1 + 10, temp2)
#define wed gotoxy(temp1 + 15, temp2)
#define thu gotoxy(temp1 + 20, temp2)
#define fri gotoxy(temp1 + 25, temp2)
#define sat gotoxy(temp1 + 30, temp2)

void textcolor(int foreground, int background);
void gotoxy(int x, int y);
int yearCheck(int year);
int outputDay(int year, int month);
int outputDW(int year, int month, int day);
char input();
void print(int year, int month);
void clear();

int main()
{
	int year = 2016, month = 7;
	int key = 1;
	while (key) {
		clear();
		print(year, month);
		switch(key = input()) {
		case 'w': year--; break;
		case 's': year++; break;
		case 'a': month--; break;
		case 'd': month++; break;
		case 27: key = 0; break;
		}
		if (month == 0) { month = 12; year--; }
		else if (month == 13) { month = 1; year++; }
		if (year == 1899) { break; }
	}
	return 0;
}
void clear()
{
	system("cls");
}
void textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
int yearCheck(int year)
{
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) { return 1; }
			else { return 0; }
		}
		else { return 1; }
	}
	else { return 0; }// 1 : 윤년, 0 : 평년
}
int outputDay(int year, int month)
{
	int day;
	int mont[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (yearCheck(year) == 1) { mont[1] += 1; }
	day = mont[month - 1];
	return day;
}
int outputDW(int year, int month, int day)
{
	int mont[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int sum = 0;
	for (int i = 1900; i < year; i++) {
		if (yearCheck(i) == 1) { sum += 366; }
		else { sum += 365; }
	}
	if (yearCheck(year) == 1) { mont[1] += 1; }
	for (int i = 1; i < month; i++) {
		sum += mont[i - 1];
	}
	sum += day;
	return (sum % 7);// 0 : 일요일, 1 : 월요일..., 6 : 토요일
}
char input()
{
	char key;
	while (1) {
		key = getch();
		if (key == 'w' || key == 's' || key == 'a' || key == 'd' || key == 27) { return key; }
	}
}
void print(int year, int month)
{
	int dw;
	int temp1 = 21, temp2 = 6;
	int day = outputDay(year, month);
	textcolor(WHITE, BLACK);
	gotoxy(30, 1);
	printf("[ %d . %d ]", year, month);
	gotoxy(20, 4);
	printf("SUN  MON  TUE  WED  THU  FRI  SAT");
	gotoxy(17, 5);
	printf("---------------------------------------");
	for (int i = 1; i <= day; i++) {
		textcolor(LIGHTGRAY, BLACK);
		dw = outputDW(year, month, i);
		switch (dw) {
		case 0:sun; textcolor(LIGHTRED, BLACK); break;
		case 1:mon; break;
		case 2:tue; break;
		case 3:wed; break;
		case 4:thu; break;
		case 5:fri; break;
		case 6:sat; textcolor(LIGHTBLUE, BLACK); break;
		}
		printf("%2d", i);
		if (dw==6) { temp2++; }
	}
	textcolor(WHITE, BLACK);
	gotoxy(2, 13);
	printf("w : 전 년도 / s : 다음 년도 / a : 전 월 / d : 다음 월 / ESC : 종료\n");
}