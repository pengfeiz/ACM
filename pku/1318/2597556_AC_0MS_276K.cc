#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 101

struct gao
{
	char s[7];
	int a[26];
}a[MAX];

int n,m;

bool com(gao a,gao b)
{return strcmp(a.s,b.s)<0;}

int main()
{
	char ss[7];
	int b[26];
	bool f;
	int i,l,j;
	n=m=0;
	while(scanf("%s",a[n].s),strcmp(a[n].s,"XXXXXX"))
	{
		memset(a[n].a,0,sizeof(a[0].a));
		l=strlen(a[n].s);
		for(i=0;i<l;i++)
			a[n].a[a[n].s[i]-'a']++;
		n++;
	}
	sort(a,a+n,com);
	while(scanf("%s",ss),strcmp(ss,"XXXXXX"))
	{
		f=true;
		memset(b,0,sizeof(b));
		l=strlen(ss);
		for(i=0;i<l;i++)
			b[ss[i]-'a']++;
		for(i=0;i<n;i++)
		{
			for(j=0;j<26;j++)
				if(a[i].a[j]!=b[j])
					break;
			if(j==26)
			{
				f=false;
				printf("%s\n",a[i].s);
			}
		}
		if(f)
			printf("NOT A VALID WORD\n");
		printf("******\n");
	}
	return 0;
}