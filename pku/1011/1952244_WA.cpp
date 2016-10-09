#include <iostream>
#include <math.h>
using namespace std;
int a[64],n,t,c[64];
int fill(int x,int i)
{
	int p;
	if(i>=n)
		return 0;
	if(x==a[i]&&c[i]==0)
	{
		c[i]=1;
		return 1;
	}
	if(x<a[i])
		return fill(x,i+1);
	if(p=fill(x-a[i],i+1))
	{
		if(p==1)
		{
			c[i]=1;
			return 1;
		}
	}
	return fill(x,i+1);
}
int com(const void *a,const void *b)
{
	return *(int *)b-*(int *)a;
}
int main()
{
	int i,j;
	while(cin>>n&&n)
	{
		for(i=t=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			t+=a[i];
		}
		qsort(a,n,sizeof(a[0]),com);
		for(i=n;i>0;i--)
			if(t%i==0)
			{
				if(a[0]>t/i)
					continue;
				for(j=0;j<n;j++)
					c[j]=0;
				for(j=0;j<i;j++)
					if(fill(t/i,0)==0)
						break;
				if(j==i)
					break;
			}
		cout<<t/i<<endl;
	}
	return 0;
}
		


				


