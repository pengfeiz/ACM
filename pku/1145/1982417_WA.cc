#include <iostream>
#include <fstream>
using namespace std;
#define MAX 100
int main()
{
//	ifstream cin("input.txt");
	char c;
	int n,i,num[MAX],t,p,q,mm;
	while(cin>>n)
	{
		getchar();
		i=t=mm=0;
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
				if(num[i]==n&&i>=mm)
				{
					t=1;
					mm=i;
				}
				if(i>mm+1)
					t=0;
				i--;
				c=getchar();
			}
			else
			{
				p=1;
				q=0;
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