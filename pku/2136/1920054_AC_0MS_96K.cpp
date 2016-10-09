#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int num[26],i,l,j;
	char s[100];
	for(i=0;i<26;i++)
		num[i]=0;
	for(j=0;j<4;j++)
	{
		gets(s);
		l=strlen(s);
		for(i=0;i<l;i++)
			if(s[i]<='Z'&&s[i]>='A')
				num[s[i]-'A']++;
	}
	l=0;
	for(i=0;i<26;i++)
		if(num[i]>=l)
			l=num[i];
	while(l>0)
	{
		for(i=0;i<26;i++)
		{
			if(num[i]==l)
			{
				if(i!=25)
					cout<<"* ";
				else cout<<"*\n";
				num[i]--;
			}
			else if(i!=25)
				cout<<"  ";
			else cout<<endl;
		}
		l--;
	}
	for(i=0;i<26;i++)
	{
		if(i!=25)
			cout<<(char)(i+'A')<<" ";
		else
			cout<<"Z\n";
	}
	return 0;
}