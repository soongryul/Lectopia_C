#include <stdio.h>
#include <string.h>

void flush();
int inputStr(char *str);
int check(char *str);
void print(char *str, int sum);

int main()
{
	char str[50];
	while (inputStr(str)) {
		print(str, check(str));
	}
	return 0;
}

void flush()
{
	while (getchar() != '\n');
}
int inputStr(char *str)
{
	printf("# 문장을 입력하시오 : ");
	scanf("%s", str);
	flush();
	if (strcmp(str, "end") == 0) { return 0; }
	else { return 1; }
}
int check(char *str)
{
	int length = strlen(str);
	int sum = 0, temp, cnt = 0, tp_sum = 0;
	for (int i = 0; i < length; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			cnt++;
			temp = str[i] - '0';
			if (cnt > 1) { tp_sum *= 10; }
			tp_sum += temp;
			//printf("temp=%d\n", temp);
			//printf("tp_sum=%d\n", tp_sum);
			//printf("cnt=%d\n", cnt);
		}
		else { sum += tp_sum; cnt = 0; tp_sum = 0; }
	}
	sum += tp_sum;
	return sum;
}
void print(char *str, int sum)
{
	printf("\"%s\" 내의 총 숫자는 [%d]입니다.\n\n", str, sum);
}