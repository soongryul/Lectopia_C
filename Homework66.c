#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>

#define flush() while(getchar()!='\n')

int inputStr(char *);
int changeInt(char *);
void changeStr(int, char *);
char *myAlloc(int);
void myDelete(char *);

int main()
{
	int sum = 0;
	char *cp;
	char str[20];
	while(1) {
		cp = (char *)myAlloc(20);
		if (inputStr(cp) == 0) { myDelete(cp); break; }
		else {
			sum += changeInt(cp);
			//printf("sum = %d\n", sum);
			myDelete(cp);
		}
	}
	changeStr(sum, str);
	printf("\n\n총 합 : %s\n", str);
	return 0;
}

int inputStr(char *str)
{
	int length, cdt = 0;
	while (1) {
		printf("금액 입력 : ");
		scanf("%s", str);
		flush();
		length = strlen(str);
		for (int i = 0; i < length; i++, cdt++) {
			if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ',')) { printf("재 입력\n"); break; }
		}
		if (cdt == length) { break; }
	}
	if (strncmp(str, "0000", 4) == 0) { return 0; }
	else{ return 1; }
}
char *myAlloc(int num)
{
	char *p;
	p = (char *)malloc(sizeof(char) * num);
	assert(p != NULL);
	return p;
}
void myDelete(char *cp)
{
	free(cp);
}
int changeInt(char *str)
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
		else if (str[i] != ',') { sum += tp_sum; cnt = 0; tp_sum = 0; }
	}
	sum += tp_sum;
	return sum;
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