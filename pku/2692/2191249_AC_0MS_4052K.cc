#include <iostream>
#include <math.h>
using namespace std;
#define MAX 1000

int a[MAX][MAX+1],d[30];
bool b[30];

struct gao
{
	char s[80];
}c[30];

int n,m;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,p,min,tt;
	memset(b,0,sizeof(b));
	scanf("%d",&m);
	getchar();
	for(i=0;i<m;i++)
		gets(c[i].s);
	n=0;
	while(scanf("%d",&p)!=EOF)
	{
		p--;
		a[n][1]=p;
		for(i=2;i<=m;i++)
		{	
			scanf("%d",&p);
			p--;
			a[n][i]=p;
		}
		n++;
	}
	for(i=0;i<n;i++)
	{
		a[i][0]=1;
		a[i][n+1]=m+1;
	}
	tt=n;
	memset(d,0,sizeof(d));
	while(1)
	{
		for(i=0;i<n;i++)
		{
			if(!b[a[i][a[i][0]]])
				d[a[i][a[i][0]]]++;
		}
		min=9999;
		for(i=0;i<m;i++)
			if((double)d[i]>double(tt)/2.0)
			{
				printf("%s\n",c[i].s);
				return 0;
			}
		for(i=0;i<m;i++)
			if(d[i]<min&&!b[i])
				min=d[i];
		for(i=0;i<m;i++)
			if(d[i]==min)
				b[i]=true;
		for(i=0;i<n;i++)
		{
			while(b[a[i][a[i][0]]])
				a[i][0]++;
			if(a[i][0]>n)
				tt--;
		}
		memset(d,0,sizeof(d));
		if(tt==0)
			break;
	}
	for(i=0;i<m;i++)
	{
		if(b[i])
			printf("%s\n",c[i].s);
	}
	return 0;
}





		