#include <stdio.h>

void flush();
int menu();
char openFan(char fan);
char offFan(char fan);
char reverseFan(char fan);
void display(char fan);

int main()
{
	char fan = 0x00, menu_num = 0;
	while (menu_num != 4) {
		menu_num = menu();
		switch (menu_num) {
		case 1:
			fan = openFan(fan);
			display(fan);
			break;
		case 2:
			fan = offFan(fan);
			display(fan);
			break;
		case 3:
			fan = reverseFan(fan);
			display(fan);
			break;
		}
	}
	return 0;
}

void flush()
{
	while (getchar() != '\n');
	return;
}

int menu()
{
	int res, rt;
	while (1) {
		printf("1. ȯǳ�� ���� / 2. ȯǳ�� �ݱ� / 3. ȯǳ�� ��ü ��ȯ / 4. ���� : ");
		res = scanf("%d", &rt);
		if (res == 1 && rt >= 1 && rt <= 4) { flush(); break; }
		else { flush(); }
	}
	return rt;
}

char openFan(char fan)
{
	char compare = 0x01;
	printf("-------------------------------------------------\n");
	printf("          Fan ���� �۾� ���� ȭ��\n");
	printf("-------------------------------------------------\n");
	int fan_n, res;
	while (1) {
		printf("* OPEN�� FAN ��ȣ�� �Է��Ͻÿ�(1-8) : ");
		res = scanf("%d", &fan_n);
		if (res == 1 && fan_n >= 1 && fan_n <= 8) { flush(); break; }
		else { flush(); }
	}
	compare = compare << fan_n - 1;
	fan = fan | compare;
	return fan;
}

char offFan(char fan)
{
	char compare=0xbf;
	printf("-------------------------------------------------\n");
	printf("          Fan �ݱ� �۾� ���� ȭ��\n");
	printf("-------------------------------------------------\n");
	int fan_n, res;
	while (1) {
		printf("* CLOSE�� FAN ��ȣ�� �Է��Ͻÿ�(1-8) : ");
		res = scanf("%d", &fan_n);
		if (res == 1 && fan_n >= 1 && fan_n <= 8) { flush(); break; }
		else { flush(); }
	}
	if (fan_n != 8) { compare = compare >> 7 - fan_n; }
	else { compare = 0x7f; }
	fan = fan & compare;
	return fan;
}

char reverseFan(char fan)
{
	printf("-------------------------------------------------\n");
	printf("          Fan ��ü ��ȯ �۾� ���� ȭ��\n");
	printf("-------------------------------------------------\n");
	printf("��ü FAN�� ���°� ��ȯ�Ǿ����ϴ�. (ON, OFF ���� �ڹٲ�)\n");
	fan = ~fan;
	return fan;
}

void display(char fan)
{
	unsigned char compare = 0x80;
	char res;
	printf("-------------------------------------------------\n");
	printf("8��FAN\t7��FAN\t6��FAN\t5��FAN\t4��FAN\t3��FAN\t2��FAN\t1��FAN\n");
	for (int i = 0; i < 8; i++) {
		res = compare & fan;
		if (res == 0) { printf("OFF  \t"); }
		else { printf("ON  \t"); }
		compare = compare >> 1;
	}
	printf("\n");
	printf("-------------------------------------------------\n");
	return;
}