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
	freopen("in.txt","r",stdin);
	int n,i,j,g;
	double k,maxx,tt,tp;
	while(scanf("%d",&n)!=EOF)
	{
		tt=tp=0.0;
		g=0;
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf",&b[i].a,&b[i].b);
			b[i].k=b[i].a/b[i].b;
			tt+=b[i].a;
			tp+=b[i].b;
		}
		sort(b,b+n,com);
		for(i=1;i<n;i++)
		{
			tt-=b[i-1].a;
			tp-=b[i-1].b;
			k=tt/tp;
			maxx=-1e10;
			if(n>5000)
			{
				if(i>3000)
					j=i-3000;
				else
					j=0;
			}
			else
				j=0;
			for(;j<i;j++)
				if(b[j].a-b[j].b*k>maxx)
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
 