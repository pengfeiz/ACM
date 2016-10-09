#include <iostream>
#include <string.h>
using namespace std;
char s[7];
int main()
{
	int l,i,nn,k,w,tt,j;
	cin>>nn;
	for(k=1;k<=nn;k++)
	{
		if(k-1)
			cout<<endl;
		cout<<"Scenario #"<<k<<":\n";
		cin>>s;
		l=strlen(s);
		tt=0;
		if(l%3==0)
			j=1;
		else j=0;
		for(i=0;i<l;i++)
		{
			if(s[i]=='?')
				w=i;
			else if((i+j)%3==0)
				tt+=(s[i]-'0')*9;
			else if((i+j)%3==2)
				tt+=(s[i]-'0')*3;
			else
				tt+=(s[i]-'0')*7;
		}
		if((w+j)%3==0)
			s[w]=tt%10+'0';
		else if((w+j)%3==2)
		{
			if(tt%10<=3)
				s[w]=tt%10*3+'0';
			else if(tt%10<=6)
				s[w]=(tt%10-3)*3-1+'0';
			else s[w]=(tt%10-6)*3-2+'0';
		}
		else if((w+j)%3==1)
		{
			if(tt%10==0)
				s[w]='0';
			else if(tt%10==1)
				s[w]='7';
			else if(tt%10==2)
				s[w]='4';
			else if(tt%10==3)
				s[w]='1';
			else if(tt%10==4)
				s[w]='8';
			else if(tt%10==5)
				s[w]='5';
			else if(tt%10==6)
				s[w]='2';
			else if(tt%10==7)
				s[w]='9';
			else if(tt%10==8)
				s[w]='6';
			else s[w]='3';
		}
		cout<<s<<endl;
	}
	return 0;
}

