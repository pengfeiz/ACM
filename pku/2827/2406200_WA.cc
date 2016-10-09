#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 20002

struct he
{
	int i,j,sum;
}b[MAX];

int n,t,a[MAX];
int c[MAX],sum[MAX];

int getroot(int x)
{
	int root;
	if(x==a[x])
		return x;
	root=getroot(a[x]);
	sum[x]+=sum[root];
	a[x]=root;
	return root;
}


int main()
{
	//freopen("in.txt","r",stdin);
	int i,x,y,ans;
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
				c[t++]=c[i];
		for(i=0;i<n;i++)
		{
			b[i].i=lower_bound(c,c+t,b[i].i)-c;
			b[i].j=lower_bound(c,c+t,b[i].j)-c;
		}
		for(i=0;i<t;i++)
		{
			a[i]=i;
			sum[i]=0;
		}
		for(i=0;i<n;i++)
		{
			x=getroot(b[i].i);
			y=getroot(b[i].j);
			if(x==y)
			{
				ans=sum[b[i].j]-sum[b[i].i];
				if(ans==b[i].sum)
					printf("Accept\n");
				else
					printf("Bug Detected %d\n",ans);
			}
			else
			{
				a[y]=x;
				sum[y]=b[i].sum+sum[b[i].i]-sum[b[i].j];
				printf("Accept\n");
			}
		}
	}
	return 0;
}

