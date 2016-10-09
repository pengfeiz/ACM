#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1001

int a[MAX][MAX];
struct gao
{
	int a,b,l;
}b[MAX*20];

int n,m,root[MAX];


bool com(gao a,gao b)
{return a.l>b.l;}
int getroot(int x)
{
	if(x!=root[x])
		root[x]=getroot(root[x]);
	return root[x];
}

int main()
{
	int i,x,y,l,t,j,tt=1;
	memset(a,0,sizeof(a));
	scanf("%d%d",&n,&t);
	m=0;
	for(i=0;i<t;i++)
	{
		scanf("%d%d%d",&x,&y,&l);
		if(x>y)
			swap(x,y);
		if(a[x][y]<l)
			a[x][y]=a[y][x]=l;
	}
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			if(a[i][j])
			{
				b[m].a=i;
				b[m].b=j;
				b[m].l=a[i][j];
				m++;
			}

	for(i=1;i<=n;i++)
		root[i]=i;
	sort(b,b+m,com);
	t=0;
	for(i=0;i<m;i++)
	{
		x=getroot(b[i].a);
		y=getroot(b[i].b);
		if(x==y)
			continue;
		tt++;
		root[y]=x;
		t+=b[i].l;
		if(tt==n)
			break;
	}
	if(tt==n)
		printf("%d\n",t);
	else
		printf("-1\n");
	return 0;
}




