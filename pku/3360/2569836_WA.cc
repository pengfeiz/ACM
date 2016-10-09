#include <iostream>
using namespace std;

int a[512];
//char s[1000001];
int main()
{
	freopen("in.txt","r",stdin);
	char ss[100];
	int i,l;
	int p,q;
	while(scanf("%s",ss)!=EOF)
	{
		scanf("%s",ss);
		p=q=0;
		memset(a,0,sizeof(a));
/*		gets(s);
		l=strlen(s);
		for(i=0;i<l;i++)
			if(s[i]=='}')
				break;
		for(;i<l;i++)
			if(s[i]=='{')
				break;
		for(i;i<l;i++)
		{
			if(s[i]=='('||s[i]==')'||s[i]==','||s[i]==' '||s[i]=='{'||s[i]=='}')
				continue;
			a[s[i]]++;
		}*/
		while(scanf("%s",ss),strcmp(ss,"}"));
		while(scanf("%s",ss),strcmp(ss,"{"));
		while(scanf("%s",ss))
		{
			l=strlen(ss);
			a[ss[1]]++;
			a[ss[3]]++;
			if(l==5)
				break;
		}
		scanf("%s",ss);
		for(i=0;i<512;i++)
		{
			if(a[i])
				q=1;
			if(a[i]&1)
				p++;
		}
		if(p==2)
			printf("YES ");
		else
			printf("NO ");
		if(p==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
