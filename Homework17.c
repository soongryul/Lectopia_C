#include <stdio.h>
void print(char *, double, char);
void flush();

int main()
{
	char name[20], s;
	double cm;
	printf("# �����Է� : ");
	gets(name);
	printf("# Ű �Է�(cm����) : ");
	scanf("%lf", &cm);
	flush();
	printf("# ���� �Է�(M/F) : ");
	scanf("%c", &s);
	print(name, cm, s);
	return 0;
}

void print(char *a, double b, char c)
{
	switch (c) {
	case 'M':
		printf("%s���� Ű�� %.2lfcm�̰� �����Դϴ�.\n", a, b);
		break;
	case 'F':
		printf("%s���� Ű�� %.2lfcm�̰� �����Դϴ�.\n", a, b);
		break;
	}
	return;
}

void flush()
{
	while (getchar() != '\n');
	return;
}