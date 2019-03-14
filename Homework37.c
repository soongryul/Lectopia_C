#include <stdio.h>

int main()
{
	for (int i = 1; i <= 100; i++) {
		if (i % 15 == 0) { printf("%d\t", i); }
		else if (i % 3 == 0) { printf("*\t"); }
		else if (i % 5 == 0) { printf("#\t"); }
		else { printf("%d\t", i); }
		if (i % 10 == 0) { printf("\n"); }
	}
	return 0;
}