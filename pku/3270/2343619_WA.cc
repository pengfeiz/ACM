#include <iostream>
#include <algorithm>
using namespace std;


#define MAX 10002
struct gao
{
	int a,n;
};

int n,a[MAX],c[MAX*10],d[MAX*10],b[MAX];
__int64 t;

bool com(gao x,gao y)
{return x.a<y.a;}

int main()
{
	int i,x,y;
	scanf("%d",&n);
	memset(c,0,sizeof(c));
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		c[a[i]]=i;
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	for(i=1;i<=n;i++)
		d[b[i]]=i;
	t=0;
	for(i=n;i>0;i--)
	{
		if(d[a[i]]!=c[a[i]])
		{
			if(d[a[i]]==c[b[i]])
			{
				t+=a[i]+b[i];
				x=a[i];
				y=b[i];
				swap(a[i],a[c[b[i]]]);
				swap(c[x],c[y]);
			}
			else if(a[i]!=b[1])
			{
				t+=a[i]+b[1];
				x=a[i];
				y=b[1];
				swap(a[i],a[c[b[1]]]);
				swap(c[x],c[y]);
			}
		}
	}
	printf("%I64d\n",t);
	return 0;
}