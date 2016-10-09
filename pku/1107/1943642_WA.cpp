#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char s[80],c,cc;
	int l,i,a[80],k[3],j,t;
	while(cin>>k[0]>>k[1]>>k[2]&&(k[0]||k[1]||k[2]))
	{
		cin>>s;
		l=strlen(s);
		for(i=0;i<l;i++)
		{
			if(s[i]>='a'&&s[i]<='i')
				a[i]=0;
			else if(s[i]>='j'&&s[i]<='r')
				a[i]=1;
			else if((s[i]>='s'&&s[i]<='z')||s[i]=='_')
				a[i]=2;
		}
		for(t=0;t<3;t++)
		{
			while(k[t]-->0)
			{
				for(j=0;j<l;j++)
					if(a[j]==t)
						break;
				c=s[j];
				for(i=j;i<l;i++)
					if(a[i]==t)
					{
						cc=s[i];
						s[i]=c;
						c=cc;
					}
				s[j]=c;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}






