#include <stdio.h>

int main()
{
	int money;
	while (1) {
		printf("���� ����� ���� �ݾ� �Է� : ");
		scanf("%d", &money);
		if (getchar() == '\n' && money > 0) {
			for (int i = 1; i <= (money - 1100) / 500; i++) {
				for (int j = 1; j <= (money - (500 * i + 400)) / 700; j++) {
					for (int k = 1; k <= (money - (500 * i + 700 * j)) / 400; k++) {
						if (money - (500 * i + 700 * j + 400 * k) == 0) { printf("ũ����(%d ��), �����(%d ����), �ݶ�(%d ��)\n", i, j, k); }
					}
				}
			}
			printf("��� �����Ͻðڽ��ϱ�?\n\n");
		}
		else { break; }
	}
	return 0;
}