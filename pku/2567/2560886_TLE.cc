#include <iostream>
#include <string.h>
using namespace std;


string s;
char c[1001];
int a[101],n;
int b[101];
bool d[101][101];


void solve(string s)
{
	int i,m;
	bool f,ff;
	ff=false;
	while(s.find_first_of(")")!=s.length()-1)
	{
		m=-1;
		while(s.find_first_of(" ")^0xffffffff)
			s.erase(s.find_first_of(" "),1);
		for(i=0;i<s.length();i++)
		{
			if(s[i]=='(')
				f=true;
			else if(s[i]==')')
			{
				if(f)
				{
					d[a[m]][a[m-1]]=d[a[m-1]][a[m]]=true;
					b[a[m-1]]++;
					b[a[m]]++;
					s[i]=s[i-1]=' ';
					if(s[i-2]>='0'&&s[i-2]<='9')
						s[i-2]=s[i-3]=' ';
					else
						s[i-2]=' ';
				}
				m--;
				f=false;
			}
			else
			{
				a[++m]=s[i]-'0';
				if(s[i+1]>='0'&&s[i+1]<='9')
				{
					a[m]=a[m]*10+s[i+1]-'0';
					i++;
				}
				if(a[m]>n)
					n=a[m];
			}
		}
	}
}


void out()
{
	int i,q=n-1,j;
	bool f;
	f=false;
	while(q)
	{
		for(i=1;i<=n;i++)
		{
			if(b[i]==1)
			{
				b[i]--;
				if(f)
					printf(" ");
				for(j=1;j<=n;j++)
					if(d[i][j]&&b[j]>0)
					{
						printf("%d",j);
						b[j]--;
						break;
					}
				f=true;
				break;
			}
		}
		q--;
	}
	printf("\n");
}


int main()
{
	while(gets(c))
	{
		n=0;
		memset(b,0,sizeof(b));
		memset(d,0,sizeof(d));
		s=c;
		solve(s);
		out();
	}
	return 0;
}