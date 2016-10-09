#include <iostream>
using namespace std;
int out[26],in[26];

char s[1002];

int main()
{
	int t,n,i;
	bool f,p,q;
	scanf("%d",&t);
	while(t--)
	{
		f=p=q=true;
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		scanf("%d",&n);
		while(n--)
		{
			scanf("%s",s);
			out[s[0]-'a']++;
			in[s[strlen(s)-1]-'a']++;
		}
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
