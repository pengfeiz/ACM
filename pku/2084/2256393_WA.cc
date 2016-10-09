#include <iostream>
using namespace std;

#define MAXX 10000
#define MAX 201

int n;
struct gao
{
	int n;
	int num[50];
}a[MAX][MAX];


void add(gao &a,gao b)
{
	int i;
	if(a.n<b.n)
		a.n=b.n;
	for(i=1;i<=a.n;i++)
		a.num[i]+=b.num[i];
	for(i=1;i<a.n;i++)
	{
		a.num[i+1]+=a.num[i]/MAXX;
		a.num[i]%=MAXX;
	}
	while(a.num[a.n]>=MAXX)
	{
		a.n++;
		a.num[n]=a.num[n-1]/MAXX;
		a.num[n-1]%=MAXX;
	}
}

void mul(gao &b,gao a1,gao a2)
{
	int i,j;
	b.n=a1.n+a2.n;
	memset(b.num,0,sizeof(b.num));
	for(i=1;i<=a1.n;i++)
		for(j=1;j<=a2.n;j++)
			b.num[i+j-1]+=a1.num[i]*a2.num[j];
	for(i=1;i<b.n;i++)
	{
		b.num[i+1]+=b.num[i]/MAXX;
		b.num[i]%=MAXX;
	}
	while(b.num[b.n]==0)
		b.n--;
}


int main()
{
	int i,j,k;
	gao b;
	memset(a,0,sizeof(a));
	n=200;
	for(i=1;i<n;i++)
		a[i][i+1].n=a[i][i+1].num[1]=1;
	for(k=3;k<n;k+=2)
		for(i=1;i<=n-k;i++)
		{
			add(a[i][i+k],a[i+2][i+k]);
			for(j=3;j<k;j+=2)
			{
				mul(b,a[i+1][i+j-1],a[i+j+1][i+k]);
				add(a[i][i+k],b);
			}
			add(a[i][i+k],a[i+1][i+k-1]);
		}
	while(scanf("%d",&n),n+1)
	{
		printf("%d",a[1][n*2].num[a[1][2*n].n]);
		for(i=a[1][2*n].n-1;i>0;i--)
			printf("%03d",a[1][n*2].num[i]);
		printf("\n");
	}
	return 0;
}
			

