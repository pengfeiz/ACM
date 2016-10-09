#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001

bool a[MAX];
int b[10],c[10],d[MAX];
int m,n,t;

int main()
{
	int i,j,k,tt;
	while(scanf("%d",&m)!=EOF)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d%d",&c[i],&b[i]);
		memset(a,0,sizeof(a));
		a[0]=true;
		t=1;
		d[0]=0;
		for(i=0;i<n;i++)
		{
			tt=t;
			for(j=0;j<tt;j++)
			{
				for(k=1;k<=c[i];k++)
				{
					if(d[j]+k*b[i]>m)
						break;
					if(!a[d[j]+k*b[i]])
					{
						a[d[j]+k*b[i]]=true;
						d[t++]=d[j]+k*b[i];
					}
				}
			}
			sort(d,d+t);
		}
		for(i=m;i>=0;i--)
			if(a[i])
				break;
		printf("%d\n",i);
	}
	return 0;
}


