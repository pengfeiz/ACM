#include <iostream>
using namespace std;

char s[10000001];
bool f[300];

int main()
{
//	freopen("2.txt","r",stdin);
	memset(f,0,sizeof(f));
	int t,i,l,ll;
	char ss[101];
	l=0;
	while(gets(ss))
	{
		ll=strlen(ss);
		for(i=0;i<ll;i++)
		{
			if(ss[i]!=' '&&ss[i]!='\n'&&ss[i]!='\t')
				s[l++]=ss[i];
		}
	}
	t=0;
	for(i=0;i<l;i++)
	{
		if(s[i]=='\'')
		{
			if(s[i+1]=='\'')
			{
				f[256]=true;
				i++;
			}
			else
				f[263]=true;
		}
		else if(s[i]=='`')
		{
			if(s[i+1]=='`')
			{
				f[257]=true;
				i++;
			}
			else
				f[262]=true;
		}
		else if(s[i]=='f')
		{
			if(s[i+1]=='i')
			{
				f[258]=true;
				i++;
			}
			else if(s[i+1]=='l')
			{
				f[259]=true;
				i++;
			}
			else if(s[i+1]=='f')
			{
				if(s[i+2]=='i')
				{
					f[260]=true;
					i+=2;
				}
				else if(s[i+2]=='l')
				{
					f[267]=true;
					i+=2;
				}
				else
				{
					f[261]=true;
					i++;
				}
			}
			else
				f[s[i]]=true;
		}
		else
			f[s[i]]=true;
	}
	for(i=0;i<300;i++)
		if(f[i])
			t++;
	printf("%d\n",t);
	return 0;
}
