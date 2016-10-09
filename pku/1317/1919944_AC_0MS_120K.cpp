#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int num[300],k,i,l;
	char s[70];
	while(cin>>k&&k!=0)
	{
		cin>>s;
		l=strlen(s);
		for(i=0;i<l;i++)
		{
			if(s[i]=='_')
				num[(k*i)%l]=i%28;
			else if(s[i]=='.')
				num[(k*i)%l]=(i+27)%28;
			else 
				num[(k*i)%l]=(i+s[i]-'a'+1)%28;
		}
		for(i=0;i<l;i++)
		{
			if(num[i]==0)
				cout<<"_";
			else if(num[i]==27)
				cout<<".";
			else 
				cout<<char(num[i]+'a'-1);
		}
		cout<<endl;
	}
	return 0;
}
