#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
#define MAX 10001
#define MAX2 1001

bool a[MAX];
int b[MAX2],n,m,d,t;
bool c[MAX2];

int maxx(int a,int b)
{return a>b?a:b;}

bool judge()
{
	int i,tt=0;
	tt=b[t+n-1];
	for(i=t+n-2;i>=maxx(t+n-d,n);i--)
	{
		tt+=b[i];
		if(!a[tt])
			return true;
	}
	return false;
}

bool solve()
{
	int i;
	if(t>=2&&judge())
		return false;
	if(t==m-n+1)
		return true;
	for(i=n;i<=m;i++)
		if(!c[i])
		{
			c[i]=true;
			b[t+n]=i;
			t++;
			if(solve())
				return true;
			t--;
			c[i]=false;
		}
	return false;
}

int main()
{
	int i,k;
	memset(a,0,sizeof(a));
	for(k=2;k<MAX;k++)
		for(i=2;i<=sqrt(k*1.0);i++)
			if(k%i==0)
			{
				a[k]=true;
				break;
			}
	while(scanf("%d%d%d",&n,&m,&d),n||m||d)
	{
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		t=0;
		if(solve())
		{
			for(i=n;i<m;i++)
				printf("%d,",b[i]);
			printf("%d\n",b[m]);
		}
		else
			printf("No anti-prime sequence exists.\n");
	}
	return 0;
}
		
