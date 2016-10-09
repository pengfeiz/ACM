#include <iostream>
using namespace std;
#define MAX 5000
#define MAX2 100
int t[10],n,pow[MAX2];
int dosth(int a[],int x)
{
	int i,j,b[MAX],q;
	for(i=1;i<10;i++)
		if(t[i]==1)
			for(j=0;j<n;j++)
				if(a[j]==1)
					if((i*pow[x]+j)%n==0)
					{
						printf("%d",i);
						return j;
					}
	memset(b,0,sizeof(b));
	for(i=0;i<10;i++)
	{	
		if(t[i]==1)
			for(j=0;j<n;j++)
				if(a[j]==1)
					b[(i*pow[x]+j)%n]=1;
	}
	if(memcmp(a,b,sizeof(b))==0)
		return -1;
	q=dosth(b,x+1);
	if(q==-1)
		return -1;
	for(i=0;i<10;i++)
	{
		if(t[i]==1)
			for(j=0;j<n;j++)
				if(a[j]==1)
					if((i*pow[x]+j)%n==q)
					{
						printf("%d",i);
						return j;
					}
	}
	return -1;
}

int main()
{
//	freopen ("input.txt","r",stdin);
	int m,p,i;
	while((scanf("%d",&n))!=EOF)
	{
		pow[0]=1;
		int c[MAX];
		scanf("%d",&m);
		memset(c,0,sizeof(c));
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
		for(i=1;i<MAX2;i++)
			pow[i]=(pow[i-1]*10)%n;
		c[0]=1;
		if(dosth(c,0)==-1)
			printf("0");
		printf("\n");
	}
	return 0;
}
