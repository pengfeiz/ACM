#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 26
int n,m,x,y,i,t;
bool a[MAX][MAX];
char c[MAX];

bool judge()
{
	int j,k,b[MAX],d[MAX];
	memset(b,0,sizeof(b));
	for(j=0;j<n;j++)
		for(k=0;k<n;k++)
			if(a[j][k])
				b[j]++;
    for(j=0;j<n;j++)
		d[b[j]]=j;
	sort(b,b+n);
	for(j=0;j<n;j++)
		if(b[j]!=j)
			return false;
	for(j=0;j<n;j++)
		c[j]=d[j]+'A';
	return true;
}

void dosth()
{
	if(x==y||a[y][x])
	{
		t=-i;
		return;
	}
	int j,k;
	bool b[MAX],d[MAX];
	memset(b,0,sizeof(b));
	memset(d,0,sizeof(d));
	for(j=0;j<n;j++)
	{
		if(a[j][x])
			b[j]=true;
		if(a[y][j])
			d[j]=true;
	}
	for(j=0;j<n;j++)
	{
		if(b[j])
		{
			if(d[j])
			{
				t=-i;
				return;
			}
			for(k=0;k<n;k++)
				if(d[k]&&a[k][j])
				{
					t=-i;
					return;
				}
		}
	}
	a[x][y]=true;
	for(j=0;j<n;j++)
	{
		if(b[j])
			a[j][y]=true;
		if(d[j])
			a[x][j]=true;
	}
	if(judge())
	{
		if(i<t)
			t=i;
		return;
	}
}
		
int main()
{
	char s[30];
	while(scanf("%d%d",&n,&m),n||m)
	{
		t=9999;
		memset(a,0,sizeof(a));
		for(i=1;i<=m;i++)
		{
			scanf("%s",s);
			if(t<0)
				continue;
			x=s[2]-'A';
			y=s[0]-'A';
			dosth();
		}
		if(t<0)
			printf("Inconsistency found after %d relations.\n",-t);
		else if(t<9999)
			printf("Sorted sequence determined after %d relations: %s.\n",t,c);
		else
			printf("Sorted sequence cannot be determined.\n");
	}
	return 0;
}

