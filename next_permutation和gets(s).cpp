#include <iostream>
#include <algorithm>
using namespace std;
bool com(char a,char b)
{return b>a;}
char a[1025];
int main()
{
    /*
	int l,i;
	while(scanf("%s",a),strcmp(a,"#"))
	{
		l=strlen(a);
		next_permutation(a,a+l,com);
		printf("%s\n",a);
	}*/
	
	char s[33];
	gets(s);
	printf("%s",s);
	system("pause");
	return 0;
}
