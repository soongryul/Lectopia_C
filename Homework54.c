#include <stdio.h>
#include <string.h>

void flush();
int inputStr(char *str, char *ch);
int strCheck(char *str, int *strc, char *ch);

int main()
{
	char str[100];
	int strc[100];
	char ch;
	int n, check;
	while (1) {
		check = inputStr(str, &ch);
		if (check == 0) { break; }
		n = strCheck(str, strc, &ch);
		if (n == 0) { printf("\"%s\" 문자열 안에 \'%c\' 문자는 존재하지 않습니다.\n", str, ch); }
		else {
			printf("\"%s\" 문자열 안에 \'%c\' 문자는", str, ch);
			for (int i = 0; i < n; i++) {
				printf(" %d번 위치", strc[i]);
			}
			printf("에 존재합니다.\n");
		}
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
	if (strncmp(str, "end", 3) == 0) { return 0; }
	printf("# 문자를 입력하시오 : ");
	scanf("%c", ch);
	flush();
	return 1;
}

int strCheck(char *str, int *strc, char *ch)
{
	int n = 0;
	for (int i = 0; i < 100; i++) {
		if (strncmp(&str[i], ch, 1) == 0) { strc[n++] = i; }
		if (str[i] == '\0') { return n; }
	}
}