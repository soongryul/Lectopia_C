#include <stdio.h>

void flush();
void inputRange(int *num1, int *num2);
char input_eo(int num1, int num2);
void print(char eo, int num1, int num2);

int main()
{
	int first_number, last_number;
	char eo;
	inputRange(&first_number, &last_number);
	eo = input_eo(first_number, last_number);
	print(eo, first_number, last_number);

	return 0;
}

void flush()
{
	while (getchar() != '\n');
	return;
}

void inputRange(int *num1, int *num2)
{
	int res;
	while (1) {
		printf("# 시작 값을 입력하시오 : ");
		res = scanf("%d", num1);
		if (res == 1 && *num1 > 0) { flush(); break; }
		else { flush(); }
	}
	res = 0;
	while (1) {
		printf("# 끝 값을 입력하시오 : ");
		res = scanf("%d", num2);
		if (res == 1 && *num2 > *num1) { flush(); break; }
		else { flush(); }
	}
	return;
}

char input_eo(int num1, int num2)
{
	char rt;
	int res;
	while (1) {
		printf("* %d ~ %d 까지의 짝수의 합을 구할까요? 홀수의 합을 구할까요? (짝수:e/홀수:o) : ", num1, num2);
		res = scanf("%c", &rt);
		if (res == 1 && (rt == 'e' || rt == 'o')) { break; }
		else { flush(); }
	}
	return rt;
}

void print(char eo, int num1, int num2)
{
	int sum = 0;
	if (eo == 'e') {
		printf("%d ~ %d 까지의 짝수(", num1, num2);
		if (num1 % 2 == 0) {
			for (int i = num1; i <= num2; i += 2) {
				printf("%d ", i);
				sum += i;
			}
		}
		else {
			for (int i = num1 + 1; i <= num2; i += 2) {
				printf("%d ", i);
				sum += i;
			}
		}
	}
	else {
		printf("%d ~ %d 까지의 홀수(", num1, num2);
		if (num1 % 2 != 0) {
			for (int i = num1; i <= num2; i += 2) {
				printf("%d ", i);
				sum += i;
			}
		}
		else {
			for (int i = num1 + 1; i <= num2; i += 2) {
				printf("%d ", i);
				sum += i;
			}
		}
	}
	printf("\b)의 합은 %d 입니다.\n", sum);
	return;
}