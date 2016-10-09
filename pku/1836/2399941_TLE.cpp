#include <iostream>
using namespace std;
#define MAX 10
#define esp 1e-7

double h[MAX],c[MAX];
int n;
int a[MAX],m;
int b[MAX];

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,t;
	scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%lf",&h[i]);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		m=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
				if(c[j]-h[i]>-esp)
					break;
			if(j>m)
				m++;
			c[j]=h[i];
			a[i]=j;
		}
		m=0;
		for(i=n;i>0;i--)
		{
			for(j=1;j<=m;j++)
				if(c[j]-h[i]>-esp)
					break;
			if(j>m)
				m++;
			c[j]=h[i];
			b[i]=j;
		}
		t=0;
		for(i=1;i<n;i++)
			for(j=i+1;j<=n;j++)
				if(t<a[i]+b[j])
					t=a[i]+b[j];
		printf("%d\n",n-t);
	return 0;
}
			
				

