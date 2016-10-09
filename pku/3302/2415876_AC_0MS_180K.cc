#include<iostream>
using namespace std;
int main()
{
	char s1[101],s2[101],s3[101];
    int len1,len2;
	int i,j;
	bool t,u;
	int test;
	cin>>test;
	while(test--)
	{
		scanf("%s %s",&s2,&s1);
		t=false;
		u=false;
		int k=0;
		j=0;
		len1=strlen(s1);
		len2=strlen(s2);
		for(i=len1-1;i>=0;i--)
			s3[k++]=s1[i];
		for(i=0;i<len1&&j<len2;i++)
		{
			while(s1[i]!=s2[j++])
				;
		}
		if(i==len1&&j<=len2)
		     t=true;
		else
			t=false;
		j=0;
		for(i=0;i<len1&&j<len2;i++)
		{
			while(s3[i]!=s2[j++])
				;
		}
		if(i==len1&&j<=len2)
			u=true;
		else
			u=false;
		if(t||u)
			printf("YES\n");
		else
           printf("NO\n");
	} 
	return 0;
}
