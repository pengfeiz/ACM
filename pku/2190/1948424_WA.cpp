#include <iostream>
#include <string.h>
using namespace std;
char s[10];
int main()
{
	int i,p,n=0;
	cin>>s;
	for(i=0;i<10;i++)
	{
		if(s[i]=='?')
			p=i;
		else if(i==9&&s[i]=='X')
			n+=10;
		else
			n+=(10-i)*(s[i]-'0');
	}
	if(p<9)
	{
		for(i=1;i<10;i++)
			if((n+p*i)%11==0)
			{
				cout<<i<<endl;
				break;
			}
	}
	else
	{
		for(i=0;i<=10;i++)
			if((n+p*i)%11==0)
			{
				if(i<10)
					cout<<i<<endl;
				else
					cout<<"X"<<endl;
				break;
			}
	}
	return 0;
}

