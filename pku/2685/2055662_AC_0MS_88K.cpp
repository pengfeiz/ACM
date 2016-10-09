#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
int ju(char c)
{
	if(c=='i')
		return 1;
	if(c=='x')
		return 10;
	if(c=='c')
		return 100;
	return 1000;
}
int main()
{
	char s1[10],s2[10];
	int n,l1,l2,i,t;
	scanf("%d",&n);
	while(n-->0)
	{
		t=0;
		scanf("%s%s",s1,s2);
		l1=strlen(s1);
		l2=strlen(s2);
		for(i=0;i<l1;i++)
		{
			if(s1[i]>'1'&&s1[i]<='9')
			{
				t+=(s1[i]-'0')*ju(s1[i+1]);
				i++;
			}
			else
				t+=ju(s1[i]);
		}
		for(i=0;i<l2;i++)
		{
			if(s2[i]>'1'&&s2[i]<='9')
			{
				t+=(s2[i]-'0')*ju(s2[i+1]);
				i++;
			}
			else
				t+=ju(s2[i]);
		}
		if(t>999)
		{
			if(t>1999)
				printf("%d",t/1000);
			printf("m");
			t%=1000;
		}
		if(t>99)
		{
			if(t>199)
				printf("%d",t/100);
			printf("c");
			t%=100;
		}
		if(t>9)
		{
			if(t>19)
				printf("%d",t/10);
			printf("x");
			t%=10;
		}
		if(t>0)
		{
			if(t>1)
				printf("%d",t);
			printf("i");
		}
		printf("\n");
	}
	return 0;
}

				