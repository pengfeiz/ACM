#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	long a[4],n,i,j,p,q,t,x;
	char s[100];
	while(cin>>s&&strcmp(s,"-1")!=0)
	{
		p=1;
		q=t=0;
		x=strlen(s);
		cout<<"N="<<s<<":\n";
		if(x!=4)
		{
			cout<<"No!!\n";
			continue;
		}
		for(i=n=0;i<x;i++)
			n=n*10+(s[i]-'0');
		if(n/1000==n/100%10&&n/100%10==n/10%10&&n/10%10==n%10)
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



