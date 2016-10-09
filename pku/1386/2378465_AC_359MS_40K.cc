#include <iostream>
using namespace std;
int out[26],in[26];
bool b[26][26],c[26];

char s[1002];

void judge(int x)
{
	int i;
	if(c[x])
		return;
	c[x]=true;
	for(i=0;i<26;i++)
		if(b[x][i]||b[i][x])
			judge(i);
}

int main()
{
	int t,n,i,l;
	bool f,p,q;
	scanf("%d",&t);
	while(t--)
	{
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		f=p=q=true;
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		scanf("%d",&n);
		while(n--)
		{
			scanf("%s",s);
			out[s[0]-'a']++;
			l=strlen(s);
			in[s[l-1]-'a']++;
			b[s[0]-'a'][s[l-1]-'a']=true;
		}
		for(i=0;i<26;i++)
			if(in[i]||out[i])
			{
				judge(i);
				break;
			}
		for(i=0;i<26;i++)
			if(!c[i]&&(in[i]||out[i]))
				f=false;
		for(i=0;f&&i<26;i++)
		{
			if(in[i]==out[i])
				continue;
			if(in[i]==out[i]+1&&p)
			{
				p=false;
				continue;
			}
			if(in[i]==out[i]-1&&q)
			{
				q=false;
				continue;
			}
			f=false;
		}
		if(f)
			printf("Ordering is possible.\n");
		else
			printf("The door cannot be opened.\n");
	}
	return 0;
}
