#include <stdio.h>
void printAge(int a);
void printHeight(double h);

int main()
{
	char name[20] = "최성률";
	int age = 24;
	double height = 169;

	printf("성명 : %s\n", name);
	printAge(age);
	printHeight(height);

	return 0;
}

void printAge(int a) {
	printf("나이 : %d\n", a);
	return;
}
void printHeight(double h) {
	printf("키 : %f\n", h);
	return;
}