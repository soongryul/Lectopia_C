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
	printf("���� ��� : %d�� %d��\n", win, draw);
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
		else { printf("�� �Է�\n"); flush(); }
	}
	return rt;
}

void cal(int *w, int *d)
{
	int me, com;
	while (1) {
		com = rand() % (3) + 1;
		me = inputInt("# ������ 1, ������ 2, ���� 3 �߿��� �����ϼ��� : ");		
		if (com == me) {
			*d += 1;
			(com == 1) ? printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : �����ϴ�.\n") :
				(com == 2) ? printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : �����ϴ�.\n") :
				printf("����� �� ����, ��ǻ�ʹ� �� ���� : �����ϴ�.\n");
		}
		else {
			if (com == 1) {
				if (me == 2) { printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : ����� �����ϴ�.\n"); break; }
				else { *w += 1; printf("����� �� ����, ��ǻ�ʹ� ���� ���� : �̰���ϴ�.\n");
				}
			}
			else if (com == 2) {
				if (me == 1) { *w += 1; printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : �̰���ϴ�.\n");
				}
				else { printf("����� �� ����, ��ǻ�ʹ� ���� ���� : ����� �����ϴ�.\n"); break; }
			}
			else {
				if (me == 1) { printf("����� ���� ����, ��ǻ�ʹ� �� ���� : ����� �����ϴ�.\n"); break; }
				else { *w += 1; printf("����� ���� ����, ��ǻ�ʹ� �� ���� : �̰���ϴ�.\n");
				}
			}
		}
	}
	return;
}