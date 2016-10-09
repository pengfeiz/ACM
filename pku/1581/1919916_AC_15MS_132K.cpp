#include <iostream>
#include <string.h>
using namespace std;
char s[1000],c[1000];
int main()
{
	int nn,i,tt,ts,mt,ms,a,b;
	cin>>nn;
	tt=ts=ms=0;
	mt=999999999;
	while(nn-->0)
	{
		tt=ts=0;
		cin>>s;
		for(i=0;i<4;i++)
		{
			cin>>a>>b;
			if(b!=0)
			{
				ts++;
				tt+=b+(a-1)*20;
			}
		}
		if(ts>=ms)
			if(tt<mt)
			{
				strcpy(c,s);
				ms=ts;
				mt=tt;
			}	
	}
	cout<<c<<" "<<ms<<" "<<mt<<endl;
	return 0;
}