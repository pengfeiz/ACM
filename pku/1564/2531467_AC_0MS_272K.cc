#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 14
int a[MAX],n,m;
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
			if(c[i])
			{
				if(q)
					printf("+");
				q=1;
				printf("%d",a[i]);
			}
		}
		printf("\n");
		f=false;
		return;
	}
	if(x==m)
		return;
	c[x]=true;
	dosth(x+1,p+a[x]);
	c[x]=false;
	while(a[x]==a[x+1]&&x<m-1)
		x++;
	dosth(x+1,p);
}

int main()
{
	int i;
	while(scanf("%d%d",&n,&m),n||m)
	{
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
