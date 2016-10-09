#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char c[10];
	int nn,l,n;
	cin>>nn;
	while(nn-->0)
	{
		cin>>c;
		l=strlen(c);
		if(c[l-1]!='0'||c[l-2]!='0')
			cout<<"0\n";
		else
		{
			if(l==4)
				n=c[0]-'0';
			else
				n=10*(c[0]-'0')+c[1]-'0';
			if(n<=12)
				cout<<n+12<<endl;
			else
				cout<<n-12<<endl;
		}
	}
	return 0;
}

