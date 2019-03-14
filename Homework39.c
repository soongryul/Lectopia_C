#include <stdio.h>

int main()
{
	int day, day_cnt = 0, sum = 0;
	printf("* 기사의 근무일 수를 입력하시오 : ");
	scanf("%d", &day);
	for (int i = 1; ; i++) {
		for (int j = 0; j < i; j++) {
			if (day_cnt == day) { break; }
			sum += i;
			day_cnt++;
		}
		if (day_cnt == day) { break; }
	}
	printf("근무일 : %d 일 / 총 금화 수 : %d 개\n", day, sum);
	return 0;
}