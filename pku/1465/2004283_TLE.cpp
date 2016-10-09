#include <iostream>
#include <fstream>
using namespace std;
#define MAX 5000
int t[10],n;
int pow(int p,int x)
{
	int i,q=p;
	for(i=0;i<x;i++)
	{
		q*=10;
		q%=n;
	}
	return q;
}
int dosth(int a[],int x,int tt)
{
	int i,j,b[MAX],q;
	if(tt>10)
		return -1;
	for(i=1;i<10;i++)
		if(t[i]==1)
			for(j=0;j<n;j++)
				if(a[j]==1)
					if((pow(i,x)+j)%n==0)
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
					b[(pow(i,x)+j)%n]=1;
	}
	if(memcmp(a,b,sizeof(b))==0)
		return -1;
	q=dosth(b,x+1,tt+1);
	if(q==-1)
		return -1;
	for(i=0;i<10;i++)
	{
		if(t[i]==1)
			for(j=0;j<n;j++)
				if(a[j]==1)
					if((pow(i,x)+j)%n==q)
					{
						printf("%d",i);
						return j;
					}
	}
	return -1;
}

int main()
{
	int m,p,i;
	while(cin>>n)
	{
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
		a[0]=1;
		if(dosth(a,0,0)==-1)
			printf("0");
		printf("\n");
	}
	return 0;
}
