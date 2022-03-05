/*
 * main.c
 *
 *  Created on: Mar 1, 2022
 *      Author: Makram Maher
 */


#include<stdio.h>

struct SComplexNumber{
	float m_real;
	float m_imag;
};

struct SComplexNumber readComplex(void);
struct SComplexNumber addComplex(struct SComplexNumber cNum1, struct SComplexNumber cNum2);

int main(void)
{
	struct SComplexNumber cNum1,cNum2,cSum;
	printf("\nFor 1st complex number\n");
	cNum1 = readComplex();
	printf("\nFor 2nd complex number\n");
	cNum2 = readComplex();

	cSum = addComplex(cNum1, cNum2);
	printf("\nSum = %.1f + %.1f i\n", cSum.m_real, cSum.m_imag);
	return 0;
}

struct SComplexNumber addComplex(struct SComplexNumber cNum1, struct SComplexNumber cNum2)
{
	struct SComplexNumber sum;
	sum.m_real = cNum1.m_real + cNum2.m_real;
	sum.m_imag = cNum1.m_imag + cNum2.m_imag;
	return sum;
}

struct SComplexNumber readComplex(void)
{
	struct SComplexNumber cNum;
	printf("Enter real and imaginary respectively: ");
	fflush(stdout);fflush(stdin);
	scanf("%f%f", &cNum.m_real, &cNum.m_imag);
	return cNum;
}
