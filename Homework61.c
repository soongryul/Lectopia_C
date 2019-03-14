#include <stdio.h>
#include <string.h>

void inputStr(char(*str)[20]);
void sortStr(char(*str)[20]);
void printStr(char(*str)[20]);

int main()
{
	char str[5][20];
	inputStr(str);
	sortStr(str);
	printStr(str);
	return 0;
}

void inputStr(char(*str)[20])
{
	for (int i = 0; i < 5; i++) {
		printf("# %d번 문자열을 입력하시오 : ", i + 1);
		scanf("%s", &str[i]);
		fflush(stdin);
	}
}
void sortStr(char(*str)[20])
{
	int n;
	char temp[20];
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 5; j++) {
			n = strcmp(&str[i], &str[j]);
			if (n > 0) {
				strcpy(temp, &str[i]);
				strcpy(&str[i], &str[j]);
				strcpy(&str[j], temp);
			}
		}
	}
}
void printStr(char(*str)[20])
{
	for (int i = 0; i < 5; i++) {
		printf("str[%d] = %s  %c  %c\n", i, str[i], str[i][0], str[i][strlen(&str[i])-1]);
	}
}