#include <iostream>
#include <string.h>
using namespace std;
char s[10][31]={"125","015625","001953125","000244140625","000030517578125","000003814697265625","000000476837158203125","000000059604644775390625","000000007450580596923828125","000000000931322574615478515625"};
int main()
{
	char c[10];
	int q[31];
	int l,i,j;
	while(cin>>c)
	{
		l=strlen(c)-3;
		for(i=0;i<strlen(s[l]);i++)
			q[i]=0;
		for(i=l;i>=0;i--)
			for(j=strlen(s[i])-1;j>=0;j--)
				q[j]+=(s[i][j]-'0')*(c[i+2]-'0');
		for(i=strlen(s[l])-1;i>=0;i--)
			if(q[i]>9)
			{
				q[i-1]+=q[i]/10;
				q[i]%=10;
			}
		cout<<c<<" [8] = 0.";
		for(i=0;i<strlen(s[l]);i++)
			cout<<q[i];
		cout<<" [10]\n";
	}
	return 0;
}