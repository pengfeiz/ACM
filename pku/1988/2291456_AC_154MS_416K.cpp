#include <iostream>
using namespace std;

#define MAX 30001

struct gao
{
	int a,n,t;
}a[MAX];

int n,p;


int getroot(int x,int &l)
{
	int root;
	if(x==a[x].a)
		return x;
	root=getroot(a[x].a,l);
	l+=a[x].n;
	a[x].a=root;
	a[x].n=l;
	return root;
}


int count(int p)
{
	int x;
	x=a[p].n;
	if(a[p].a!=p)
		x+=count(a[p].a);
	return x;
}

int main()
{
//	freopen("in.txt","r",stdin);
	char s[2];
	int i,from,to,x,y,l;
	scanf("%d",&p);
	for(i=1;i<MAX;i++)
	{
		a[i].a=i;
		a[i].n=0;
		a[i].t=1;
	}
	while(p--)
	{
		scanf("%s",s);
		if(s[0]=='M')
		{
			scanf("%d%d",&from,&to);
			l=0;
			x=getroot(from,l);
			l=0;
			y=getroot(to,l);
			a[x].a=y;
			a[x].n=a[y].t;
			a[y].t+=a[x].t;
		}
		else
		{
			scanf("%d",&from);
			printf("%d\n",count(from));
		}
	}
	return 0;
}