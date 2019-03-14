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
		if (n == -1) { printf("\"%s\" ���ڿ� �ȿ� \'%c\' ���ڴ� �������� �ʽ��ϴ�.\n", str, ch); }
		else{ printf("\"%s\" ���ڿ� �ȿ� \'%c\' ���ڴ� %d�� ��ġ�� �����մϴ�.\n", str, ch, n); }
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
	printf("# ���ڿ��� �Է��ϼ��� : ");
	scanf("%s", str);
	flush();
	if (strncmp(str, "end", 3) == 0) { return -1; }
	printf("# ���ڸ� �Է��Ͻÿ� : ");
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