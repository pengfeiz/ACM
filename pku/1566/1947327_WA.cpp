#include <iostream>
#include <string.h>
using namespace std;
char s[300];
int l;
int main()
{
	int i,t,p,k,ss;
	while(gets(s)&&strcmp(s,"e/o/i")!=0)
	{
		l=strlen(s);
		t=p=ss=0;
		k=1;
		for(i=0;i<=l;i++)
		{
			if(strchr("eoiuay",s[i])==NULL)
				p=0;
			else if(strchr("eoiuay",s[i])!=NULL&&p==0)
			{
				t++;
				p=1;
			}
			if(s[i]=='/'||i==l)
			{
				if(k==1&&t!=5)
				{
					ss=1;
					cout<<"1";
				}
				else if(k==2&&t!=7)
				{
					ss=1;
					cout<<"2";
				}
				else if(k==3&&t!=5)
				{
					ss=1;
					cout<<"3";
				}
				t=p=0;
				k++;
			}
		}
		if(ss==0)
			cout<<"Y";
		cout<<endl;
	}
	return 0;
}
