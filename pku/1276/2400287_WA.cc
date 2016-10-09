#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001

bool a[MAX];
int b[10],c[10],d[MAX],dd[MAX];
int m,n,t;

int main()
{
	int i,tt,j,k;
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
			tt=0;
			for(j=0;j<t;j++)
			{
				for(k=1;k<=c[i];k++)
				{
					if(d[j]+k*b[i]>m)
						break;
					if(!a[d[j]+k*b[i]])
					{
						a[d[j]+k*b[i]]=true;
						dd[tt++]=d[j]+k*b[i];
					}
				}
			}
			t=tt;
			for(j=0;j<tt;j++)
				d[j]=dd[j];
			sort(d,d+n);
		}
		for(i=m;i>=0;i--)
			if(a[i])
				break;
		printf("%d\n",i);
	}
	return 0;
}