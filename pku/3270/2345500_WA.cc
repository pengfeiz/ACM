#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10005

int n,minn,h,p;
__int64 t;
struct gao
{
	int a,n;
}a[MAX];
bool c[MAX];

bool com(gao x,gao y)
{return x.a<y.a;}


void dfs(int x,int y)
{
	h++;
	c[x]=true;
	p+=a[x].a;
	if(a[x].n!=y)
		dfs(a[x].n,y);
}	
	

int main()
{
	int i;
	t=0;
	minn=0x7fffffff;
	scanf("%d",&n);
	memset(c,0,sizeof(c));
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i].a);
		a[i].n=i;
		if(a[i].a<minn)
			minn=a[i].a;
	}
	sort(a,a+n,com);
	for(i=0;i<n;i++)
	{
		h=p=0;
		if(!c[i])
		{
			dfs(i,i);
			if((h-2)*a[i].a>h*a[0].n)
				t+=h*a[0].n+p;
			else
				t+=(h-2)*a[i].a+p;
		}
	}
	printf("%d\n",t);
	return 0;
}