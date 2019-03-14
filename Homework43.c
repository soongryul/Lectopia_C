#include <stdio.h>

int main()
{
	char ch;
	int i, j;
	while (1) {
		printf("* 영문자 대문자 입력( 'A' ~ 'Z' ) : ");
		scanf("%c", &ch);
		if (getchar() == '\n'&&ch >= 'A'&&ch <= 'Z') {
			for (i = 0; i <= ch - 'A'; i++) {
				for (j = 0; j <= i; j++) {
					printf("%c", ch - j);
				}
				printf("\n");
			}
		}
		else { break; }
	}
	return 0;
}