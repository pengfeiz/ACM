#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 200001

struct gao
{
	int n,root;
}a[MAX];


struct he
{
	int i,j,sum;
}b[MAX];


int n,t;
int c[MAX],sum[MAX];


bool comp(gao a,gao b)
{return a.n<b.n;}


int getroot(int x)
{
	int root;
	if(x==a[x].root)
		return x;
	root=getroot(a[x].root);
	sum[x]+=sum[root];
	a[x].root=root;
	return root;
}


int main()
{
	int i,x,y,ans,xx;
	gao q;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d%d%d",&b[i].i,&b[i].j,&b[i].sum);
		for(i=0;i<n;i++)
		{
			c[2*i]=b[i].i;
			c[2*i+1]=b[i].j;
		}
		sort(c,c+2*n);
		c[2*n]=-1;
		t=0;
		for(i=0;i<2*n;i++)
		{
			if(c[i]!=c[i+1])
			{
				t++;
				a[t].n=c[i];
			}
		}
		a[0].n=0;
		for(i=0;i<=t;i++)
		{
			a[i].root=i;
			sum[i]=0;
		}
		for(i=0;i<n;i++)
		{
			if(b[i].i>b[i].j)
				swap(b[i].i,b[i].j);
			q.n=b[i].i;
			x=lower_bound(a+1,a+t+1,q,comp)-a;
			q.n=b[i].j;
			y=lower_bound(a+1,a+t+1,q,comp)-a;
			xx=getroot(x-1);
			x=getroot(x);
			y=getroot(y);
			if(x==y)
			{
				ans=sum[b[i].j]-sum[b[i].i-1];
				if(ans==b[i].sum)
					printf("Accept\n");
				else
					printf("Bug Detected %d\n",ans);
				continue;
			}
			if(xx==y)
			{
				ans=sum[b[i].j]-sum[b[i].i-1];
				if(ans==b[i].sum)
					printf("Accept\n");
				else
					printf("Bug Detected %d\n",ans);
				continue;
			}
			else if(x>y)
			{
				if(x==b[i].i)
				{
					a[x].root=y;
					sum[x]=sum[b[i].i]-b[i].sum-sum[b[i].j];
					printf("Accept\n");
				}
				else
				{
					a[x-1].root=y;
					sum[x-1]=sum[b[i].i]-b[i].sum-sum[b[i].j];
					printf("Accept\n");
				}
			}
			else
			{
				if(y!=b[i].j)
				{
					a[y-1].root=x;
					sum[y-1]=b[i].sum+sum[b[i].i]-sum[b[i].j];
					printf("Accept\n");
				}
				else
				{
					a[y].root=x;
					sum[y]=b[i].sum+sum[b[i].i]-sum[b[i].j];
					printf("Accept\n");
				}

			}
		}
	}
	return 0;
}

