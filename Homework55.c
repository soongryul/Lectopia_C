#include <stdio.h>
#include <windows.h>
#include <string.h>

void inputStr(char *str, int size);
void scroll(char *str, int size);
void blink(char *str);
void clear();
void gotoxy(int x, int y);

int main()
{
	char str[51];
	int length, size = sizeof(str)/sizeof(str[0]);
	inputStr(str, size);
	length = strlen(str);
	scroll(str, length);
	blink(str);
	return 0;
}

void inputStr(char *str, int size)
{
	printf("문자열을 입력하시오 : ");
	fgets(str, 51, stdin);
	str[strlen(str) - 1] = '\0';
}

void gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void scroll(char *str, int length)
{
	char tp;
	gotoxy(30, 12);
	printf("%s\n", str);
	Sleep(200);
	for (int j = 0; j < length*2; j++) {
		clear();
		tp = str[0];
		for (int i = 0; i < length - 1; i++) {
			str[i] = str[i + 1];
		}
		str[length - 1] = tp;
		gotoxy(30, 12);
		printf("%s\n", str);
		Sleep(200);
	}
}

void clear()
{
	system("cls");
}

void blink(char *str)
{
	for (int i = 0; i < 3; i++) {
		clear();
		Sleep(300);
		gotoxy(30, 12);
		printf("%s", str);
		Sleep(300);
	}

}