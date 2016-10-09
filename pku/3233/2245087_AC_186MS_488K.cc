#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAX 30
int a[MAX][MAX],c[MAX][MAX];
int ans[MAX][MAX];
int n,k,m;


void mul(int p[MAX][MAX],int q[MAX][MAX])
{
	int i,j,k;
	int w[MAX][MAX]={0};
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			for(k=0;k<n;k++)
			{
				w[i][j]+=p[k][j]*q[i][k];
				if(w[i][j]>=m)
					w[i][j]%=m;
			}
	memcpy(p,w,sizeof(w));
}


void add(int p[MAX][MAX],int q[MAX][MAX])
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			p[i][j]+=q[i][j];
			p[i][j]%=m;
		}
}


void dosth(int k,int a[MAX][MAX])
{
	int i,j;
	if(k==1||k==0)
		return;
	int no[MAX][MAX]={0};
	int aa[MAX][MAX];
	memcpy(aa,a,sizeof(aa));
	for(i=0;i<n;i++)
		no[i][i]=1;
	if(k%2==0)
	{
		add(no,a);
		mul(aa,a);
		dosth(k/2,aa);
		mul(ans,no);
		return;
	}
	dosth(k-1,a);
	mul(ans,a);
	add(ans,no);
}


void build()
{
	int i,j;
	scanf("%d%d%d",&n,&k,&m);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	memset(ans,0,sizeof(ans));
	for(i=0;i<n;i++)
		ans[i][i]=1;
	memcpy(c,a,sizeof(a));
}


void printff()
{
	int i,j;
	if(k>0)
		mul(ans,c);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j)
				printf(" ");
			printf("%d",ans[i][j]);
		}
		printf("\n");
	}
}


int main()
{
	build();
	dosth(k,a);
	printff();
	return 0;
}
