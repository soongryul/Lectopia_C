#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <assert.h>
#include <conio.h>

int menu();
int inputSize();
void bingoPrint1(int **user, int size);
void bingoPrint2(int **user, int **com, int size);
int **myAlloc(int size);
void myDelete(int **ip, int size);
void setNum(int **ip, int size);
void swap(int *temp, int a, int b);
int userErase(int **user, int size);
int comErase(int **com, int size);
int erase(int **ip, int size, int rub);
int checkOver(int **ip, int size, int rub);
int checkLine(int **ip, int size);

int main()
{
	srand((unsigned int)time(NULL));
	int **user;
	int **com;
	int menu_num, size, checkUser, checkCom;
	int ur, cr;
	while (1) {
		menu_num = menu();
		if (menu_num == 3) { break; }
		else if (menu_num == 2) {
			printf("\n사용자 vs 컴퓨터 대전 빙고게임을 시작합니다.\n\n");
			size = inputSize();
			printf("사용자 빙고게임판 내용을 생성중입니다.\n");
			printf("컴퓨터 빙고게임판 내용을 생성중입니다.\n\n");
			user = myAlloc(size);
			setNum(user, size);
			com = myAlloc(size);
			setNum(com, size);
			while (1) {
				bingoPrint2(user, com, size);
				ur = userErase(user, size);
				cr = comErase(user, size);
				erase(user, size, ur);
				erase(user, size, cr);
				erase(com, size, cr);
				erase(com, size, ur);
				checkUser = checkLine(user, size);
				checkCom = checkLine(com, size);
				if (checkUser || checkCom) {
					printf("BINGO!!! BINGO!!!\n"); 
					break;
				}
			}
			if (checkUser && checkCom) {
				printf("DRAW!!!\n계속하시려면 아무키나 누르세요\n\n\n");
			}
			else if (checkUser) {
				printf("User WIN!!!\n계속하시려면 아무키나 누르세요\n\n\n");
			}
			else if (checkCom) {
				printf("Computer WIN!!!\n계속하시려면 아무키나 누르세요\n\n\n");
			}
			myDelete(user, size);
			myDelete(com, size);
			checkUser = 0;
			checkCom = 0;
			getch();
		}
		else if (menu_num == 1) {
			printf("\n연습용 빙고게임을 시작합니다.\n\n");
			size = inputSize();
			user = myAlloc(size);
			setNum(user, size);
			while (1) {
				bingoPrint1(user, size);
				erase(user, size, userErase(user, size));
				if (checkLine(user, size)) { break; }
			}
			printf("BINGO!!! BINGO!!!\n계속하시려면 아무키나 누르세요\n\n\n");
			myDelete(user, size);
			getch();
		}
	}
	return 0;
}

int menu()
{
	int num;
	printf("=====================*MENU*=======================\n");
	printf("1. 연습 게임(개인 연습용)\n");
	printf("2. 대전 게임(컴퓨터와 대전용)\n");
	printf("3. 종료\n\n");
	while (1) {
		printf("# 메뉴 선택 : ");
		scanf("%d", &num);
		if (getchar() == '\n' && num >= 1 && num <= 3) { break; }
		else { fflush(stdin); printf("재 입력\n"); }
	}
	return num;
}
int inputSize()
{
	int size;
	while (1) {
		printf("# 빙고판의 가로, 세로 크기를 입력(3 ~ 9) : ");
		scanf("%d", &size);
		if (getchar() == '\n' && size >= 3 && size <= 9) { break; }
		else { fflush(stdin); printf("재 입력\n"); }
	}
	printf("\n\n");
	return size;
}
void bingoPrint1(int **user, int size)
{
	for (int i = 0; i < size; i++) {
		printf("[");
		for (int j = 0; j < size; j++) {
			if(user[i][j]==0){ printf("%3c", 'X'); }
			else{ printf("%3d", user[i][j]); }
		}
		printf(" ]\n");
	}
	printf("\n\n");
}
void bingoPrint2(int **user, int **com, int size) {
	printf(" [user]");
	for (int i = 0; i < size * 3; i++) {
		printf(" ");
	}
	printf(" [computer]\n");
	for (int i = 0; i < size; i++) {
		printf("[");
		for (int j = 0; j < size; j++) {
			if (user[i][j] == 0) { printf("%3c", 'X'); }
			else { printf("%3d", user[i][j]); }
		}
		printf(" ]\t[");
		for (int j = 0; j < size; j++) {
			if (com[i][j] == 0) { printf("%3c", 'X'); }
			else { printf("%3d", com[i][j]); }
		}
		printf(" ]\n");
	}
	printf("\n\n");
}
int **myAlloc(int size)
{
	int **p;
	p = (int **)malloc(sizeof(int *) * size);
	assert(p != NULL);
	for (int i = 0; i < size; i++) {
		p[i] = (int *)malloc(sizeof(int) * size);
		assert(p[i] != NULL);
	}
	return p;
}
void myDelete(int **ip, int size)
{
	for (int i = 0; i < size; i++) {
		free(ip[i]);
	}
	free(ip);
}
void setNum(int **ip, int size)
{
	int *temp;
	int a, b;
	temp = (int *)malloc(sizeof(int) * (size * size));
	for (int i = 0; i < (size*size); i++) {
		temp[i] = i + 1;
	}
	for (int i = 0; i < (size * size); i++) {
		a = rand() % (size * size);
		b = rand() % (size * size);
		while (a == b) {
			b = rand() % (size * size);
		}
		swap(temp, a, b);
	}
	for (int i = 0, index = 0; i < size; i++) {
		for (int j = 0; j < size; j++, index++) {
			ip[i][j] = temp[index];
		}
	}
}
void swap(int *temp, int a, int b)
{
	int tp;
	tp = temp[a];
	temp[a] = temp[b];
	temp[b] = tp;
}
int userErase(int **user, int size)
{
	int rub;
	while (1) {
		printf("# 지울 숫자 입력(1 ~ %d) : ", size*size);
		scanf("%d", &rub);
		if (getchar() == '\n' && rub >= 1 && rub <= (size*size) && checkOver(user, size, rub)) { break; }
		else { fflush(stdin); printf("* 이미 지워진 숫자거나 잘못 입력하셨습니다.\n"); }
	}
	printf("\n");
	return rub;
}
int comErase(int **com, int size)
{
	int random;
	while (1) {
		random = rand() % (size*size) + 1;
		if (checkOver(com, size, random)) { break; }
	}
	printf("# 컴퓨터가 선택한 숫자는 (%d)입니다.\n\n", random);
	return random;
}
int erase(int **ip, int size, int rub)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (ip[i][j] == rub) { ip[i][j] = 0; return 1; }
		}
	}
	return 0;
}
int checkOver(int **ip, int size, int rub)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (ip[i][j] == rub) { return 1; }
		}
	}
	return 0;
}
int checkLine(int **ip, int size)
{
	int temp1 = 0, temp2 = 0, count = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (ip[i][j] == 0) { temp1++; }
			if (ip[j][i] == 0) { temp2++; }
		}
		if (temp1 == size) { count++; }
		if (temp2 == size) { count++; }
		temp1 = 0;
		temp2 = 0;
	}
	for (int i = 0; i < size; i++) {
		if (ip[i][i] == 0) { temp1++; }
		if (ip[i][size - i - 1] == 0) { temp2++; }
	}
	if (temp1 == size) { count++; }
	if (temp2 == size) { count++; }
	if (count >= size) { return 1; }
	else { return 0; }
}