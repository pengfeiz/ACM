#include <iostream>
using namespace std;
int main()
{
	int a[4],n,i,j,p,q,t,x;
	while(cin>>n&&n!=-1)
	{
		p=1;
		q=t=0;
		x=4;
		cout<<"N="<<n<<":\n";
		if(n/1000==n/100%10&&n/100%10==n/10%10&&n/10%10==n%10)
		{
			cout<<"No!!\n";
			continue;
		}
		if(n<1000)
		{
			cout<<"No!!\n";
			continue;
		}
		while(n!=0&&n!=6174)
		{
			t++;
			for(i=x-1;i>=0;i--)
			{
				a[i]=n%10;
				n/=10;
			}
			for(i=0;i<x-1;i++)
				for(j=i+1;j<x;j++)
				{
					if(a[i]<a[j])
					{
						p=a[i];
						a[i]=a[j];
						a[j]=p;
					}
				}
			p=q=0;
			for(i=0;i<x;i++)
			{
				p=10*p+a[i];
				q=10*q+a[x-1-i];
			}
			n=p-q;
			cout<<p<<"-"<<q<<"="<<n<<endl;
			if(n>999)
				x=4;
			else if(n>99)
				x=3;
			else if(n>9)
				x=2;
			else
				x=1;
		}
		cout<<"Ok!! "<<t<<" times\n";
	}
	return 0;
}



