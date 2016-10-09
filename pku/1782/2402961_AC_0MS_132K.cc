#include <iostream>
using namespace std;
#define MAX 10001

char s[MAX];

int main()
{
	int i,l,t;
	while(gets(s))
	{
		l=strlen(s);
		i=0;
		while(i<l)
		{
			t=1;
			while(s[i]==s[i+1]&&t<9)
			{
				t++;
				i++;
			}
			if(t>1)
			{
				printf("%c%c",t+'0',s[i]);
				i++;
			}
			else
			{
				printf("1");
				while(s[i]!=s[i+1]&&i<l)
				{
					if(s[i]=='1')
						printf("1");
					printf("%c",s[i]);
					i++;
				}
				printf("1");
			}
		}
		printf("\n");
	}
	return 0;
}

