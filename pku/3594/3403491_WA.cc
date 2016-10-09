#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct gao
{
	int x,y,a,b,l;
}a[2002];


vector<int> d[102];
int n,m,s,t;
int b[102];


int c[102],cc[102];
int p;


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
				if(b[x]<=a[*q].b-a[*q].l&&a[*q].a<=a[*q].b-a[*q].l)
				{
					if(b[x]<a[*q].a)
						help_x=a[*q].a;
					else
						help_x=b[x];
					if(help_x<b[a[*q].y]-a[*q].l)
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
//	freopen("in.txt","r",stdin);
	int i,maxx;
	while(scanf("%d%d%d%d",&n,&m,&s,&t)!=EOF){
	for(i=0;i<=n;i++)
	{
		d[i].clear();
	}
	for(i=0;i<m;i++)
		scanf("%d%d%d%d%d",&a[i].x,&a[i].y,&a[i].a,&a[i].b,&a[i].l);
	for(i=0;i<m;i++)
		d[a[i].x].push_back(i);

	maxx=1<<30;
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
	if(maxx<(1<<30))
		printf("%d\n",maxx);
	else
		printf("Impossible\n");
	}
	return 0;
}

