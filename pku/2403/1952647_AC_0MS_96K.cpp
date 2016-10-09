#include <iostream>
#include <string.h>
using namespace std;
struct gao
{
	char s[20];
	long n;
}lin[1000];
int main()
{
	long nn,n,i,tt;
	char s[20];
	cin>>nn>>n;
	for(i=0;i<nn;i++)
		cin>>lin[i].s>>lin[i].n;
	while(n-->0)
	{
		tt=0;
		while(cin>>s&&strcmp(s,"."))
		{
			for(i=0;i<nn;i++)
				if(strcmp(s,lin[i].s)==0)
					break;
			if(i!=nn)
				tt+=lin[i].n;
		}
		cout<<tt<<endl;
	}
	return 0;
}
