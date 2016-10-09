#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char s[10];
	long n1,n2,m;
	n1=0;
	n2=999999;
	while(cin>>m&&m!=0)
	{
		getchar();
		gets(s);
		if(strcmp(s,"too high")==0&&m<n2)
			n2=m;
		else if(strcmp(s,"too low")==0&&m>n1)
			n1=m;
		else if(strcmp(s,"right on")==0)
		{
			if(m<=n1||m>=n2)
				cout<<"Stan is dishonest\n";
			else
				cout<<"Stan may be honest\n";
			n1=0;
			n2=999999;
		}
	}
	return 0;
}

