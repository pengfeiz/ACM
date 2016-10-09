#include <iostream>
#include <string.h>
using namespace std;
char s[100000];
int main()
{
	long l,i;
	char c;
	while(cin>>s)
	{
		c=0;
		l=strlen(s);
		for(i=0;i<l;i++)
			if(c<s[i])
				c=s[i];
		if(c<='9'&&c>='1')
			cout<<int(c-'0'+1);
		else if(c=='0')
			cout<<2;
		else if(c<='Z'&&c>='A')
			cout<<int(c-'A'+11);
		else if(c<='z'&&c>='a')
			cout<<int(c-'a'+37);
		else
			cout<<"such number is impossible!\n";
		cout<<endl;
	}
	return 0;
}