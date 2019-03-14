#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void flush();
int inputInt(char *);
int print(int);

int main()
{
	int r_num;
	srand((unsigned int)time(NULL));
	r_num = rand() % (100) + 1;
	printf("%d\n", r_num);
	printf("���~ �¾Ҵ�~~~ ��ī��ī~~ %d ��° ���� ���߼̽��ϴ�.\n", print(r_num));
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
		if (res == 1 && rt >= 1 && rt <= 100) { flush(); break; }
		else { printf("�� �Է�\n"); flush(); }
	}
	return rt;
}

int print(int r_num)
{
	int num, count = 0, temp1 = 0, temp2 = 100;
	while (1) {
		num = inputInt("# ���ڸ� �Է��Ͻÿ� : ");
		count++;
		if (num != r_num) {
			if (num > r_num) { temp2 = num; }
			else { temp1 = num; }
			printf("%d ���ٴ� ũ�� %d ���ٴ� �۽��ϴ�.\n", temp1, temp2);
		}
		else { break; }
	}
	return count;
}