#include <iostream>
#include <vector>
using namespace std;
char s[10005];
int l,m,maxx;
vector<int> v[10005];
void dfs(int d)
{
	if(d>maxx)
		maxx=d;
	v[d].push_back(l);
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
	vector<int>::iterator j;
	scanf("%d",&n);
	while(n--)
	{
		m=maxx=0;
		scanf("%s",s);
		l=strlen(s)-1;
		for(i=1;i<=l;i++)
			v[i].clear();
		dfs(1);
		l=strlen(s);
		for(i=maxx;i>0;i--)
			for(j=v[i].begin();j<v[i].end();j++)
				printf("%c",s[*j]);
		printf("\n");
	}
	return 0;
}
