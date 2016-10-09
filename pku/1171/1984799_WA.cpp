#include <stdio.h>
#include <string.h>
#include <iostream.h>
long w[26]={2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
void main()
{
	char s[8];
	long max=0,i,l,t;
	while(scanf("%s",s)!=EOF)
	{
		if(strcmp(s,".")==0)
		{
			cout<<max<<endl;
			break;
		}
		l=strlen(s);
		for(i=t=0;i<l;i++)
			t+=w[s[i]-'a'];
		if(t>max)
			max=t;
	}
}