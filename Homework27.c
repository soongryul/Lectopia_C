#include <stdio.h>
void flush();
int inputInt(char *);

int main()
{
	int weight;
	for (int i = 0; i != 10;) {
		weight = inputInt("# ����� ���Ը� �Է��ϼ���(���� : g) : ");
		if (weight >= 150 && weight <= 500) { i++; printf("* ���� �ް��� �� : %d\n", i); }
		else if (weight < 150) { printf("���߸��� ������ �峭���� ���ÿ�~ ^^\n"); }
		else{ printf("Ÿ���� ������ �峭���� ���ÿ�~ ^^\n"); }
	}
	printf("\n*** �ް� ������ �������ϴ�.\n");
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
		if (res == 1 && rt >= 0) { flush(); break; }
		else { printf("�� �Է�\n"); flush(); }
	}
	return rt;
}