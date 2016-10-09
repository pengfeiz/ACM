#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 14
int a[MAX],b[MAX],n,m;
bool f;
bool c[MAX];

bool com(int a,int b)
{return a>b;}

void dosth(int x,int p)
{
	int i,q;
	if(p>n)
		return;
	if(p==n)
	{
		q=0;
		for(i=0;i<m;i++)
		{
			if(c[i]&&b[q++]!=a[i])
				break;
		}
		if(i==m)
			return;
		q=0;
		for(i=0;i<m;i++)
		{
			if(c[i])
			{
				if(q)
					printf("+");
				b[q++]=a[i];
				printf("%d",a[i]);
			}
			else
				b[i]=-1;
		}
		printf("\n");
		f=false;
	}
	if(x==m)
		return;
	c[x]=true;
	dosth(x+1,p+a[x]);
	c[x]=false;
	dosth(x+1,p);
}

int main()
{
	int i;
	while(scanf("%d%d",&n,&m),n||m)
	{
		memset(b,0xff,sizeof(b));
		memset(c,0,sizeof(c));
		f=true;
		printf("Sums of %d:\n",n);
		for(i=0;i<m;i++)
			scanf("%d",&a[i]);
		a[m]=-1;
		sort(a,a+m,com);
		dosth(0,0);
		if(f)
			printf("NONE\n");
	}
	return 0;
}
