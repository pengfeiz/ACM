#include <iostream>
#include <string.h>
using namespace std;
char s[10][10];
int main()
{
	char c[10];
	int a,b,i,j;
	while(cin>>c&&strcmp(c,"ENDOFINPUT")!=0)
	{
		cin>>a>>b;
		for(i=0;i<a;i++)
			cin>>s[i];
		for(i=0;i<a-1;i++)
		{
			for(j=0;j<b-1;j++)
				cout<<(int)(s[i][j]-'0'+s[i][j+1]-'0'+s[i+1][j]-'0'+s[i+1][j+1]-'0')/4;
			cout<<endl;
		}
		cin>>c;
	}
	return 0;
}


