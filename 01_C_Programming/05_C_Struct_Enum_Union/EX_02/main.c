/*
 * main.c
 *
 *  Created on: Mar 1, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>

struct SDistance{
	unsigned int m_feet;
	float m_inch;
};

struct SDistance readDistance(void);
struct SDistance sumDistance(struct SDistance dis1, struct SDistance dis2);

int main(void)
{
	struct SDistance dis1,dis2,sum;

	printf("\nEnter information for 1st distance\n");
	dis1 = readDistance();
	printf("\nEnter information for 2nd distance\n");
	dis2 = readDistance();

	sum = sumDistance(dis1, dis2);
	printf("\nSum of distance = %u\'-%.1f\"",sum.m_feet, sum.m_inch);

	return 0;
}

struct SDistance readDistance(void)
{
	struct SDistance dis;
	printf("Enter Feet:");
	fflush(stdin);fflush(stdout);
	scanf("%u", &dis.m_feet);
	printf("Enter Inch:");
	fflush(stdin);fflush(stdout);
	scanf("%f", &dis.m_inch);

	return dis;
}

struct SDistance sumDistance(struct SDistance dis1, struct SDistance dis2)
{
	struct SDistance sum;
	sum.m_feet = dis1.m_feet + dis2.m_feet;
	sum.m_inch = dis1.m_inch + dis2.m_inch;
	while(sum.m_inch >= 12)
	{
		sum.m_feet += 1;
		sum.m_inch -= 12.0;
	}
	return sum;
}
