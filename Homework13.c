#include <stdio.h>
#include <string.h>

int main()
{
	char f[10], s[10];
	printf("#���� �Է��ϼ��� : ");
	scanf("%s", s);
	printf("#�̸��� �Է��ϼ��� : ");
	scanf("%s", f);
	printf("%s\t%s\n", s, f);
	printf("%*d\t%*d\n", strlen(s), strlen(s), strlen(f), strlen(f));
	return 0;
}