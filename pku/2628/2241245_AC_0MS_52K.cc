#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define EPSILON 10e-10
#define M_PI 3.14159265358979323846

int t;

#define angle 2*M_PI/t

int to_the_left(int i, int j)
{
	double x1,x2,y1,y2,x3,y3,cosa;
	if(i==j)
		return 0;
	x1=cos(angle*i);
	y1=sin(angle*i);
	x2=cos(angle*j);
	y2=sin(angle*j);
	x3=x1-(y2-y1);
	y3=y1+(x2-x1);
	cosa=(-x1*(x3-x1)+-y1*(y3-y1))/(sqrt(x1*x1+y1*y1)*sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1)));
	if(cosa>EPSILON)
		return 1;
	return 0;
}

int main()
{
	int i,j,J;
	int best,current,touch,previous;
	int first=1;
	int L[51];
	while (1)
	{
		scanf("%d",&t);
		if(!t)
			break;
		if(!first)
			printf("\n");
		first=0;
		for(i=0;i<t;i++)
			scanf("%d",&L[i]);
		best=9999999;
		for(i=0;i<t;i++)
		{
			previous=i;
			current=0;
			touch=1;
			for(J=1;J<t;J++)
			{
				j=(i+J)%t;
				if(L[i]<=L[j])
				{
					if(to_the_left(previous,j))
					{
						previous=j;
						current+=L[j]-L[i];
						touch++;
					}
					else
						goto A;
				}
			}
			if(to_the_left(previous,i)&&touch>2&&current<best)
				best = current;
A:
			;
		}
		printf("%d\n", best);
	}
	return 0;
}

