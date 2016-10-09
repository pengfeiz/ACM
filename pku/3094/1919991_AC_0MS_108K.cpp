#include <iostream>
#include <string.h>
using namespace std;
char s[300];
int main()
{
	long i,l,tt;
	while(gets(s)&&strcmp(s,"#")!=0)
	{
		tt=0;
		l=strlen(s);
		for(i=1;i<=l;i++)
			if(s[i-1]>='A'&&s[i-1]<='Z')
				tt+=i*(s[i-1]-'A'+1);
		cout<<tt<<endl;
	}
	return 0;
}
