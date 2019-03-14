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
		printf("1. 환풍구 열기 / 2. 환풍구 닫기 / 3. 환풍구 전체 전환 / 4. 종료 : ");
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
	printf("          Fan 열기 작업 실행 화면\n");
	printf("-------------------------------------------------\n");
	int fan_n, res;
	while (1) {
		printf("* OPEN할 FAN 번호를 입력하시오(1-8) : ");
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
	printf("          Fan 닫기 작업 실행 화면\n");
	printf("-------------------------------------------------\n");
	int fan_n, res;
	while (1) {
		printf("* CLOSE할 FAN 번호를 입력하시오(1-8) : ");
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
	printf("          Fan 전체 전환 작업 실행 화면\n");
	printf("-------------------------------------------------\n");
	printf("전체 FAN의 상태가 전환되었습니다. (ON, OFF 상태 뒤바뀜)\n");
	fan = ~fan;
	return fan;
}

void display(char fan)
{
	unsigned char compare = 0x80;
	char res;
	printf("-------------------------------------------------\n");
	printf("8번FAN\t7번FAN\t6번FAN\t5번FAN\t4번FAN\t3번FAN\t2번FAN\t1번FAN\n");
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