#include <stdio.h>

int main()
{
	char ch;
	int a = 0, b = 0, c = 0, d = 0;
	printf("# ���� ������ �Է� �Ͻÿ� : \n");
	while (1) {
		ch = getchar();
		if (ch == EOF) { break; }
		else if ((ch >= 'A'&& ch <= 'Z') || (ch >= 'a'&&ch <= 'z')) { a++; }
		else if (ch >= '0'&&ch <= '9') { b++; }
		else if (ch == ' ' || ch == '\t' || ch == '\n') { c++; }
		else { d++; }
	}
	printf("* ������ ��ҹ��� ���� : %d��\n", a);
	printf("* ���ڹ��� ���� : %d��\n", b);
	printf("* ���鹮��(space, tab, enter)���� : %d��\n", c);
	printf("* �� �� ��Ÿ���� ���� : %d��\n", d);
	return 0;
}