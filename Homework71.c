#include <stdio.h>

int inputInt(int *);
void sort(int *);
int checkRuns(int *);
int checkTripletes(int *);

int main()
{
	int user[6];
	while (inputInt(user)) {
		//printf("checkRus = %d\n", checkRuns(user));
		//printf("checkTripletes = %d\n", checkTripletes(user));
		if (checkRuns(user) || checkTripletes(user)) {
			for (int i = 0; i < 6; i++) {
				printf("%2d", user[i]);
			}
			printf("는 Maybe Win입니다.\n\n");
		}
		else {
			for (int i = 0; i < 6; i++) {
				printf("%2d", user[i]);
			}
			printf("는 Maybe Win이 아닙니다.\n\n");
		}
	}
	return 0;
}

int inputInt(int *user)
{
	int res;
	printf("# 0 ~ 9 사이의 숫자 6개를 입력 하시오 : ");
	res = scanf("%d %d %d %d %d %d", &user[0], &user[1], &user[2], &user[3], &user[4], &user[5]);
	if (res == 6) {
		for (int i = 0; i < 6; i++) {
			if (user[i] < 0 || user[i] > 9) { return 0; }
		}
	}
	else { return 0; }
	return 1;
}
void sort(int *ary)
{
	int temp;
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 6; j++) {
			if (ary[i] > ary[j]) {
				temp = ary[i];
				ary[i] = ary[j];
				ary[j] = temp;
			}
		}
	}
}
int checkRuns(int *user)
{
	int temp[6];
	int cnt = 0;
	for (int i = 0; i < 6; i++) {
		temp[i] = user[i];
	}
	sort(temp);
	for (int i = 0; i < 5; i++) {
		if (temp[i] + 1 == temp[i + 1]) { cnt++; }
		else { cnt = 0; }
		if (cnt >= 2) { return 1; }
	}
	return 0;
}
int checkTripletes(int *user)
{
	int temp[6];
	int cnt = 0;
	for (int i = 0; i < 6; i++) {
		temp[i] = user[i];
	}
	sort(temp);
	/*for (int i = 0; i < 6; i++) {
		printf("temp[%d] = %d\n", i, temp[i]);
	}*/
	for (int i = 0; i < 5; i++) {
		if (temp[i] == temp[i + 1]) { cnt++; }
		else { cnt = 0; }
	//	printf("cnt = %d\n", cnt);
		if (cnt >= 2) { return 1; }
	}
	return 0;
}