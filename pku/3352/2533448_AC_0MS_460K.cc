#include <iostream>
#include <vector>
using namespace std;

#define maxn 5002


vector<int> graph[maxn];
int dfn[maxn];
int index[maxn];
int stack[maxn];
int total_in[maxn];
int n,m,stail,tt,ttp;


void dfs(int x,int parents)
{
	int tp;
	vector<int>::iterator p;
	stack[++stail]=x;
	ttp++;
	tp=ttp;
	dfn[x]=ttp;
	p=graph[x].begin();
	while(p!=graph[x].end())
	{
		if(*p!=parents)
		{
			if(!dfn[*p])
				dfs(*p,x);
			if(dfn[x]>dfn[*p])
				dfn[x]=dfn[*p];
		}
		p++;
	}
	if(dfn[x]==tp)
	{
		tt++;	
		do{
			index[stack[stail]]=tt;
		}while(stack[stail--]!=x);
	}
}


int main()
{
	int i,x,y;
	scanf("%d%d",&n,&m);
	memset(dfn,0,sizeof(dfn));
	memset(total_in,0,sizeof(total_in));
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	ttp=tt=stail=0;
	dfs(1,0);
	vector<int>::iterator p;
	for(i=1;i<=n;i++)
	{
		p=graph[i].begin();
		while(p!=graph[i].end())
		{
			if(index[i]!=index[*p])
				total_in[index[i]]++;
			p++;
		}
	}
	ttp=0;
	for(i=1;i<=tt;i++)
		if(total_in[i]==1)
			ttp++;
	printf("%d\n",(ttp+1)/2);
	return 0;
}
