#include <stdio.h>
void print(char *, double, char);
void flush();

int main()
{
	char name[20], s;
	double cm;
	printf("# 성명입력 : ");
	gets(name);
	printf("# 키 입력(cm단위) : ");
	scanf("%lf", &cm);
	flush();
	printf("# 성별 입력(M/F) : ");
	scanf("%c", &s);
	print(name, cm, s);
	return 0;
}

void print(char *a, double b, char c)
{
	switch (c) {
	case 'M':
		printf("%s씨의 키는 %.2lfcm이고 남성입니다.\n", a, b);
		break;
	case 'F':
		printf("%s씨의 키는 %.2lfcm이고 여성입니다.\n", a, b);
		break;
	}
	return;
}

void flush()
{
	while (getchar() != '\n');
	return;
}