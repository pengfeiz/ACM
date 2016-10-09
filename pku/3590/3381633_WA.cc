#include <iostream>
#include <algorithm>
using namespace std;


int a[201];
__int64 maxx;
int b[201],pp;

int c[24]={3,5,7,11,13,17,19,23,29,31,
			37,41,43,47,53,59,61,67,71,73,
			79,83,89,97};
int f[9]={0,1,2,4,8,16,32,64,128};

int gcd(__int64 a,__int64 b)
{
	__int64 c;
	while(a%b)
	{
		c=b;
		b=a%b;
		a=c;
	}
	return b;
}

void find(int x,int m,int q)
{
	int i,j,k,p=q;
	__int64 t;
	t=1;
	for(i=0;i<9;i++)
		if(f[i]>(m-c[x]))
			break;
	i--;
	j=f[i];
	k=m-c[x]-j;
	a[p++]=c[x];
	if(k)
	{
		a[p++]=k;
	}
	if(j)
		a[p++]=j;
	for(i=0;i<p;i++)
		t=t*(a[i]/gcd(t,(__int64)a[i]));
	if(t>maxx)
	{
		pp=p;
		for(i=0;i<pp;i++)
			b[i]=a[i];
		maxx=t;
	}
	for(i=x;c[i]<=m-c[x]&&i<24;i++)
	{
		find(i,m-c[x],q+1);
	}
}


int main()
{
	int t,n,i,j,k,ppp;
	scanf("%d",&t);
	while(t--)
	{
		maxx=0;
		n=t;
		scanf("%d",&n);
		if(n==1)
			printf("1 1\n");
		else if(n==2)
			printf("2 2 1\n");
		else if(n==3)
			printf("3 2 3 1\n");
		else if(n==4)
			printf("4 2 3 4 1\n");
		else
		{
			for(i=0;c[i]<=n&&i<24;i++)
			{
				find(i,n,0);
			}
			/*
			printf("%d\n",pp);
			for(i=0;i<pp;i++)
				printf("%d ",b[i]);
			printf("\n\n");
			*/
			ppp=pp;
			for(i=0;i<pp;i++)
				for(j=0;j<pp;j++)
					if(i!=j&&b[i]%b[j]==0)
					{
						for(k=1;k<b[j];k++)
							b[ppp++]=1;
						b[j]=1;
					}
			pp=ppp;
			sort(b,b+pp);
			printf("%I64d",maxx);
			n=0;
			for(i=0;i<pp;i++)
			{
			//	printf(" %d",b[i]);
				for(j=1;j<=b[i];j++)
				{
					printf(" %d",j%b[i]+n+1);
				}
				n+=b[i];
			}
			printf("\n");

		}
	}
	return 0;
}