#include <stdio.h>
void flush();
int inputInt(char *msg);

int main()
{
	int number;
	number = inputInt("정수값을 입력하세요 : ");
	printf("입력된 값은 8진수로 %#o 입니다.\n", number);
	printf("입력된 값을 16진수로 %#x 입니다.\n", number);

	return 0;
}

void flush()
{
	while (getchar() != '\n') {}
	return;
}

int inputInt(char *msg)
{
	int rt, res;
	while (1) {
		printf("%s", msg);
		res = scanf("%d", &rt);
		if (res == 1) { break; }
		else { flush(); }
	}
	return rt;
}