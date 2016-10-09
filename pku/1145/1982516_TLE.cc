#include <iostream>
#include <fstream>
using namespace std;
#define MAX 100
int main()
{
	char c;
	int n,i,num[MAX],t,p,q,u;
	while(1)
	{
		cin>>n;
		getchar();
		i=t=u=0;
		num[0]=0;
		c=getchar();
		while(1)
		{
			if(c==' '||c=='\n')
			{
				if(i==0&&c=='\n')				
					break;
				c=getchar();
				continue;
			}
			if(c=='(')
			{
				i++;
				c=getchar();
			}
			else if(c==')')
			{
				i--;
				u++;
				if(num[i]==n&&u==2)
					t=1;
				c=getchar();
			}
			else
			{
				p=1;
				q=u=0;
				while(1)
				{
					if(c=='-')
						p=-1;
					else if(c<='9'&&c>='0')
						q=q*10+c-'0';
					else
						break;
					c=getchar();
				}
				q=q*p;
				num[i]=q+num[i-1];
			}
		}
		if(t==1)
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
	return 0;
}