#include <iostream>
using namespace std;
#define MAX 50000
long a[MAX],b[MAX],c[MAX];
int main()
{
	long nn,n,i,max,p,q,t;
	cin>>nn;
	while(nn-->0)
	{
		cin>>n;
		p=q=-9999;
		for(i=0;i<n;i++)
		{
			scanf("%ld",&a[i]);
			if(a[i]>p)
			{
				q=p;
				p=a[i];
			}
			else if(a[i]>q)
				q=a[i];
		}
		if(p<0||q<0)
		{
			cout<<p+q<<endl;
			continue;
		}
		for(i=t=0,max=a[0];i<n;i++)
		{
			if(t+a[i]>0)
			{
				t+=a[i];
				if(t>max)
					max=t;
			}
			else if(t+a[i]<=0)
				t=0;
			b[i]=max;
		}
		for(i=n-1,t=0,max=a[n-1];i>=0;i--)
		{			
			if(t+a[i]>0)
			{
				t+=a[i];
				if(t>max)
					max=t;
			}
			else if(t+a[i]<=0)
				t=0;
			c[i]=max;
		}
		max=0;
		for(i=0;i<n-1;i++)
			if(b[i]+c[i+1]>max)
				max=b[i]+c[i+1];
		cout<<max<<endl;
	}
	return 0;
}
