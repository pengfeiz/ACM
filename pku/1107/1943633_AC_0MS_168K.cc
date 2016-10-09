#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char s[80],c,cc;
	int l,i,a[80],k1,k2,k3,j;
	while(cin>>k1>>k2>>k3&&(k1||k2||k3))
	{
		cin>>s;
		l=strlen(s);
		for(i=0;i<l;i++)
		{
			if(s[i]>='a'&&s[i]<='i')
				a[i]=0;
			else if(s[i]>='j'&&s[i]<='r')
				a[i]=1;
			else
				a[i]=2;
		}
		while(k1-->0)
		{
			for(j=0;j<l;j++)
				if(a[j]==0)
					break;
			c=s[j];
			for(i=j;i<l;i++)
				if(a[i]==0)
				{
					cc=s[i];
					s[i]=c;
					c=cc;
				}
			s[j]=c;
		}
		while(k2-->0)
		{
			for(j=0;j<l;j++)
				if(a[j]==1)
					break;
			c=s[j];
			for(i=j;i<l;i++)
				if(a[i]==1)
				{
					cc=s[i];
					s[i]=c;
					c=cc;
				}
			s[j]=c;
		}
		while(k3-->0)
		{
			for(j=0;j<l;j++)
				if(a[j]==2)
					break;
			c=s[j];
			for(i=j;i<l;i++)
				if(a[i]==2)
				{
					cc=s[i];
					s[i]=c;
					c=cc;
				}
			s[j]=c;
		}
		cout<<s<<endl;
	}
	return 0;
}






