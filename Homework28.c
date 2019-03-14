#include <stdio.h>

int main()
{
	char ch;
	int a = 0, b = 0, c = 0, d = 0;
	printf("# 영문 문장을 입력 하시오 : \n");
	while (1) {
		ch = getchar();
		if (ch == EOF) { break; }
		else if ((ch >= 'A'&& ch <= 'Z') || (ch >= 'a'&&ch <= 'z')) { a++; }
		else if (ch >= '0'&&ch <= '9') { b++; }
		else if (ch == ' ' || ch == '\t' || ch == '\n') { c++; }
		else { d++; }
	}
	printf("* 영문자 대소문자 개수 : %d개\n", a);
	printf("* 숫자문자 개수 : %d개\n", b);
	printf("* 여백문자(space, tab, enter)개수 : %d개\n", c);
	printf("* 그 외 기타문자 개수 : %d개\n", d);
	return 0;
}