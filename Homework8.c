#include <stdio.h>

int main()
{
	int a, b, c;
	printf("역사, 문학, 예능 점수를 입력하세요 : ");
	scanf("%d %d %d", &a, &b, &c);
	printf("총점은 %d이고 평균은 %.2lf\n ", a + b + c, (double)(a + b + c) / 3);

	return 0;
}