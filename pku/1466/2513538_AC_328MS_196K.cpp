#include <iostream>
#include <vector>
using namespace std;
#define MAX 501

int y[MAX],n,t;
vector<int> a[MAX];
bool q[MAX];


bool find(int x)
{
	if(q[x])
		return false;
	q[x]=true;
	vector<int>::iterator p;
	p=a[x].begin();
	while(p!=a[x].end())
	{
		if(y[*p]<0||find(y[*p]))
		{
			if(y[*p]<0)
				t++;
			y[*p]=x;
			return true;
		}
		p++;
	}
	return false;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,x,m,yy,j;
	while(scanf("%d",&n)!=EOF)
	{
		t=0;
		for(i=0;i<n;i++)
			a[i].clear();
		for(i=0;i<n;i++)
		{
			scanf("%d: (%d)",&x,&m);
			for(j=0;j<m;j++)
			{
				scanf("%d",&yy);
				a[x].push_back(yy);
			}
		}
		memset(y,0xFF,sizeof(y));
		for(i=0;i<n;i++)
		{
			memset(q,0,sizeof(q));
			find(i);
		}
		printf("%d\n",n-t/2);
	}
	return 0;
}