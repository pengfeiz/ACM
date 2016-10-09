#include<iostream>
using namespace std;
int main()
{
	int t,i=0, q=0,d=0,n=0,p=0,nn,tag;
	cin>>t;
	while(t--)
	{	
		i++;
		q=0;
		d=0;
		n=0;
		p=0;
		cout<<i<<" ";
		int sum=0;
		cin>>nn;
		q=nn/25;
		int tt=nn%25;
		if(nn>25&&tt)
		{
			tag=1;
			sum=nn%25;
			if(sum>=10)
			{
				d=sum/10;
				int ss=sum%10;
				if(ss>=5)
				{
					n=1;
					p=ss-5;
				}
				else
					p=ss;
			}
			else
			{
				n=1;
				p=sum-5;
			}
		}
		
		else if(nn<25&&tt)
		{
			tag=1;
			if(nn>=10)
			{
				d=nn/10;
				sum=nn%10;
					if(sum>=5)
				{
					n=1;
					p=sum-5;
				}
				else
					p=sum;
			}
			else
			{
				if(nn>=5)
				{
					n=1;
					p=nn-5;
				}
				else
					p=nn;
			}
		}
		else
			tag=2;
		if(tag>=1)
		cout<<q<<" QUARTER(S), "<<d<<" DIME(S), "<<n<<" NICKEL(S), "<<p<<" PENNY(S)"<<endl;
	}
	return 0;

}