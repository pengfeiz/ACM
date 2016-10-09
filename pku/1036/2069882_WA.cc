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

int max(int a,int b,int c)
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
	int n,i,j,m,l;
	scanf("%d%d%d",&n,&m,&l);
	for(i=0;i<n;i++)
		scanf("%d",&x[i].a);
	for(i=0;i<n;i++)
		scanf("%d",&x[i].c);
	for(i=0;i<n;i++)
		scanf("%d",&x[i].b);
	for(i=0;i<MAX;i++)
		a[0][i]=-999999;
	sort(x,x+n,com);
	a[0][0]=n=0;
	for(i=1;i<=l;i++)
	{
		for(j=1;j<=m;j++)
		{
			a[1][j]=max(a[0][j],a[0][j+1],a[0][j-1]);
			if(x[n].a==i&&x[n].b==j)
				a[1][j]+=x[n++].c;
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




