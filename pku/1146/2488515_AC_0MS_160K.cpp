#include <iostream>
#include <algorithm>
using namespace std;
bool com(char a,char b)
{return b>a;}
char a[1025];
int main()
{
	int l,i;
	while(scanf("%s",a),strcmp(a,"#"))
	{
		l=strlen(a);
		next_permutation(a,a+l,com);
		a[l]=127;
		for(i=0;i<l;i++)
			if(a[i]>a[i+1])
				break;
		a[l]='\0';
		if(i==l)
			printf("No Successor\n");
		else
			printf("%s\n",a);
	}
	return 0;
}


