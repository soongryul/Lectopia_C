#include <stdio.h>
#include <string.h>

int main()
{
	char str[20];
	printf("* 문자열 입력 :");
	scanf("%s", str);
	printf("[%*.*s...]", strlen(str), strlen(str)/2, str);
	return 0;
}