#include <iostream>
#include <string.h>
using namespace std;

char s[110],x[300],y[300];

int main()
{
	bool java=true,c=true,t,p;
	int i,l,lx,ly;
	scanf("%s",s);
	l=strlen(s);
	t=p=false;
	if(s[0]=='_'||(s[0]<='Z'&&s[0]>='A')||s[l-1]=='_')
		goto error;
	for(i=lx=ly=0;i<l;i++)
	{
		if((t&&s[i]=='_')||(!java&&!c)||(p&&s[i]<='Z'&&s[i]>='A'))
			goto error;
		if(s[i]<='Z'&&s[i]>='A')
		{
			p=true;
			java=false;
		}
		if(java)
		{
			if(t)
			{
				if(s[i]=='_'||(s[i]>='A'&&s[i]<='Z'))
					goto error;
				x[lx++]=s[i]+'A'-'a';
				t=false;
			}
			else if(s[i]!='_')
				x[lx++]=s[i];
		}
		if(s[i]=='_')
		{
			t=true;
			c=false;
		}
		if(c)
		{
			if(p)
			{
				y[ly++]='_';
				y[ly++]=s[i]-'A'+'a';
				p=false;
			}
			else
				y[ly++]=s[i];
		}
	}
	if(java)
		printf("%s\n",x);
	else
		printf("%s\n",y);
	return 0;
error:
	printf("Error!\n");
	return 0;
}