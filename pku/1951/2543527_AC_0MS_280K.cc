#include <iostream>
using namespace std;

char s[10000];
int main()
{
	int i,l,a[26],t;
	memset(a,0,sizeof(a));
	gets(s);
	l=strlen(s);
	for(i=0;i<l;i++)
	{
		if(s[i]=='A'||s[i]=='O'||s[i]=='U'||s[i]=='I'||s[i]=='E')
			s[i]=')';
		else if(s[i]>='A'&&s[i]<='Z')
		{
			if(a[s[i]-'A'])
				s[i]=')';
			else 
				a[s[i]-'A']=true;
		}
	}
	t=0;
	for(i=0;i<l;i++)
	{
		while((s[i]==' '||s[i]==')')&&i<l)
			i++;
		if(s[i]>'Z'||s[i]<'A')
		{
			printf("%c ",s[i]);
			t=0;
			continue;
		}
		if(t)
			printf(" ");
		while(s[i]!=' '&&i<l)
		{
			if(s[i]==')')
				i++;
			else
				printf("%c",s[i++]);
			t=1;
		}
	}
	printf("\n");
	return 0;
}