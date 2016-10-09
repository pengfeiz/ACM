#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100010


int n;
struct gao
{
	int b[6];
}a[MAX];


bool com(gao a,gao b)
{
	int i;
	for(i=0;i<6;i++)
		if(a.b[i]!=b.b[i])
			return a.b[i]<b.b[i];
	return true;
}

int main()
{
	int i,j,k;
	gao p,q,w;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<6;j++)
			scanf("%d",&p.b[j]);
//			p.b[j]=rand()%1000;
		for(j=0;j<6;j++)
			q.b[j]=p.b[5-j];
		for(k=0;k<6;k++)
			w.b[k]=999999999;
		for(k=0;k<6;k++)
		{
			for(j=0;j<6;j++)
				if(w.b[j]>p.b[(j+k)%6])
					break;
			if(j<6)
			{
				for(j=0;j<6;j++)
					w.b[j]=p.b[(j+k)%6];
			}
		}
		for(k=0;k<6;k++)
			a[i].b[k]=w.b[k];
		for(k=0;k<6;k++)
			w.b[k]=999999999;
		for(k=0;k<6;k++)
		{
			for(j=0;j<6;j++)
				if(w.b[j]>q.b[(j+k)%6])
					break;
			if(j<6)
			{
				for(j=0;j<6;j++)
					w.b[j]=q.b[(j+k)%6];
			}
		}
		for(k=0;k<6;k++)
			if(a[i].b[k]>w.b[k])
				break;
		if(k<6)
		{
			for(k=0;k<6;k++)
				a[i].b[k]=w.b[k];
		}
	}
	sort(a,a+n,com);
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<6;j++)
			if(a[i].b[j]!=a[i+1].b[j])
				break;
		if(j==6)
			break;
	}
	if(i<n-1)
		printf("Twin snowflakes found.\n");
	else
		printf("No two snowflakes are alike.\n");
	return 0;
}