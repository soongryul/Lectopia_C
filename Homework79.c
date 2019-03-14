#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>

char *myAlloc(int col);
void myDelete(char *cp);
void sort(char **);

int main()
{
	char *p[5];
	char temp[100];
	for (int i = 0; i < 5; i++) {
		printf("# ¹®ÀÚ¿­ %d : ", i + 1);
		fgets(temp, sizeof(temp), stdin);
		temp[strlen(temp) - 1] = '\0';
		p[i] = myAlloc(strlen(temp));
		strcpy(p[i], temp);
	}
	sort(p);
	for (int i = 0; i < 5; i++) {
		printf("%d. %s\n", i + 1, p[i]);
	}
	return 0;
}

char *myAlloc(int col)
{
	char *cp;
	cp = (char *)malloc(sizeof(char)*col);
	assert(cp != NULL);
	return cp;
}
void myDelete(char *cp)
{
	free(cp);
}
void sort(char **p)
{
	char *cp;
	for (int i = 0; i < 4; i++) {
		if (strcmp(p[i], p[i + 1]) > 0) {
			cp = p[i];
			p[i] = p[i + 1];
			p[i + 1] = cp;
		}
	}
}