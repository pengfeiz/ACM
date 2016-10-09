#include <iostream>
#include <string.h>
using namespace std;
char s[10000];
int main()
{
	int l,i,t=1;
	while(gets(s))
	{
		l=strlen(s);
		for(i=0;i<l;i++)
		{
			if(s[i]=='"')
			{
				if(t==1)
				{
					cout<<"``";
					t=0;
				}
				else if(t==0)
				{
					cout<<"''";
					t=1;
				}
			}
			else cout<<s[i];
		}
		cout<<endl;
	}
	return 0;
}