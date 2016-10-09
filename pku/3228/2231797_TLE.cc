#include <iostream>
using namespace std;
#define MAX 201
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b 

int a[MAX],b[MAX],n,m;
int d[MAX][MAX],root[MAX];

bool judge()
{
	int i,j,t;
	for(i=1;i<=n;i++)
	{
		if(root[i]==i)
		{
			t=0;
			for(j=i;j<=n;j++)
			{
				if(root[j]==i)
				{
					t+=a[j];
					t-=b[j];
				}
			}
			if(t<0)
				return true;
		}
	}
	return false;
}

int main()
{
	int i,j,p,q,l,mm;
	while(scanf("%d",&n),n)
	{
		mm=0;
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(i=1;i<=n;i++)
			scanf("%d",&b[i]);
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&p,&q,&l);
			d[p][q]=d[q][p]=l;
		}
		for(i=0;i<=n;i++)
			root[i]=i;
		while(judge())
		{
			l=99999999;
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
				{
					if(root[i]==root[j])
						continue;
					if(d[i][j]<l)
					{
						l=d[i][j];
						p=i;
						q=j;
					}
				}
			if(mm<d[p][q])
				mm=d[p][q];
			d[p][q]=d[q][p]=99999999;
			l=min(p,q);
			p=max(p,q);
			for(i=1;i<=n;i++)
				if(root[i]==p)
					root[i]=l;
		}
		printf("%d\n",mm);
	}
	return 0;
}




			

