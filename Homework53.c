#include <stdio.h>
#include <string.h>

void flush();
int inputStr(char *str, char *ch);
int strCheck(char *str, char *ch);

int main()
{
	char str[100];
	char ch;
	int n, check;
	while (1) {
		check = inputStr(str, &ch);
		if (check == -1) { break; }
		n = strCheck(str, &ch);
		if (n == -1) { printf("\"%s\" 문자열 안에 \'%c\' 문자는 존재하지 않습니다.\n", str, ch); }
		else{ printf("\"%s\" 문자열 안에 \'%c\' 문자는 %d번 위치에 존재합니다.\n", str, ch, n); }
		printf("\n");
	}
	return 0;
}

void flush()
{
	while (getchar() != '\n');
}

int inputStr(char *str, char *ch)
{
	printf("# 문자열을 입력하세요 : ");
	scanf("%s", str);
	flush();
	if (strncmp(str, "end", 3) == 0) { return -1; }
	printf("# 문자를 입력하시오 : ");
	scanf("%c", ch);
	flush();
	return 0;
}

int strCheck(char *str, char *ch)
{
	int n;
	for (int i = 0; i < 100; i++) {
		if (strncmp(&str[i], ch, 1) == 0) { n = i; return n; }
	}
	return -1;
}