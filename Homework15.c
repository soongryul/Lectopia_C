#include <stdio.h>
void flush();
double inputDouble(char *msg);
double BMIcalculator(double, double);
void print(double);

int main()
{
	double kg, m, bmi;
	kg = inputDouble("몸무게를 입력하세요(kg) : ");
	m = inputDouble("키를 입력하세요(m) : ");
	bmi = BMIcalculator(kg, m);
	print(bmi);

	return 0;
}

void flush()
{
	while (getchar != '\n') {}
	return;
}

double inputDouble(char *msg)
{
	int res;
	double rt;
	while (1) {
		printf("%s", msg);
		res = scanf("%lf", &rt);
		if (res == 1) { break; }
		else { flush(); }
	}
	return rt;
}

double BMIcalculator(double a, double b)
{
	return a / (b * b);
}

void print(double c)
{
	if(c<18.5){ printf("당신의 BMI는 %.1lf으로 저체중입니다.\n", c); }
	else if(c>=18.5 && c<25.0){ printf("당신의 BMI는 %.1lf으로 정상체중입니다.\n", c); }
	else if(c>=25.0 && c<30){ printf("당신의 BMI는 %.1lf으로 과체중입니다.\n", c); }
	else if(c>=30 && c<40){ printf("당신의 BMI는 %.1lf으로 비만입니다.\n", c); }
	else if(c>40){ printf("당신의 BMI는 %.1lf으로 고도비만입니다.\n", c); }
	return;
}