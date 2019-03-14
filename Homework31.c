#include <stdio.h>

int getBit(int num, int i); //num ������ 2�� i�� bit���� 0�̸� 0, 1�̸� 1�� ����
int setBit(int num, int i); //num������ 2�� i�� bit���� 1�� ���� �� num�� ����
int clearBit(int num, int i); //num������ 2�� i�� bit���� 0���� ���� �� num�� ����
int clearBitsMSBthroughI(int num, int i); //���� ū Bit���� i�� ��Ʈ���� ��� 0���� ����
int clearBitsIthrough0(int num, int i); //i�� ��Ʈ ~ 0�� ��Ʈ���� ��� 0���� ����
int updateBit(int num, int i, int value); //i�� ��Ʈ�� ���� value(0 or 1)������ ����
void printBit(int num); //bit ���
int inputBit(char *msg);//bit �Է�
void flush();
int inputBitI(char *msg);
int inputBitValue(char *msg);
int inputCd(char *msg);

int main()
{
	int bit, bit_i, bit_value, cd = 1;
	bit = inputBit("10���� ������ �Է��ϼ��� : ");
	while (cd != 0) {
		printf("\n1. getBit : num ������ 2�� i�� bit���� 0�̸� 0, 1�̸� 1�� ����\n");
		printf("2. setBit : num������ 2�� i�� bit���� 1�� ���� �� num�� ����\n");
		printf("3. clearBit : num������ 2�� i�� bit���� 0���� ���� �� num�� ����\n");
		printf("4. clearBitsMSBthroughI :���� ū Bit���� i�� ��Ʈ���� ��� 0���� ����\n");
		printf("5. clearBitsIthrough0 : i�� ��Ʈ ~ 0�� ��Ʈ���� ��� 0���� ����\n");
		printf("6. updateBit : i�� ��Ʈ�� ���� value(0 or 1)������ ����\n");
		printf("7. printBit : bit���\n");
		printf("8. inputBit : ���ο� bit�Է�\n");
		printf("0. ����!\n\n");
		cd = inputCd("�ɼ��� �����ϼ��� (0 ~ 8) : ");
		printf("\n\n");
		switch (cd) {
		case 0: cd = 0; break;
		case 1:
			bit_i = inputBitI("i�� �Է��ϼ���(0 ~ 31) : ");
			printf("<<%d ����>>\n", getBit(bit, bit_i));
			break;
		case 2:
			bit_i = inputBitI("i�� �Է��ϼ���(0 ~ 31) : ");
			bit = setBit(bit, bit_i);
			break;
		case 3:
			bit_i = inputBitI("i�� �Է��ϼ���(0 ~ 31) : ");
			bit = clearBit(bit, bit_i);
			break;
		case 4:
			bit_i = inputBitI("i�� �Է��ϼ���(0 ~ 31) : ");
			bit = clearBitsMSBthroughI(bit, bit_i);
			break;
		case 5:
			bit_i = inputBitI("i�� �Է��ϼ���(0 ~ 31) : ");
			bit = clearBitsIthrough0(bit, bit_i);
			break;
		case 6:
			bit_i = inputBitI("i�� �Է��ϼ���(0 ~ 31) : ");
			bit_value = inputBitValue("value�� �Է��ϼ���(0 or 1) : ");
			bit = updateBit(bit, bit_i, bit_value);
			break;
		case 7:
			printBit(bit);
			break;
		case 8:
			bit = inputBit("10���� ������ �Է��ϼ��� : ");
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