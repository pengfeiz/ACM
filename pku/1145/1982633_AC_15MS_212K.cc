#include <iostream>
using namespace std;
#define MAX 20000
int main()
{
	char c,s[MAX];
	long n,i,num[MAX],t,p,q,u,o,nn;
	while(scanf("%ld",&n)!=EOF)
	{
		i=t=u=0;
		num[0]=0;
		scanf("%c",&c);
		while(c!='(')
			scanf("%c",&c);
		s[0]='(';
		q=p=1;
		while(p>0)
		{
			scanf("%c",&c);
			if(c>='0'&&c<='9'||c=='('||c==')'||c=='-')
			{				
				s[q]=c;
				q++;
				if(c=='(') 
					p++;
				else if(c==')')
					p--;
			}
		}
		nn=q;
		o=0;
		while(o<nn)
		{
			if(s[o]=='(')
			{
				i++;
				o++;
			}
			else if(s[o]==')')
			{
				i--;
				u++;
				if(num[i]==n&&u==2)
					t=1;
				o++;
			}
			else
			{
				p=1;
				q=u=0;
				while(1)
				{
					if(s[o]=='-')
						p=-1;
					else if(s[o]<='9'&&s[o]>='0')
						q=q*10+s[o]-'0';
					else
						break;
					o++;
				}
				q=q*p;
				num[i]=q+num[i-1];
			}
		}
		if(t==1)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}