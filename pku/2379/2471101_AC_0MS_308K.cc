#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1001

struct gao
{
	int a,b,c,d;
}a[MAX],b[MAX];

bool com(gao a,gao b)
{
	if(a.a!=b.a)
		return a.a<b.a;
	if(a.b!=b.b)
		return a.b<b.b;
	if(a.c!=b.c)
		return a.c<b.c;
	return a.d>b.d;
}
bool com1(gao a,gao b)
{
	if(a.a!=b.a)
		return a.a>b.a;
	if(a.b!=b.b)
		return a.b<b.b;
	return a.c<b.c;
}

int n,m;


int main()
{
	int i,j,k;
	scanf("%d%d",&m,&n);
	for(i=0;i<n;i++)
		scanf("%d%d%d%d",&a[i].a,&a[i].b,&a[i].c,&a[i].d);
	sort(a,a+n,com);
	memset(b,0,sizeof(b));
	for(i=1;i<=m;i++)
		b[i].c=i;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
			if(a[i].a!=a[j].a||a[i].b!=a[j].b)
				break;
		for(k=i;k<j;k++)
			if(a[k].d==1)
				break;
		if(a[k].d==1&&k<j)
		{
			b[a[i].a].a++;
			b[a[i].a].b+=a[k].c+1200*(k-i);
		}
		i=j-1;
	}
	sort(b+1,b+m+1,com1);
	printf("%d",b[1].c);
	for(i=2;i<=m;i++)
		printf(" %d",b[i].c);
	printf("\n");
	return 0;
}
