#include <iostream>
#include <vector>

using namespace std;
#define MAX 10005

char s[MAX];
int l,m;
vector<int> v[MAX];

void dfs(int d)
{
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
		m=0;
		scanf("%s",s);
		l=strlen(s);
		for(i=1;i<=l;i++)
			v[i].clear();
		l--;
		dfs(1);
		l=strlen(s);
		for(i=l;i>=1;i--)
			for(j=v[i].begin();j<v[i].end();j++)
				printf("%c",s[*j]);
		printf("\n");
	}
	return 0;
}
