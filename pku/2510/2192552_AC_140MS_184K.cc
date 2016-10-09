#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define MAX 101
#define MAX2 1000000
int a[MAX],b[MAX],c[MAX2];
double aa[MAX],bb[MAX];
int na,nb,nc;

int main()
{
//	freopen("in.txt","r",stdin);
	char s[30];
	int i,j,t;
	double x,total,d;
	while(scanf("%s",s)!=EOF)
	{
		if(strcmp(s,"Query")==0)
		{
			scanf("%d",&t);
			c[nc++]=t;
		}
		else if(strcmp(s,"Chocolate")==0)
		{
			scanf("%d%lf",&t,&x);
			a[na]=t;
			aa[na++]=x;
		}
		else if(strcmp(s,"Coffee")==0)
		{
			scanf("%d%lf",&t,&x);
			b[nb]=t;
			bb[nb++]=x;
		}
	}
	sort(c,c+nc);
	for(i=0;i<nc;i++)
	{
		total=0.0;
		for(j=0;j<na;j++)
		{
			if(a[j]>c[i])
				continue;
			d=8*aa[j]-(c[i]-a[j])*1.0/12.0;
			if(d>0.0)
				total+=d;
		}
		for(j=0;j<nb;j++)
		{
			if(b[j]>c[i])
				continue;
			d=2*bb[j]-(c[i]-b[j])*1.0*(c[i]-b[j])/79.0;
			if(d>0.0)
				total+=d;
		}
		if(total<1.0)
			total=1.0;
		printf("%d %.1lf\n",c[i],total);
	}
	return 0;
}

