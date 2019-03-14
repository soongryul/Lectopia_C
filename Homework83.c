#include <stdio.h>
#include <string.h>

typedef struct _Dic {
	char word[20];
	char mean[80];
	int len;
}Dic;

void flush();
int menuInput();
void wordInput(Dic *ary, int *num);
void wordOutput(Dic *ary, int num);
void wordSearch(Dic *ary, int num);
void wordDelete(Dic *ary, int *num);

int main()
{
	Dic ary[10];
	int menu_num, ary_num = 0;
	while (1) {
		menu_num = menuInput();
		if (menu_num == 5) { break; }
		switch (menu_num) {
		case 1:wordInput(ary, &ary_num); break;
		case 2:wordOutput(ary, ary_num); break;
		case 3:wordSearch(ary, ary_num); break;
		case 4:wordDelete(ary, &ary_num); break;
		}
	}
	return 0;
}
void flush() { while (getchar() != '\n'); }
int menuInput()
{
	int rt;
	printf("=====================*MENU*=====================\n");
	printf("1. �Է��ϱ�\n2. ����ϱ�\n3. �˻��ϱ�\n4. �����ϱ�\n5. ����\n\n");
	while (1) {
		printf("�Է� : ");
		scanf("%d", &rt);
		if (getchar() == '\n' && rt >= 1 && rt <= 5) { break; }
		else { fflush(stdin); printf("�� �Է�\n"); }
	}
	printf("================================================\n");
	return rt;
}
void wordInput(Dic *ary, int *num)
{
	char temp_word[20];
	char temp_mean[80];
	for (int i = *num; i < 10; i++) {
		printf("# �ܾ �Է��Ͻÿ� : ");
		scanf("%s", temp_word);
		flush();
		if (strcmp(temp_word, "end") == 0) { *num = i; break; }
		else {
			strcpy(ary[i].word, temp_word);
			ary[i].len = strlen(temp_word);
		}
		printf("# ���� �Է��Ͻÿ� : ");
		fgets(temp_mean, 80, stdin);
		temp_mean[strlen(temp_mean) - 1] = '\0';
		if (strcmp(temp_mean, "end") == 0) { *num = i; break; }
		else { strcpy(ary[i].mean, temp_mean); }
		printf("\n");
	}
}
void wordOutput(Dic *ary, int num)
{
	char temp_mean[52];
	for (int i = 0; i < num; i++) {
		if (strlen(ary[i].mean) <= 50) {
			printf("%2d. %s(%2d) : %s\n", i + 1, ary[i].word, ary[i].len, ary[i].mean);
		}
		else {
			strncpy(temp_mean, ary[i].mean, sizeof(temp_mean));
			temp_mean[51] = '~';
			temp_mean[52] = '\0';
			printf("%2d. %s(%2d) : %s\n", i, ary[i].word, ary[i].len, temp_mean);
		}
	}
	printf("\n");
}
void wordSearch(Dic *ary, int num)
{
	char temp_word[20];
	char temp_mean[52];
	while (1) {
		printf("# ã�� �ܾ �Է��Ͻÿ� : ");
		scanf("%s", temp_word);
		if (strcmp(temp_word, "end") == 0) { break; }
		for (int i = 0; i < num; i++) {
			if (strcmp(temp_word, ary[i].word) == 0) {
				if (strlen(ary[i].mean) <= 50) {
					printf("�ܾ��� �� : %s\n\n", ary[i].mean);
				}
				else {
					strncpy(temp_mean, ary[i].mean, sizeof(temp_mean));
					temp_mean[51] = '~';
					temp_mean[52] = '\0';
					printf("�ܾ��� �� : %s\n\n", temp_mean);
				}
				break;
			}
			if (i == num - 1) { printf("Not found!!!\n\n"); }
		}
	}
}
void wordDelete(Dic *ary, int *num)
{
	char temp_word[20];
	char check;
	while (1) {
		printf("# ������ �ܾ �Է��Ͻÿ� : ");
		scanf("%s", temp_word);
		flush();
		if (strcmp(temp_word, "end") == 0) { break; }
		for (int i = 0; i < *num; i++) {
			if (strcmp(temp_word, ary[i].word) == 0) {
				printf("# ������ �����Ͻðڽ��ϱ�? (y/n) : ");
				scanf("%c", &check);
				flush();
				if (check == 'y') {
					(*num)--;
					for (int j = i; j < *num; j++) {
						ary[j].len = ary[j + 1].len;
						strcpy(ary[j].word, ary[j + 1].word);
						strcpy(ary[j].mean, ary[j + 1].mean);
					}
					ary[*num].len = 0;
					ary[*num].word[0] = '\0';
					ary[*num].mean[0] = '\0';
					printf("�����Ǿ����ϴ�.\n\n");
				}
				else { printf("������ ��ҵǾ����ϴ�.\n\n"); }
				break;
			}
			if (i == num - 1) { printf("Not found!!!\n\n"); }
		}
	}
}