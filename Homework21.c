#include <stdio.h>

int main()
{
	double a, b, c, d, e;

	printf("- 1번 학생의 키는? ");
	scanf("%lf", &a);
	printf("- 2번 학생의 키는? ");
	scanf("%lf", &b);
	printf("- 3번 학생의 키는? ");
	scanf("%lf", &c);
	printf("- 4번 학생의 키는? ");
	scanf("%lf", &d);
	printf("- 5번 학생의 키는? ");
	scanf("%lf", &e);
	printf("다섯 명의 평균 키는 %.1lf cm 입니다. \n", (a + b + c + d + e) / 5);
	return 0;
}