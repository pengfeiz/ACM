#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;
int main()
{
	char *s1,*s2;
	int l1,l2,i,j;
	s1=(char *)malloc(100000*sizeof(char));
	s2=(char *)malloc(100000*sizeof(char));
	while(cin>>s1>>s2)
	{
		l1=strlen(s1);
		l2=strlen(s2);
		for(i=j=0;i<l2;i++)
		{
			if(*(s1+j)==*(s2+i))
				j++;
		}
		if(j==l1)
			cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}


