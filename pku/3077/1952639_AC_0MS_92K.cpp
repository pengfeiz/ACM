#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char s[10];
	int l,i,nn;
	cin>>nn;
	while(nn-->0)
	{
		cin>>s;
		l=strlen(s);
		for(i=l-1;i>0;i--)
		{
			if(s[i]>'4')
				s[i-1]++;
			s[i]='0';
		}
		cout<<int(s[i]-'0')<<s+1<<endl;
	}
	return 0;
}


