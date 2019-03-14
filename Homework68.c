#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define RESIDENT_NUMBER_LENGTH 13 //주민등록번호 길이

int availabilityCheck(char *resident_number);
int checkLengthCharacter(char *resident_number);
int checkDate(char *resident_number);
int checkIdentification(char *resident_number);
int checkGender(char *resident_number);
int checkYear(int year);
int check(int y, int m, int d);

int main()
{
	//테스트할 주민등록번호 저장 배열
	char resident_number[][20] = { "0402291000008", "870401102321", "00031541949179", "0003154194917", "801203#201122", "7804155328845", "7804150328840", "9612241068382", "9902292194322", "0230174326176", "8811391042219", "8100122042213", "8112002042213", "9210101069415", "0802294012345", "8806311069417", "8807311069418" };
	int i, count;
	//검사할 주민등록번호의 개수 계산
	count = sizeof(resident_number) / sizeof(resident_number[0]);
	for (i = 0; i < count; i++) {
		if (availabilityCheck(resident_number[i]) == TRUE) {
			printf("(+) 주민번호 %s 는(은) 유효한 번호입니다.\n", resident_number[i]);
		}
		else {
			printf("(-) 주민번호 %s 는(은) 유효하지 않은 번호입니다.\n", resident_number[i]);
		}
	}
	return 0;
}

int availabilityCheck(char *resident_number)
{
	int check;
	check = checkLengthCharacter(resident_number) + checkDate(resident_number) + checkIdentification(resident_number) + checkGender(resident_number);
	if (check == 4) { return TRUE; }
	else { return FALSE; }
}
int checkLengthCharacter(char *resident_number)
{
	if (strlen(resident_number) == 13) {
		for (int i = 0; i < 13; i++) {
			if (resident_number[i]<'0' || resident_number[i]>'9') { return FALSE; }
		}
		return TRUE;
	}
	else { return FALSE; }
}
int checkDate(char *resident_number)
{
	int year, month, day;
	if (resident_number[6] == '1' || resident_number[6] == '2') {
		year = 1900 + ((resident_number[0] - '0') * 10) + (resident_number[1] - '0');
		month = ((resident_number[2] - '0') * 10) + (resident_number[3] - '0');
		day = ((resident_number[4] - '0') * 10) + (resident_number[5] - '0');
	}
	else if (resident_number[6] == '3' || resident_number[6] == '4') {
		year = 2000 + ((resident_number[0] - '0') * 10) + (resident_number[1] - '0');
		month = ((resident_number[2] - '0') * 10) + (resident_number[3] - '0');
		day = ((resident_number[4] - '0') * 10) + (resident_number[5] - '0');
	}
	else { return FALSE; }
	if (check(year, month, day)) { return TRUE; }
	else { return FALSE; }
}
int checkIdentification(char *resident_number)
{
	int sum = 0;
	for (int i = 0; i < 12; i++) {
		sum += resident_number[i] - '0';
	}
	if (sum % 10 == resident_number[12] - '0') { return TRUE; }
	else { return FALSE; }
}
int checkGender(char *resident_number)
{
	if (resident_number[6] >= '1' && resident_number[6] <= '4') { return TRUE; }
	else { return FALSE; }
}
int checkYear(int year)
{
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 4 == 0) { return TRUE; }
			else { return FALSE; }
		}
		else { return TRUE; }
	}
	else { return FALSE; }
}
int check(int y, int m, int d)
{
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (y > 1899 && m > 0 && m < 13 && d > 0) {
		if (checkYear(y) == 1) { month[1] += 1; }
		if (d > month[m - 1]) { return FALSE; }
	}
	else { return FALSE; }
	return TRUE;
}