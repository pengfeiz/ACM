#include <iostream>
#include <fstream>
using namespace std;
#define MAX 5000
int t[10],n,c[MAX],s;
int dosth(int a[])
{
	int b[MAX];
	int i,j,q;
	for(i=0;i<10;i++)
	{
		if(t[i]==1)
		{
			for(j=1;j<n;j++)
				if(a[j]==1&&(j*10+i)%n==0)
				{
					c[s++]=i;
					return j;
				}
		}
	}
	memset(b,0,sizeof(b));
	for(i=0;i<10;i++)
	{
		if(t[i]==1)
		for(j=0;j<n;j++)
		{
			if(a[j]==1)
				b[(j*10+i)%n]=1;
		}
	}
	if(memcmp(a,b,sizeof(b))==0)
		return -1;
	q=dosth(b);
	if(q==-1)
		return -1;
	for(i=0;i<10;i++)
		if(t[i]==1)
		{
			for(j=0;j<n;j++)
				if(a[j]==1&&(j*10+i)%n==q)
				{
					c[s++]=i;
					return j;
				}	
		}
	return -1;
}

int main()
{
	freopen("input.txt","r",stdin);
	int m,p,i,q;
	while(scanf("%d",&n)!=EOF)
	{
		s=0;
		memset(c,0,sizeof(c));
		int a[MAX];
		scanf("%d",&m);
		memset(a,0,sizeof(a));
		memset(t,0,sizeof(t));
		for(i=0;i<m;i++)
		{
			scanf("%d",&p);
			t[p]=1;
		}
		if(n==0)
		{
			printf("0\n");
			continue;
		}
		for(i=0;i<10;i++)
			if(t[i]==1)
			{
				a[i%n]=1;
				if(i%n==0&&i)
				{
					printf("%d\n",i);
					break;
				}
			}
		if(i<10)
			continue;
		q=dosth(a);
		if(q==-1)
			printf("0\n");
		else
		{
			printf("%d",q);
			for(i=s-1;i>=0;i--)
				printf("%d",c[i]);
			printf("\n");
		}
	}
	return 0;
}
