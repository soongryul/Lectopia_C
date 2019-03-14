#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>

#define flush() while(getchar()!='\n')

int inputCount(char *msg);
int inputArray(int *ary, int count);
int check(char *str, int *tpArray, int count);
int *intAlloc(int);
int countCheck(int *ip1, int *ip2, int count);

int main()
{
	int *ip1, *ip2;
	int count, count2;
	while (count = inputCount("* 입력할 숫자의 개수 : ")) {
		ip1 = intAlloc(count);
		ip2 = intAlloc(count);
		inputArray(ip1, count);
		/*for (int i = 0; i < count; i++) {
			printf("ip[%d] = %d\n", i, ip1[i]);
		}*/
		count2 = countCheck(ip1, ip2, count);
		printf("서로 다른 수의 개수 : %d  <- 위에 입력된 숫자 중 ", count2);
		for (int i = 0; i < count2; i++) {
			printf("%d, ", ip2[i]);
		}
		printf("\b\b 이렇게 %d개가 서로 다른 수가 됨\n\n", count2);
		free(ip1);
		free(ip2);
	}

	return 0;
}

int inputCount(char *msg)
{
	int rt;
	printf(msg);
	if (scanf("%d", &rt) == 1 && rt >= 2 && rt <= 1000) { flush(); return rt; }
	else { flush(); return 0; }
}

int inputArray(int *ary, int count)
{
	char str[2100];
	printf("* 숫자 입력 : ");
	fgets(str, sizeof(str), stdin);
	str[strlen(str) - 1] = '\0';
	return check(str, ary, count);
}
int check(char *str, int *tpArray, int count)
{
	int length = strlen(str);
	int aryCnt = 0, temp, cnt = 0, tp_sum = 0, neg = 0;
	for (int i = 0; i < length; i++) {
		if (aryCnt == count) { break; }
		if (str[i] >= '0' && str[i] <= '9') {
			cnt++;
			temp = str[i] - '0';
			if (neg) { temp -= (temp * 2); }
			if (cnt > 1) { tp_sum *= 10; }
			tp_sum += temp;
		}
		else if (str[i] == '-') { neg = 1; }
		else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A'&&str[i] <= 'Z')) { return 0; }
		else { tpArray[aryCnt] = tp_sum; cnt = 0; tp_sum = 0; aryCnt++; neg = 0; }
	}
	tpArray[aryCnt] = tp_sum;
	return aryCnt;
}
int *intAlloc(int count)
{
	int *ip;
	ip = (int *)malloc(sizeof(int) * count);
	assert(ip != NULL);
	return ip;
}
int countCheck(int *ip1, int *ip2, int count)
{
	int cnt = 1;
	ip2[0] = ip1[0];
	for (int i = 1; i < count; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (ip1[i] == ip1[j]) { break; }
			else if (ip1[i] != ip1[j] && j == 0) { ip2[cnt] = ip1[i]; cnt++; }
		}
	}
	return cnt;
}