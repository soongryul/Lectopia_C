#include <stdio.h>
void printAge(int a);
void printHeight(double h);

int main()
{
	char name[20] = "�ּ���";
	int age = 24;
	double height = 169;

	printf("���� : %s\n", name);
	printAge(age);
	printHeight(height);

	return 0;
}

void printAge(int a) {
	printf("���� : %d\n", a);
	return;
}
void printHeight(double h) {
	printf("Ű : %f\n", h);
	return;
}