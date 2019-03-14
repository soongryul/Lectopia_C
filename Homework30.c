#include <stdio.h>

int main()
{
	int num, res;
	unsigned int compare = 0x80000000;
	printf("* 10진수 정수를 입력하시오 : ");
	scanf("%d", &num);
	printf("%d(10) = ", num);
	while (compare != 0) {
		res = num & compare;
		if (res==0) { printf("0"); }
		else { printf("1"); }
		compare = compare >> 1;
	}
	printf("(2)\n");
	return 0;
}