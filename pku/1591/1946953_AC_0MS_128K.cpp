#include <iostream>
using namespace std;
int main()
{
	int n,a[20],t,tt,p=0,h[50],x,i,j;
	while(cin>>n)
	{
		if(p)
			cout<<endl;
		p++;
		cout<<"Selection #"<<p<<endl;
		for(i=0;i<n;i++)
			h[i]=1;
		cin>>t;
		for(i=0;i<20;i++)
			cin>>a[i];
		tt=n;
		j=-1;
		while(tt>t&&j<20)
		{
			j++;
			for(i=x=0;i<n&&tt>t;i++)
			{
				if(h[i]==1)
					x++;
				if(x==a[j])
				{
					h[i]=0;
					x=0;
					tt--;
				}
			}
		}
		for(i=tt=0;i<n&&tt<t;i++)
		{
			if(h[i]==1)
			{
				if(tt)
					cout<<" ";
				cout<<i+1;
				tt++;
			}
		}
		cout<<endl;
	}
	return 0;
}
				

