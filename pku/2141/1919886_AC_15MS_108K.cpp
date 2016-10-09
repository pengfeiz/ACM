#include <iostream>
#include <string.h>
using namespace std;
char c[26],s[80];
int main()
{
	int l,i;
	cin>>c;
	getchar();
	gets(s);
	l=strlen(s);
	for(i=0;i<l;i++)
	{
		if(s[i]<='z'&&s[i]>='a')
			cout<<c[s[i]-'a'];
		else if(s[i]<='Z'&&s[i]>='A')
			cout<<(char)(c[s[i]-'A']+'A'-'a');
		else
			cout<<s[i];
	}
	cout<<endl;
	return 0;
}


	