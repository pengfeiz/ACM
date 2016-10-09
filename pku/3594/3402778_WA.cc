#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct gao
{
	int x,y,a,b,l;
}a[1001];
vector<int> d[101];
int n,m,s,t;
int b[101];


int c[1001],cc[1001];
int p;


bool com(gao a,gao b)
{
	if(a.x!=b.x)
		return a.x<b.x;
	if(a.y!=b.y)
		return a.y<b.y;
	if(a.a!=b.a)
		return a.x<b.a;
	if(a.b!=b.b)
		return a.b<b.b;
	return a.l<b.l;
}


void bfs()
{
	int pp,i,x,help_x;
	vector<int>::iterator q;
	bool f[101];
	while(p)
	{
		pp=0;
		memset(f,0,sizeof(f));
		for(i=0;i<p;i++)
		{
			x=c[i];
			for(q=d[x].begin();q<d[x].end();q++)
			{
				if(b[x]+a[*q].l<=a[*q].b)
				{
					if(b[x]<a[*q].a)
						help_x=a[*q].a;
					else
						help_x=b[x];
					if(help_x+a[*q].l<b[a[*q].y])
					{
						b[a[*q].y]=help_x+a[*q].l;
						if(!f[a[*q].y])
						{
							cc[pp++]=a[*q].y;
							f[a[*q].y]=true;
						}
					}
				}
			}
		}
		p=pp;
		for(i=0;i<p;i++)
			c[i]=cc[i];
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	int i,M=0,maxx;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	
	for(i=1;i<=n;i++)
	{
		d[i].clear();
	}
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d%d%d",&a[M].x,&a[M].y,&a[M].a,&a[M].b,&a[M].l);
		if(a[M].l<=a[M].b-a[M].a)
			M++;
	}

	m=M;
	sort(a,a+m,com);
	for(i=0;i<m;i++)
	{
		d[a[i].x].push_back(i);
	}

	maxx=99999999;
	vector<int>::iterator q;
	for(q=d[s].begin();q<d[s].end();q++)
	{
		memset(b,127,sizeof(b));
		p=1;
		b[s]=a[*q].a;
		c[0]=s;
		bfs();
		if(maxx>b[t]-a[*q].a)
			maxx=b[t]-a[*q].a;
	}
	if(maxx<99999999)
		printf("%d\n",maxx);
	else
		printf("Impossible\n");

	return 0;
}

