//cow school


#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 50001


struct gao
{
	double a,b,k;
}b[MAX];

int a[MAX];


bool com(gao a,gao b)
{return a.k<b.k;}


int main()
{
	int n,st,sp,i,j,g;
	double k,maxx;
	while(scanf("%d",&n)!=EOF)
	{
		st=sp=g=0;
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf",&b[i].a,&b[i].b);
			b[i].k=b[i].a/b[i].b;
			st+=b[i].a;
			sp+=b[i].b;
		}
		sort(b,b+n,com);
		for(i=1;i<n;i++)
		{
			st-=b[i-1].a;
			sp-=b[i-1].b;
			k=st*1.0/sp;
			maxx=0.0;
			if(n>15000)
			{
				if(i>2000)
					j=i-2000;
				else
					j=0;
			}
			else
				j=0;
			for(;j<i;j++)
				if(b[j].a-b[j].b*k>maxx-1e-6)
					maxx=b[j].a-b[j].b*k;
			for(j=i;j<n;j++)
				if(b[j].a-b[j].b*k<maxx-1e-6)
					break;
			if(j<n)
				a[g++]=i;
		}
		printf("%d\n",g);
		for(i=0;i<g;i++)
			printf("%d\n",a[i]);
	}
	return 0;
}
 