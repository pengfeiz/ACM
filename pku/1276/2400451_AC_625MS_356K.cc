#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001

bool a[MAX];
struct gao
{
	int b,c;
}x[10];
int d[MAX];
int m,n,t;

bool comp(gao a,gao b)
{return a.b<b.b;}

int main()
{
	int i,j,k,tt;
	while(scanf("%d",&m)!=EOF)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d%d",&x[i].c,&x[i].b);
		memset(a,0,sizeof(a));
		a[0]=true;
		sort(x,x+n,comp);
		t=1;
		d[0]=0;
		for(i=0;!a[m]&&i<n;i++)
		{
			tt=t;
			for(j=0;!a[m]&&j<tt;j++)
			{
				for(k=1;!a[m]&&k<=x[i].c;k++)
				{
					if(d[j]+k*x[i].b>m)
						break;
					if(!a[d[j]+k*x[i].b])
					{
						a[d[j]+k*x[i].b]=true;
						d[t++]=d[j]+k*x[i].b;
					}
				}
			}
		}
		for(i=m;i>=0;i--)
			if(a[i])
				break;
		printf("%d\n",i);
	}
	return 0;
}


