#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 10005

char s[MAX];
int l,m;
struct gao
{
	int x,d;
}b[MAX];

bool com(gao a,gao b)
{
	if(a.d!=b.d)
		return a.d>b.d;
	return a.x>b.x;
}

void dfs(int d)
{
	b[m].x=l;
	b[m++].d=d;
	if(s[l]>='a'&&s[l]<='z')
	{
		l--;
		return;
	}
	l--;
	dfs(d+1);
	dfs(d+1);
}

int main()
{
	int n,i;
	scanf("%d",&n);
	while(n--)
	{
		m=0;
		scanf("%s",s);
		l=strlen(s);
		l--;
		dfs(1);
		sort(b,b+m,com);
		for(i=0;i<m;i++)
			printf("%c",s[b[i].x]);
		printf("\n");
	}
	return 0;
}