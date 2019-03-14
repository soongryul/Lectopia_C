#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void flush();
int inputInt(char *);
void cal(int *, int *);

int main()
{
	int win = 0, draw = 0;
	srand((unsigned int)time(NULL));
	cal(&win, &draw);
	printf("게임 결과 : %d승 %d무\n", win, draw);
	return 0;
}

void flush()
{
	while (getchar() != '\n');
	return;
}

int inputInt(char *msg)
{
	int rt, res;
	while (1) {
		printf(msg);
		res = scanf("%d", &rt);
		if (res == 1 && rt >= 1 && rt <= 3) { flush(); break; }
		else { printf("재 입력\n"); flush(); }
	}
	return rt;
}

void cal(int *w, int *d)
{
	int me, com;
	while (1) {
		com = rand() % (3) + 1;
		me = inputInt("# 바위는 1, 가위는 2, 보는 3 중에서 선택하세요 : ");		
		if (com == me) {
			*d += 1;
			(com == 1) ? printf("당신은 바위 선택, 컴퓨터는 바위 선택 : 비겼습니다.\n") :
				(com == 2) ? printf("당신은 가위 선택, 컴퓨터는 가위 선택 : 비겼습니다.\n") :
				printf("당신은 보 선택, 컴퓨터는 보 선택 : 비겼습니다.\n");
		}
		else {
			if (com == 1) {
				if (me == 2) { printf("당신은 가위 선택, 컴퓨터는 바위 선택 : 당신이 졌습니다.\n"); break; }
				else { *w += 1; printf("당신은 보 선택, 컴퓨터는 바위 선택 : 이겼습니다.\n");
				}
			}
			else if (com == 2) {
				if (me == 1) { *w += 1; printf("당신은 바위 선택, 컴퓨터는 가위 선택 : 이겼습니다.\n");
				}
				else { printf("당신은 보 선택, 컴퓨터는 가위 선택 : 당신이 졌습니다.\n"); break; }
			}
			else {
				if (me == 1) { printf("당신은 바위 선택, 컴퓨터는 보 선택 : 당신이 졌습니다.\n"); break; }
				else { *w += 1; printf("당신은 가위 선택, 컴퓨터는 보 선택 : 이겼습니다.\n");
				}
			}
		}
	}
	return;
}