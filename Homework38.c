#include <stdio.h>

int main()
{
	int num, sum = 0, temp = 1, temp1 = 0, temp2;
	printf("�Ǻ���ġ ������ �� ���� �Է��Ͻÿ� : ");
	scanf("%d", &num);
	if (num == 1) { printf("%d\n", temp); }
	else {
		for (int i = 1; i <= num; i++) {
			printf("%d", temp);
			sum += temp;
			temp2 = temp;
			temp += temp1;
			temp1 = temp2;
			if (i != num) { printf(" + "); }
			else { printf(" = %d\n", sum); }
		}
	}
	return 0;
}