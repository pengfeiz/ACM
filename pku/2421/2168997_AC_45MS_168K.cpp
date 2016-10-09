#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100
int a[MAX],n,m,t,l;

struct gao
{
	int x,y,l;
}b[MAX*MAX];

bool com(gao a,gao b)
{
	return a.l<b.l;
}

int get(int x)
{
	int root;
	if(a[x]==x)
		return x;
	root=get(a[x]);
	a[x]=root;
	return root;
}

bool find(int i)
{
	int x,y;
	x=get(b[i].x);
	y=get(b[i].y);
	if(x==y)
		return false;
	if(x>y)
		a[x]=y;
	else
		a[y]=x;
	return true;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,x,y;
	scanf("%d",&n);
	t=n-1;
	l=0;
	for(i=0;i<n;i++)
	{
		a[i]=i;
		for(j=0;j<n;j++)
		{
			scanf("%d",&b[i*n+j].l);
			b[i*n+j].x=i;
			b[i*n+j].y=j;
		}
	}
	sort(b,b+n*n,com);
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d%d",&i,&j);
		i--;
		j--;
		x=get(i);
		y=get(j);
		if(x>y)
			a[x]=y;
		else
			a[y]=x;
	}
	for(i=0;i<n;i++)
		if(a[i]!=i)
			t--;
	for(i=0;i<n*n&&t;i++)
		if(find(i))
		{
			t--;
			l+=b[i].l;
		}
	printf("%d\n",l);
	return 0;
}
