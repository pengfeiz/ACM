#include <iostream>
using namespace std;
int main()
{
	int a[4],n,i,j,p,q,t;
	while(cin>>n&&n!=-1)
	{
		p=1;
		q=t=0;
		cout<<"N="<<n<<":\n";
		if(n/1000==n/100%10&&n/100%10==n/10%10&&n/10%10==n%10)
		{
			cout<<"No!!\n";
			continue;
		}
		while(n!=0&&n!=6174)
		{
			t++;
			for(i=3;i>=0;i--)
			{
				a[i]=n%10;
				n/=10;
			}
			for(i=0;i<3;i++)
				for(j=i+1;j<4;j++)
				{
					if(a[i]<a[j])
					{
						p=a[i];
						a[i]=a[j];
						a[j]=p;
					}
				}
			p=q=0;
			for(i=0;i<4;i++)
			{
				if(a[i]!=0)
					p=10*p+a[i];
				if(a[3-i]!=0)
					q=10*q+a[3-i];
			}
			n=p-q;
			cout<<p<<"-"<<q<<"="<<n<<endl;
		}
		cout<<"Ok!! "<<t<<" times\n";
	}
	return 0;
}



