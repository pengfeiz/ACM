#include <iostream>
using namespace std;
#define MAX 676
bool a[MAX];
int main()
{
	char s[80],i,l,j,t;
	while(scanf("%s",s)&&strcmp(s,"*"))
	{
		l=strlen(s);
		t=1;
		for(i=1;i<l;i++)
		{
			memset(a,0,sizeof(a));
			for(j=0;j+i<l;j++)
			{
				if(a[(s[j]-'A')*26+(s[j+i]-'A')])
				{
					t=0;
					goto write;
				}
				a[(s[j]-'A')*26+(s[j+i]-'A')]=true;
			}
		}
write:
		if(t)
			printf("%s is surprising.\n",s);
		else
			printf("%s is NOT surprising.\n",s);
	}
	return 0;
}

