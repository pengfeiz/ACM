#include <iostream>
using namespace std;
int main()
{
	char s[40];
	int i,l,j,s1[10],s2[10],s3[10],s4[10];
	while(scanf("%s",s)!=EOF)
	{
		memset(s1,0,sizeof(s1));
		memset(s3,0,sizeof(s1));
		memset(s2,0,sizeof(s1));
		memset(s4,0,sizeof(s1));
		l=strlen(s);
		for(i=j=0;i<l;i++,j++)
		{
			if(s[i]=='+')
				break;
			s1[j]=s[i]-'0';
		}
		i++;
		for(j=0;i<l;i++,j++)
		{
			if(s[i]=='=')
				break;
			s2[j]=s[i]-'0';
		}
		i++;
		for(j=0;i<l;i++,j++)
			s3[j]=s[i]-'0';
		for(i=0;i<10;i++)
			s4[i]=s1[i]+s2[i];
		for(i=0;i<9;i++)
		{
			s4[i+1]+=s4[i]/10;
			s4[i]%=10;
		}
		for(i=0;i<10;i++)
			if(s3[i]!=s4[i])
				break;
		if(i!=10)
			printf("False\n");
		else
			printf("True\n");
	}
	return 0;
}
