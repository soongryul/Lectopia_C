#include <stdio.h>

int main()
{
	int money;
	while (1) {
		printf("현재 당신의 소유 금액 입력 : ");
		scanf("%d", &money);
		if (getchar() == '\n' && money > 0) {
			for (int i = 1; i <= (money - 1100) / 500; i++) {
				for (int j = 1; j <= (money - (500 * i + 400)) / 700; j++) {
					for (int k = 1; k <= (money - (500 * i + 700 * j)) / 400; k++) {
						if (money - (500 * i + 700 * j + 400 * k) == 0) { printf("크림빵(%d 개), 새우깡(%d 봉지), 콜라(%d 병)\n", i, j, k); }
					}
				}
			}
			printf("어떻게 구입하시겠습니까?\n\n");
		}
		else { break; }
	}
	return 0;
}