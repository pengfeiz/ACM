#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 20002

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
	int i,x,y,ans,hx,hy;
	gao q;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d%d%d",&b[i].i,&b[i].j,&b[i].sum);
		for(i=0;i<n;i++)
		{
			if(b[i].i>b[i].j)
				swap(b[i].i,b[i].j);
			b[i].i--;
			c[2*i]=b[i].i;
			c[2*i+1]=b[i].j;
		}
		sort(c,c+2*n);
		c[2*n]=-123;
		t=0;
		for(i=0;i<2*n;i++)
			if(c[i]!=c[i+1])
				a[t++].n=c[i];
		for(i=0;i<t;i++)
		{
			a[i].root=i;
			sum[i]=0;
		}
		for(i=0;i<n;i++)
		{
			q.n=b[i].i;
			hx=lower_bound(a,a+t,q,comp)-a;
			q.n=b[i].j;
			hy=lower_bound(a,a+t,q,comp)-a;
			x=getroot(hx);
			y=getroot(hy);
			if(x==y)
			{
				ans=sum[hy]-sum[hx];
				if(ans==b[i].sum)
					printf("Accept\n");
				else
					printf("Bug Detected %d\n",ans);
			}
			else
			{
				a[y].root=x;
				sum[y]=b[i].sum+sum[hx]-sum[hy];
				printf("Accept\n");
			}
		}
	}
	return 0;
}