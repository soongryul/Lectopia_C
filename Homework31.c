#include <stdio.h>

int getBit(int num, int i); //num 변수의 2의 i승 bit값이 0이면 0, 1이면 1을 리턴
int setBit(int num, int i); //num변수의 2의 i승 bit값을 1로 만든 후 num값 리턴
int clearBit(int num, int i); //num변수의 2의 i승 bit값을 0으로 만든 후 num값 리턴
int clearBitsMSBthroughI(int num, int i); //가장 큰 Bit부터 i승 비트까지 모두 0으로 지움
int clearBitsIthrough0(int num, int i); //i승 비트 ~ 0승 비트까지 모두 0으로 지움
int updateBit(int num, int i, int value); //i승 비트이 값을 value(0 or 1)값으로 변경
void printBit(int num); //bit 출력
int inputBit(char *msg);//bit 입력
void flush();
int inputBitI(char *msg);
int inputBitValue(char *msg);
int inputCd(char *msg);

int main()
{
	int bit, bit_i, bit_value, cd = 1;
	bit = inputBit("10진수 정수를 입력하세요 : ");
	while (cd != 0) {
		printf("\n1. getBit : num 변수의 2의 i승 bit값이 0이면 0, 1이면 1을 리턴\n");
		printf("2. setBit : num변수의 2의 i승 bit값을 1로 만든 후 num값 리턴\n");
		printf("3. clearBit : num변수의 2의 i승 bit값을 0으로 만든 후 num값 리턴\n");
		printf("4. clearBitsMSBthroughI :가장 큰 Bit부터 i승 비트까지 모두 0으로 지움\n");
		printf("5. clearBitsIthrough0 : i승 비트 ~ 0승 비트까지 모두 0으로 지움\n");
		printf("6. updateBit : i승 비트이 값을 value(0 or 1)값으로 변경\n");
		printf("7. printBit : bit출력\n");
		printf("8. inputBit : 새로운 bit입력\n");
		printf("0. 종료!\n\n");
		cd = inputCd("옵션을 선택하세요 (0 ~ 8) : ");
		printf("\n\n");
		switch (cd) {
		case 0: cd = 0; break;
		case 1:
			bit_i = inputBitI("i를 입력하세요(0 ~ 31) : ");
			printf("<<%d 리턴>>\n", getBit(bit, bit_i));
			break;
		case 2:
			bit_i = inputBitI("i를 입력하세요(0 ~ 31) : ");
			bit = setBit(bit, bit_i);
			break;
		case 3:
			bit_i = inputBitI("i를 입력하세요(0 ~ 31) : ");
			bit = clearBit(bit, bit_i);
			break;
		case 4:
			bit_i = inputBitI("i를 입력하세요(0 ~ 31) : ");
			bit = clearBitsMSBthroughI(bit, bit_i);
			break;
		case 5:
			bit_i = inputBitI("i를 입력하세요(0 ~ 31) : ");
			bit = clearBitsIthrough0(bit, bit_i);
			break;
		case 6:
			bit_i = inputBitI("i를 입력하세요(0 ~ 31) : ");
			bit_value = inputBitValue("value를 입력하세요(0 or 1) : ");
			bit = updateBit(bit, bit_i, bit_value);
			break;
		case 7:
			printBit(bit);
			break;
		case 8:
			bit = inputBit("10진수 정수를 입력하세요 : ");
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

int inputBit(char *msg)
{
	int rt, res;
	while (1) {
		printf(msg);
		res = scanf("%d", &rt);
		if (res == 1) { flush(); break; }
		else { flush(); }
	}
	return rt;
}

int inputBitI(char *msg)
{
	int rt, res;
	while (1) {
		printf(msg);
		res = scanf("%d", &rt);
		if (res == 1 && rt >= 0 && rt <= 31) { flush(); break; }
		else { flush(); }
	}
	return rt;
}

int inputBitValue(char *msg)
{
	int rt, res;
	while (1) {
		printf(msg);
		res = scanf("%d", &rt);
		if (res == 1 && (rt == 0 || rt == 1)) { flush(); break; }
		else { flush(); }
	}
	return rt;
}

int inputCd(char *msg)
{
	int rt, res;
	while (1) {
		printf(msg);
		res = scanf("%d", &rt);
		if (res == 1 && rt >= 0 && rt <= 8) { flush(); break; }
		else { flush(); }
	}
	return rt;
}

void printBit(int num)
{
	int res;
	unsigned int compare = 0x80000000;
	printf("%d(10) = ", num);
	while (compare != 0) {
		res = num & compare;
		if (res == 0) { printf("0"); }
		else { printf("1"); }
		compare = compare >> 1;
	}
	printf("(2)\n");
	return;
}

int getBit(int num, int i)
{
	int res, compare = 0x00000001;
	compare = compare << i;
	res = compare & num;
	if (res == compare) { return 1; }
	else { return 0; }
}

int setBit(int num, int i)
{
	int res, compare = 0x00000001;
	compare = compare << i;
	res = num | compare;
	return res;
}

int clearBit(int num, int i)
{
	int res, compare = 0xbfffffff;
	if (i != 31) { compare = compare >> 30 - i; }
	else { compare = 0x7fffffff; }
	res = num & compare;
	return res;
}

int clearBitsMSBthroughI(int num, int i)
{
	int res;
	unsigned int compare = 0x7fffffff;
	compare = compare >> 31 - i;
	res = num & compare;
	return res;
}

int clearBitsIthrough0(int num, int i)
{
	int res, compare = 0xfffffffe;
	compare = compare << i;
	res = num & compare;
	return res;
}

int updateBit(int num, int i, int value)
{
	int res;
	switch (value) {
	case 0:res = clearBit(num, i); break;
	case 1:res = setBit(num, i); break;
	}
	return res;
}