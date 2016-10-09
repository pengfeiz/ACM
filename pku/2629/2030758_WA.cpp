#include <iostream>
using namespace std;
#define MAX 1001
int a[MAX][MAX];
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int l1,l2,i,j,t;
	char s1[MAX],s2[MAX];
	while(cin>>s1>>s2)
	{
		memset(a,0,sizeof(a));
		l1=strlen(s1);
		l2=strlen(s2);
		for(i=1;i<=l1;i++)
			for(j=1;j<=l2;j++)
			{
				t=max(a[i-1][j],a[i][j-1]);
				if(s1[i-1]==s2[j-1]&&a[i-1][j-1]+1>t)
					t=a[i-1][j-1]+1;
				a[i][j]=t;
			}
		t=a[l1][l2];
		i=l1;
		j=l2;
		if(!t)
			continue;
		while(t>0)
		{
			if(s1[i-1]!=s2[j-1])
			{
				if(a[i-1][j]==a[i][j-1])
				{
					if(s1[i-1]>s2[j-1])
						i--;
					else
						j--;
				}
				else if(a[i-1][j]>a[i][j-1])
					i--;
				else
					j--;
			}
			else
			{
				printf("%c",s2[j-1]);
				t--;
				i--;
				j--;
			}
		}
		printf("\n");
	}
	return 0;
}
			
