#include <iostream>
using namespace std;

int a[26];

char s[100];

int main()
{
//	freopen("in.txt","r",stdin);
	int n,i,l,t,tim=0;
	scanf("%d",&n);
	getchar();
	while(gets(s))
	{
		tim++;
		memset(a,0,sizeof(a));
		l=strlen(s);
		for(i=0;i<l;i++)
			a[s[i]-'a']++;
		gets(s);
		l=strlen(s);
		for(i=0;i<l;i++)
			a[s[i]-'a']--;
		t=0;
		for(i=0;i<26;i++)
			t+=abs(a[i]);
		printf("Case #%d:  %d\n",tim,t);
	}
	return 0;
}