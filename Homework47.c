#include <stdio.h>
#include <windows.h>
#include <conio.h>

void flush();
void gotoxy(int x, int y);
void input(int *sx, int *ex, int *sy, int *ey);
void makingBox(int *sx, int *ex, int *sy, int *ey);

int main()
{
	char ch = 0;
	int sx, ex, sy, ey;
	input(&sx, &ex, &sy, &ey);
	while (ch!=27) {
		system("cls");
		makingBox(&sx, &ex, &sy, &ey);
		ch = getch();
			switch (ch) {
			case 'w':
				if (sy != 0) { sy--; ey--; }
				else { printf("\a"); }
				break;
			case 's':
				if (ey != 25) { sy++; ey++; }
				else { printf("\a"); }
				break;
			case 'a':
				if (sx != 0) { sx--; ex--; }
				else { printf("\a"); }
				break;
			case 'd':
				if (ex != 80) { sx++; ex++; }
				else { printf("\a"); }
				break;
			}
	}

	return 0;
}

void gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void flush()
{
	while (getchar() != '\n');
}

void input(int *sx, int *ex, int *sy, int *ey)
{
	int temp, res;
	while (1) {
		printf("sx ÁÂÇ¥ ÀÔ·Â(1 ~ 70) : ");
		res = scanf("%d", &temp);
		if (res == 1 && (temp >= 1 && temp <= 70)) { flush(); break; }
		else { flush(); }
	}
	*sx = temp;

	while (1) {
		printf("ex ÁÂÇ¥ ÀÔ·Â(%d ~ 80) : ", *sx + 1);
		res = scanf("%d", &temp);
		if (res == 1 && (temp >= *sx + 1&& temp <= 80)) { flush(); break; }
		else { flush(); }
	}
	*ex = temp;

	while (1) {
		printf("sy ÁÂÇ¥ ÀÔ·Â(1 ~ 20) : ");
		res = scanf("%d", &temp);
		if (res == 1 && (temp >= 1 && temp <= 20)) { flush(); break; }
		else { flush(); }
	}
	*sy = temp;

	while (1) {
		printf("ey ÁÂÇ¥ ÀÔ·Â(%d ~ 24) : ", *sy + 1);
		res = scanf("%d", &temp);
		if (res == 1 && (temp >= *sy + 1 && temp <= 24)) { flush(); break; }
		else { flush(); }
	}
	*ey = temp;
}

void makingBox(int *sx, int *ex, int *sy, int *ey)
{
	gotoxy(*sx, *sy);
	for (int i = 0; i <= *ex - *sx; i++) {
		printf("*");
	}
	gotoxy(*sx, *ey);
	for (int i = 0; i <= *ex - *sx; i++) {
		printf("*");
	}
	for (int i = 1; i <= *ey - *sy; i++) {
		gotoxy(*sx, *sy + i);
		printf("*");
	}
	for (int i = 1; i <= *ey - *sy; i++) {
		gotoxy(*ex, *sy + i);
		printf("*");
	}
}