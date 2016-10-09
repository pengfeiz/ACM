#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1001

int a[MAX],b[MAX],n,m;
bool c[MAX];

int lcm(int a,int b)
{
	int c,d=a,e=b;
	if(a<b)
		swap(a,b);
	while(a%b)
	{
		c=a%b;
		a=b;
		b=c;
	}
	return d*e/b;
}

int main()
{
	int i,t,x,s;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	t=m=0;
	memset(c,0,sizeof(c));
	for(i=1;i<=n;i++)
		if(!c[i])
		{
			c[i]=true;
			s=1;
			x=i;
			while(a[x]!=i)
			{
				x=a[x];
				c[x]=true;
				s++;
			}
			b[m++]=s;
		}
	for(i=0;i<m-1;i++)
		b[i+1]=lcm(b[i],b[i+1]);
	printf("%d\n",b[m-1]);
	return 0;
}