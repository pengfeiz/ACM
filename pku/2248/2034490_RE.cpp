#include <iostream>
using namespace std;
int n,b[10];
void dosth(int x,int a[])
{
	int i,j,c[10];
	if(a[a[0]]>=n||a[0]>9||a[0]>=b[0])
		return;
	if(a[a[0]]*2>=n)
	{
		for(i=a[0];i>0;i--)
			for(j=a[0];j>0&&a[i]+a[j]>=n;j--)
				if(a[i]+a[j]==n)
					if(a[0]<b[0])
					{
						memcpy(b,a,sizeof(b));
						return;
					}
	}
	memcpy(c,a,sizeof(c));
	c[0]++;
	for(i=c[0]-1;i>0;i--)
	{
		c[c[0]]=c[c[0]-1]+c[i];
		if(c[c[0]]<=c[c[0]-1])
			return;
		dosth(x,c);
	}
}
int main()
{
	int a[10],i;
	while(cin>>n&&n)
	{
		memset(a,0,sizeof(a));
		a[1]=1;
		a[0]=a[2]=2;
		b[0]=999;
		dosth(1,a);
		if(n==1)
		{
			printf("1\n");
			continue;
		}
		else if(n==2)
		{
			printf("1 2\n");
			continue;
		}
		for(i=1;i<=b[0];i++)
			printf("%d ",b[i]);
		printf("%d\n",n);
	}
	return 0;
}