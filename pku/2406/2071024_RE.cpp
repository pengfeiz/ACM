#include <iostream>
using namespace std;
#define MAX 100000
char s[MAX];
int main()
{
	int l,i,j;
	while(scanf("%s",s)&&strcmp(s,"."))
	{
		l=strlen(s);
		for(i=1;i<=l;i++)
		{
			if(!(l%i))
			{
				for(j=i;j<l;j++)
					if(s[j%i]!=s[j])
						break;
				if(j==l)
					break;
			}
		}
		printf("%d\n",l/i);
	}
	return 0;
}
	