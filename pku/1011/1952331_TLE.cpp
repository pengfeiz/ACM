#include <iostream>
#include <math.h>
using namespace std;
int a[64],n,t,c[64],s;
int fill(int x,int i,int q)
{
	int p;
	if(i>=n)
		return 0;
	if(x==a[i]&&c[i]==0)
	{
		c[i]=1;
		if(q==t/s)
			return 1;
		else
		{
			p=fill(s,0,q+1);
			if(p==1)
				return 1;
			else
				c[i]=0;
		}
	}
	if(x<a[i])
		return fill(x,i+1,q);
	if(c[i]==0)
	{
		c[i]=1;
		p=fill(x-a[i],i+1,q);
		if(p==1)
			return 1;
		c[i]=0;
	}
	return fill(x,i+1,q);
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
				s=t/i;
				for(j=0;j<n;j++)
					c[j]=0;
				if(fill(t/i,0,1)==1)
					break;
			}
		cout<<t/i<<endl;
	}
	return 0;
}
		


				


