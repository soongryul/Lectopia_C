#include <stdio.h>
#include <string.h>

void flush();
int inputInt();
void changeStr(int, char *);

int main()
{
	int num;
	char str[20];
	while (num = inputInt()) {
		changeStr(num, str);
		printf("%d -> %s\n\n", num, str);
	}
	return 0;
}

void flush()
{
	while (getchar() != '\n');
}
int inputInt()
{
	int rt;
	while (1) {
		printf("# 금액 입력 : ");
		scanf("%d", &rt);
		if (getchar() == '\n') {
			if (rt > 0) { return rt; }
			else { return 0; }
		}
		else { flush(); printf("재 입력\n"); }
	}
}
void changeStr(int num, char *str)
{
	int cnt = 0, temp = num;
	int count = 0;
	int cip = 1;
	while (temp) {
		temp /= 10;
		cnt++;
	}
	temp = num;
	for (int i = 0; i < cnt; i++) {
		cip = 1;
		temp = num;
		for (int j = i + 1; j < cnt; j++) {
			temp /= 10;
			cip *= 10;
		}
		if (i != 0 && (cnt - i) % 3 == 0) { str[count] = ','; count++; }
		str[count] = temp + '0';
		count++;
		num = num - (temp*cip);
	}
	str[count] = '\0';
}