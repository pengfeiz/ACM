#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	__int64 n;
	char s[64],c[64];
	int nn,l,i;
	cin>>nn;
	while(nn-->0)
	{	
		cin>>l;
		cin>>s;
		scanf("%I64d",&n);
		i=l-1;
		while(i>=0)
		{
			if(n%2==0)
			{
				c[i]='0';
				n/=2;
			}
			else if(s[i]=='n')
			{
				c[i]='1';
				n=(n+1)/2;
			}
			else
			{
				c[i]='1';
				n=(n-1)/2;
			}
			i--;
		}
		if(n==0)
			for(i=0;i<l;i++)
				cout<<c[i];
		else
			cout<<"Impossible";
		cout<<endl;
	}
	return 0;
}

		
		