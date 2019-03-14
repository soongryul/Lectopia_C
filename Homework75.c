#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

void inputCom(int *);
void inputUser(int *);
int checkBall(int *, int *);
int checkStrike(int *, int *);
void print(int, int);

int main()
{
	int com[4];
	int user[4];
	int ballCnt, strikeCnt = 0, checkCnt = 1;
	srand((unsigned int)time(NULL));
	inputCom(com);
	/*for (int i = 0; i < 4; i++) {
		printf("%2d", com[i]);
	}*/
	printf("\n\n");
	while (strikeCnt!=4) {
		printf("# %dÂ÷ : ", checkCnt++);
		inputUser(user);
		ballCnt = checkBall(com, user);
		strikeCnt = checkStrike(com, user);
		print(ballCnt, strikeCnt);
	}
	return 0;
}

void inputCom(int *com)
{
	int res;
	int i = 0, j;
	res = rand() % 10;
	com[i] = res;
	i++;
	while (i != 4) {
		res = rand() % 10;
		for (j = i - 1; j >= 0; j--) {
			if (res == com[j]) { break; }
		}
		if (j == -1) { com[i] = res; i++; }
	}
}
void inputUser(int *user)
{
	int res, i;
	char temp[4];
	for (int i = 0; i < 4; i++) {
		temp[i] = getche();
		if (temp[i]<'0' || temp[i]>'9') { 
			printf("\b");
			i--;
		}
		else { printf(" "); }
	}
	for (int i = 0; i < 4; i++) {
		user[i] = temp[i] - '0';
	}
}
int checkBall(int *com, int *user)
{
	int ballCnt = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 3; j >= 0; j--) {
			if (i != j && com[i] == user[j]) { ballCnt++; }
		}
	}
	return ballCnt;
}
int checkStrike(int *com, int *user)
{
	int strikeCnt = 0;
	for (int i = 0; i < 4; i++) {
		if (com[i] == user[i]) { strikeCnt++; }
	}
	return strikeCnt;
}
void print(int ballCnt, int strikeCnt)
{
	if (strikeCnt == 4) {
		printf("\tOK!!!\n");
	}
	else if (ballCnt || strikeCnt) {
		printf("\t%dS  %dB\n", strikeCnt, ballCnt);
	}
	else {
		printf("\tNO!\n");
	}
}