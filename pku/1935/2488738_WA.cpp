#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 50002


struct gao
{
	int n,to[3],l[3];
}a[MAX];

int n,k;
bool c[MAX];
bool d[MAX];

int dfs(int x,bool &f)
{
	int l[3],i;
	bool he;
	if(d[x])
		f=true;
	memset(l,0,sizeof(l));
	for(i=0;i<a[x].n;i++)
	{
		he=false;
		if(c[a[x].to[i]])
			continue;
		c[a[x].to[i]]=true;
		l[i]=dfs(a[x].to[i],he)+a[x].l[i];
		if(!he)
			l[i]=0;
	}
	sort(l,l+3);
	return 2*l[1]+l[2];
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,x,y,l,h;
	bool f;
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	memset(a,0,sizeof(a));
	scanf("%d%d",&n,&k);
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&l);
		h=a[x].n;
		a[x].to[h]=y;
		a[x].l[h]=l;
		a[x].n++;
		h=a[y].n;
		a[y].to[h]=x;
		a[y].l[h]=l;
		a[y].n++;
	}
	scanf("%d",&h);
	c[h]=d[h]=true;
	for(i=0;i<k;i++)
	{
		scanf("%d",&x);
		d[x]=true;
	}
	f=false;
	l=dfs(h,f);
	if(f)
		printf("%d\n",l);
	else
		printf("0\n");
	return 0;
}


