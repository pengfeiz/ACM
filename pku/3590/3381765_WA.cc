#include <iostream>
#include <algorithm>
using namespace std;


int a[201];
__int64 maxx[201];
int b[201][201],pp[201];

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

void find(int x,int m,int q,int nn)
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
	if(t>maxx[nn])
	{
		pp[nn]=p;
		for(i=0;i<pp[nn];i++)
			b[nn][i]=a[i];
		maxx[nn]=t;
	}
	for(i=x;c[i]<=m-c[x]&&i<24;i++)
	{
		find(i,m-c[x],q+1,nn);
	}
}


int main()
{
	int t,n,i,j,k,ppp;
	for(n=1;n<=100;n++)
	{
		maxx[n]=0;
		if(n>1)
		{
			maxx[n]=maxx[n-1];
			pp[n]=pp[n-1];
			for(i=0;i<pp[n];i++)
				b[n][i]=b[n-1][i];
			b[n][pp[n]++]=1;
		}
		if(n==1)
		{
			pp[1]=1;
			maxx[1]=1;
			b[1][0]=1;
		}
		else if(n==2)
		{
			pp[2]=1;
			maxx[2]=2;
			b[2][0]=2;
		}
		else if(n==3)
		{
			pp[3]=1;
			maxx[3]=3;
			b[3][0]=3;
		}
		else if(n==4)
		{
			pp[4]=1;
			maxx[4]=4;
			b[4][0]=4;
		}
		else
		{
			for(i=0;c[i]<=n&&i<24;i++)
			{
				find(i,n,0,n);
			}
			/*
			printf("%d\n",pp);
			for(i=0;i<pp;i++)
				printf("%d ",b[i]);
			printf("\n\n");
			*/
			ppp=pp[n];
			for(i=0;i<pp[n];i++)
				for(j=0;j<pp[n];j++)
					if(i!=j&&b[n][i]%b[n][j]==0)
					{
						for(k=1;k<b[n][j];k++)
							b[n][ppp++]=1;
						b[n][j]=1;
					}
			pp[n]=ppp;
			sort(b[n],b[n]+pp[n]);
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%I64d",maxx[n]);
		k=0;
		for(i=0;i<pp[n];i++)
		{
	//		printf(" %d",b[n][i]);
			for(j=1;j<=b[n][i];j++)
			{
				printf(" %d",j%b[n][i]+k+1);
			}
			k+=b[n][i];
		}
		printf("\n");
	}
	return 0;
}