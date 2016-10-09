#include <iostream>
#include <algorithm>
using namespace std;

struct gao
{
	int x,y,l;
}b[100000];

bool a[20000];
int root[20000];
int n,n1,n2,m,t,ttt;

bool com(gao a,gao b)
{return a.l<b.l;}

int getroot(int x)
{
	if(x==root[x])
		return x;
	root[x]=getroot(root[x]);
	return root[x];
}

void init()
{
	int i,x,y;
	scanf("%d%d%d",&n1,&n2,&m);
	n=n1+n2;
	ttt=10000;
	for(i=0;i<n;i++)
	{
		a[i]=0;
		root[i]=i;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].l);
		b[i].l=10000-b[i].l;
		b[i].y+=n1;
	}
	sort(b,b+m,com);
	t=1;
	for(i=0;i<m;i++)
	{
		if(t==n)
			break;
		x=getroot(b[i].x);
		y=getroot(b[i].y);
		if(x==y)
			continue;
		root[x]=y;
		ttt+=b[i].l;
		t++;
	}
	ttt+=10000*(n-t);
	printf("%d\n",ttt);
}

int main()
{
	int nn;
	scanf("%d",&nn);
	while(nn--)
	{
		init();
	}
	return 0;
}