#include <stdio.h>
#include <string.h>

int inputArray(int *ary);
int outputMax(int *ary, int dataCnt);
int outputMin(int *ary, int dataCnt);
void print(int *ary, int max, int min);
int check(char *str, int *tpArray);

int main()
{
	int ary[100];
	int dataCnt;
	int max, min;
	while (dataCnt = inputArray(ary)) {
		max = outputMax(ary, dataCnt);
		min = outputMin(ary, dataCnt);
		print(ary, max, min);
	}
	
	return 0;
}

int inputArray(int *ary)
{
	char str[200];
	printf("* 정수입력 : ");
	fgets(str, sizeof(str), stdin);
	str[strlen(str) - 1] = '\0';
	return check(str, ary);
}
int check(char *str, int *tpArray)
{
	int length = strlen(str);
	int aryCnt = 0, temp, cnt = 0, tp_sum = 0, neg = 0;
	for (int i = 0; i < length; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			cnt++;
			temp = str[i] - '0';
			if (neg) { temp -= (temp * 2); }
			if (cnt > 1) { tp_sum *= 10;}
			tp_sum += temp;
		}
		else if (str[i] == '-') { neg = 1; }
		else if ((str[i] >= 'a'&&str[i] <= 'z') || (str[i] >= 'A'&&str[i] <= 'Z')) { return 0; }
		else { tpArray[aryCnt] = tp_sum; cnt = 0; tp_sum = 0; aryCnt++; neg = 0; }
	}
	return aryCnt;
}
int outputMax(int *ary, int dataCnt)
{
	int max = ary[0], index;
	for (int i = 0; i < dataCnt; i++) {
		if (ary[i] > max) { max = ary[i]; index = i; }
	}
	return index;
}
int outputMin(int *ary, int dataCnt)
{
	int min = ary[0], index;
	for (int i = 0; i < dataCnt; i++) {
		if (ary[i] < min) { min = ary[i]; index = i; }
	}
	return index;
}
void print(int *ary, int max, int min)
{
	printf("최댓값 : %d(index:%d)  /  최소값 : %d(index:%d)\n\n", ary[max], max, ary[min], min);
}