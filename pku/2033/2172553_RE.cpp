#include <iostream>
using namespace std;
#define MAX 501

int a[MAX];
char s[MAX];
int main()
{
	int i,l;
	while(scanf("%s",s+1)&&strcmp(s+1,"0"))
	{
		s[0]='a';
		memset(a,0,sizeof(a));
		a[0]=1;
		a[1]=1;
		l=strlen(s);
		for(i=2;i<l;i++)
		{
			a[i]+=a[i-1];
			if(s[i-1]=='1'||(s[i-1]=='2'&&s[i]<='6'))
				a[i]+=a[i-2];
		}
		printf("%d\n",a[l-1]);
	}
	return 0;
}
				



