#include <iostream>
#include <string.h>
using namespace std;
#define x 26
char s[11];
int a[11][28];

bool judge(char s[])
{
	int i,l;
	char c;
	l=strlen(s);
	c=s[0];
	for(i=1;i<l;i++)
	{
		if(s[i]<=c)
			return true;
		c=s[i];
	}
	return false;
}

int main()
{
	int l,i,j,t;
	memset(a,0,sizeof(a));
	for(j=1;j<=10;j++)
		for(i=1;i<=x;i++)
			a[j][i]=a[j][i-1]+a[j-1][x]-a[j-1][i]+1;
	while(scanf("%s",s+1)!=EOF)
	{
		if(judge(s+1))
			printf("0\n");
		else
		{
			t=0;
			s[0]='a'-1;
			l=strlen(s+1);
			for(i=0;i<l;i++)
				t+=a[l-i][s[i+1]-'a'+1]-a[l-i][s[i]-'a'+1];
			printf("%d\n",t);
		}
	}
	return 0;
}
