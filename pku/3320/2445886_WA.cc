#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000001

int a[MAX],n,m,b[MAX];
bool c[MAX];

int main()
{
	int i,t,q,x,ma;
	memset(c,0,sizeof(c));
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b,b+n);
	m=0;
	b[n]=-1;
	for(i=0;i<n;i++)
	{
		if(b[i]==b[i+1])
			continue;
		b[m++]=b[i];
	}
	t=0;
	x=0;
	ma=9999999;
	for(i=0;i<n;i++)
	{
		q=lower_bound(b,b+m,a[i])-b;
		if(!c[q])
		{
			c[q]=true;
			t++;
		}
		if(t==m)
		{
			if(i-x+1<ma)
				ma=i-x+1;
			q=lower_bound(b,b+m,a[x])-b;
			c[q]=false;
			x++;
		}
	}
	printf("%d\n",ma);
	return 0;
}
