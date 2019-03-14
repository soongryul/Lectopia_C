#include <stdio.h>

char *ustrchr(char *str, char ch);
char *ustrcat(char *s1, char *s2);
char *ustrstr(char *s1, char *s2);
void ustrcpy(char *s1, char *s2);
size_t ustrlen(char *str);
int ustrcmp(char *s1, char *s2);

int main()
{
	char *u;
	char str1[20] = "Hello";
	char str2[20] = "Bye";
	char str3[20] = "llo";
	char ch = 'l';
	//u = ustrchr(str1, ch);
	//printf("str1[2]의 주소 = %u\n", &str1[2]);
	//printf("찾음 = %u\n", u);
	//u = ustrcat(str1, str2);
	//printf("이어붙이기 = %s\n", u);
	//u = ustrstr(str1, str3);
	//printf("찾음 : %u\n", u);
	//printf("str1[2]의 주소 : %u\n", &str1[2]);
	//u = ustrstr(str1, str2);
	//printf("못찾음 : %u\n", u);
	//ustrcpy(str1, str2);
	//printf("ustrcpy = %s\n", str1);
	//printf("str1의 길이 : %d\tstr2의 길이 : %d\tstr의 길이 : %d\n", ustrlen(str1), ustrlen(str2), ustrlen(str3));
	//printf("str1과 str2의 비교 = %d\n", ustrcmp(str1, str2));
	//printf("str1과 str3의 비교 = %d\n", ustrcmp(str1, str3));
	//printf("str2과 str3의 비교 = %d\n", ustrcmp(str2, str3));
	//printf("str1과 str1의 비교 = %d\n", ustrcmp(str1, str1));
	return 0;
}

char *ustrchr(char *str, char ch)
{
	int i = 0;
	while (1) {
		if (str[i] == ch) { return str + i; }
		else if (str[i] == '\0') { return NULL; }
		else { i++; }
	}
}
char *ustrcat(char *s1, char *s2)
{
	int i = 0, j = 0;
	while (1) {
		if (s1[i] == '\0') { break; }
		else { i++; }
	}
	while (1) {
		s1[i] = s2[j];
		if (s2[j] == '\0') { break; }
		else { i++; j++; }
	}
	return s1;
}
char *ustrstr(char *s1, char *s2)
{
	int i = 0, j = 0;
	while (1) {
		if (s1[i] == s2[j]) {
			if (s2[j] == '\0') { return s1 + (i - j); }
			i++;
			j++;
			
		}
		else if (s1[i] == '\0') {
			return NULL;
		}
		else { i++; j = 0; }
	}
}
void ustrcpy(char *s1, char *s2)
{
	int i = 0;
	while (1) {
		if (s2[i] == '\0') { break; }
		else { i++; }
	}
	for (int j = 0; j <= i; j++) {
		s1[j] = s2[j];
	}
}
size_t ustrlen(char *str)
{
	int i = 0;
	while (1) {
		if (str[i] == '\0') { return i; }
		else { i++; }
	}
}
int ustrcmp(char *s1, char *s2)
{
	int i = 0;
	while (1) {
		if (s1[i] == '\0' && s2[i] == '\0') { return 0; }
		else if (s1[i] == '\0') { return -1; }
		else if (s2[i] == '\0') { return 1; }
		if (s1[i] > s2[i]) { return 1; }
		else if (s1[i] < s2[i]) { return -1; }
		else if (s1[i] == s2[i]) { i++; }
	}
}