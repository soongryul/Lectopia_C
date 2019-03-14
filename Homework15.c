#include <stdio.h>
void flush();
double inputDouble(char *msg);
double BMIcalculator(double, double);
void print(double);

int main()
{
	double kg, m, bmi;
	kg = inputDouble("�����Ը� �Է��ϼ���(kg) : ");
	m = inputDouble("Ű�� �Է��ϼ���(m) : ");
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
	if(c<18.5){ printf("����� BMI�� %.1lf���� ��ü���Դϴ�.\n", c); }
	else if(c>=18.5 && c<25.0){ printf("����� BMI�� %.1lf���� ����ü���Դϴ�.\n", c); }
	else if(c>=25.0 && c<30){ printf("����� BMI�� %.1lf���� ��ü���Դϴ�.\n", c); }
	else if(c>=30 && c<40){ printf("����� BMI�� %.1lf���� ���Դϴ�.\n", c); }
	else if(c>40){ printf("����� BMI�� %.1lf���� �����Դϴ�.\n", c); }
	return;
}