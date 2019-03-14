#include <stdio.h>
#include <string.h>
#include <ctype.h>

int inputStr(char *str);
void flush();
int checkPalindrome(char *str);
void print(char *str, int check);

int main()
{
	char str[20];
	int n = 0;
	while (1) {
		n = inputStr(str);
		if (n == -1) { break; }
		print(str, checkPalindrome(str));
	}
	return 0;
}
void flush()
{
	while (getchar() != '\n');
}
int inputStr(char *str)
{
	printf("# 단어 입력 : ");
	scanf("%s", str);
	flush();
	if (strncmp(str, "end", 3)==0) { return -1; }
	return 0;
}
int checkPalindrome(char *str)
{
	int length = strlen(str);
	char strC[20];
	strcpy(strC, str);
	for (int i = 0; i < length; i++) {
		strC[i] = toupper(strC[i]);
	}
	int cnt = 0;
	for (int i = 0; i < length / 2; i++) {
		if (strncmp(&strC[i], &strC[length - 1 - i], 1) == 0) { cnt++; }
	}
	if (cnt == length / 2) { return 1; }
	else { return 0; }
}
void print(char *str, int check)
{
	switch (check) {
	case 0: printf("\"%s\" : 회문이 아닙니다!\n\n", str); break;
	case 1: printf("\"%s\" : 회문입니다!\n\n", str); break;
	}
}