#include <stdio.h>
#include <string.h>
#define MAX 102
#define MAX2 30001
int a[MAX2][MAX],b[MAX2][MAX];
struct gao
{
	int a,b,c;
}x[MAX];

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
	for(i=0;i<MAX2;i++)
		for(j=0;j<MAX;j++)
			a[i][j]=-999999;
	memset(b,0,sizeof(b));
	for(i=0;i<n;i++)
		b[x[i].a][x[i].b]=x[i].c;
	a[0][0]=0;
	for(i=1;i<=l;i++)
		for(j=1;j<=m;j++)
			a[i][j]=max(a[i-1][j],a[i-1][j+1],a[i-1][j-1])+b[i][j];
	n=0;
	for(i=1;i<=m;i++)
		if(a[l][i]>n)
			n=a[l][i];
	printf("%d\n",n);
	return 0;
}




