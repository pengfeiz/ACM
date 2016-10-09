#include <stdio.h>
#include <math.h>

int main ()
{
	int noh=0;
	double X[1010],Y[1010];
	int F[1010],T[1010],V[1010];
	int *f,*t,*a;
	int fc,tc,i,j,steps;
	int speed,time;
	scanf("%d%d", &speed, &time);
	while(scanf("%lf%lf",&X[noh],&Y[noh])!=EOF)
		noh++;
	f=F;
	f[0]=0;
	fc=1;
	V[0]=1;
	t=T;
	tc=0;
	steps=0;
	while(fc)
	{
		for(i=0;i<fc;i++)
			for(j =0;j<noh;j++)
			{
				if(!V[j] && sqrt((X[f[i]]-X[j])*(X[f[i]]-X[j])+(Y[f[i]]-Y[j])*(Y[f[i]]-Y[j]))/speed<time*60)
				{
					if(j==1) 
						goto A;
					V[j]=1;
					t[tc++]=j;
				}
			}
		steps++;
		a=f;
		f=t;
		t=a;
		fc=tc; 
		tc=0;
	}
	printf("No.\n");
	return 0;
A: printf("Yes, visiting %d other holes.\n", steps);
	return 0;
}