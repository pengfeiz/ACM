#include <iostream>
#include <stdlib.h>
using namespace std;
char s[12],c[12];
int main()
{
	int i,l;
	memset(s,0,sizeof(s));
	memset(s,0,sizeof(c));
	while(cin>>s)
	{
		l=strlen(s);
		for(i=0;i<l;i++)
			c[i]=(c[i]+s[i]-'0')%10;
	}
	for(i=0;i<l;i++)
		cout<<(int)c[i];
	cout<<endl;
	return 0;
}
