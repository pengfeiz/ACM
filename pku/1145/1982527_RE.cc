#include <iostream>
using namespace std;
#define MAX 10000
int main()
{
	char c;
	long n,i,num[MAX],t,p,q,u;
	while(scanf("%ld",&n)!=EOF)
	{
		i=t=u=0;
		num[0]=0;
		scanf("%c",&c);
		while(1)
		{
			if(c==' '||c=='\n')
			{
				if(i==0&&c=='\n')				
					break;
				scanf("%c",&c);
				continue;
			}
			if(c=='(')
			{
				i++;
				scanf("%c",&c);
			}
			else if(c==')')
			{
				i--;
				u++;
				if(num[i]==n&&u==2)
					t=1;
				scanf("%c",&c);
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
					scanf("%c",&c);
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