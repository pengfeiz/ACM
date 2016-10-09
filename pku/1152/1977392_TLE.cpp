#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
char s[100000];
int main()
{
	long l,i,t,q,p,j;
	char c;
	while(cin>>s)
	{
		c=0;
		l=strlen(s);
		for(i=0;i<l;i++)
			if(c<s[i])
				c=s[i];
		if(c<='9'&&c>='1')
			t=long(c-'0'+1);
		else if(c=='0')
			t=2;
		else if(c<='Z'&&c>='A')
			t=long(c-'A'+11);
		else
			t=long(c-'a'+37);
		for(t;t<63;t++)
		{
			q=0;
			for(i=0;i<l;i++)
			{
				p=1;
				for(j=0;j<l-i-1;j++)
				{
					p*=t;
					p%=(t-1);
				}
				if(s[i]>='0'&&s[i]<='9')
					p*=(s[i]-'0');
				else if(s[i]>='A'&&s[i]<='Z')
					p*=(s[i]-'A'+10);
				else
					p*=(s[i]-'a'+36);
				q+=p;
				q%=(t-1);
			}
			if(q==0)
				break;
		}
		if(t<63)
			cout<<t<<endl;
		else
			cout<<"such number is impossible!\n";
	}
	return 0;
}