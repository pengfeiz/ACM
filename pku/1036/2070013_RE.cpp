#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 102
int a[2][MAX];
struct gao
{
	int a,b,c;
}x[MAX];

bool com(gao a,gao b)
{
	if(a.a<b.a)
		return true;
	if(a.a==b.a&&a.b<b.b)
		return true;
	return false;
}

int minn(int i,int m)
{
	return i>m?m:i;
}

int maxx(int a,int b,int c)
{
	int e=a;
	if(e<b)
		e=b;
	if(e<c)
		e=c;
	return e;
}

int main()
{
	int n,i,j,m,l,max;
	scanf("%d%d%d",&n,&m,&l);
	for(i=0;i<n;i++)
		scanf("%d",&x[i].a);
	for(i=0;i<n;i++)
		scanf("%d",&x[i].c);
	for(i=0;i<n;i++)
		scanf("%d",&x[i].b);
	for(i=0;i<MAX;i++)
		a[0][i]=0;
	sort(x,x+n,com);
	x[n].a=x[n].b=x[n].c=-999999;
	n=0;
	for(i=1;i<=l;i++)
	{
		for(j=1;j<=minn(i,m);j++)
		{
			a[1][j]=maxx(a[0][j],a[0][j+1],a[0][j-1]);
			max=0;
			while(x[n].a<i||(x[n].a==i&&x[n].b<j))
				n++;
			while(x[n].a==i&&x[n].b==j)
			{
				max+=x[n].c;
				n++;
			}
			a[1][j]+=max;
		}
		memcpy(a[0],a[1],sizeof(a[0]));
	}
	n=0;
	for(i=1;i<=m;i++)
		if(a[0][i]>n)
			n=a[0][i];
	printf("%d\n",n);
	return 0;
}




