#include <iostream>
using namespace std;
#define MAX 1001
int main()
{
	int l1,l2,i,j,a[26],b[26];
	char s1[MAX],s2[MAX];
	while(gets(s1))
	{
		gets(s2);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		l1=strlen(s1);
		l2=strlen(s2);
		for(i=0;i<l1;i++)
			a[s1[i]-'a']++;
		for(i=0;i<l2;i++)
			b[s2[i]-'a']++;
		for(i=0;i<26;i++)
			for(j=0;j<a[i]&&j<b[i];j++)
				printf("%c",i+'a');
		printf("\n");
	}
	return 0;
}
			
