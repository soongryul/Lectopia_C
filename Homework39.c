#include <stdio.h>

int main()
{
	int day, day_cnt = 0, sum = 0;
	printf("* ����� �ٹ��� ���� �Է��Ͻÿ� : ");
	scanf("%d", &day);
	for (int i = 1; ; i++) {
		for (int j = 0; j < i; j++) {
			if (day_cnt == day) { break; }
			sum += i;
			day_cnt++;
		}
		if (day_cnt == day) { break; }
	}
	printf("�ٹ��� : %d �� / �� ��ȭ �� : %d ��\n", day, sum);
	return 0;
}