#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
using namespace std;

vector<int> a[100001];
int b[100001];
int c[100001];
int n,m;

vector<int> d;

int main()
{
	int ca=0;
	int i;
	int x,y;
	while(scanf("%d%d",&n,&m),n||m)
	{
		ca++;
		for(i=1;i<=n;i++)
		{
			b[i]=0;
			a[i].clear();
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			a[x].push_back(y);
			a[y].push_back(x);
		}
		d.clear();
		for(i=2;i<=n;i++)
			d.push_back(i);
		b[1]=0;
		c[0]=1;
		int t1,t2;
		t1=0;
		t2=1;
		while(t1<t2)
		{
			vector<int> d2;
			d2.clear();
			int size=a[c[t1]].size();
			for(i=0;i<size;i++)
			{
				if(b[a[c[t1]][i]]==t1) 
				{
					d2.push_back(a[c[t1]][i]);
					b[a[c[t1]][i]]=t1+1;
				}
			}
			size=d.size();
			for(i=0;i<size;i++)
			{
				if(b[d[i]]==t1)
					c[t2++]=d[i];
			}
			d=d2;
			t1++;
		}
		printf("Case %d: %d\n",ca,t2-1);
	}
	return 0;
}