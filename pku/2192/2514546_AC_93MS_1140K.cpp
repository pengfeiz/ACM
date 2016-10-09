#include <iostream>
using namespace std;
#define MAX 1001
char s1[MAX],s2[MAX],s3[MAX];
bool c[MAX][MAX];

int min(int a,int b)
{return a<b?a:b;}

int main()
{
	int t,i,j,top,l1,l2,l3,tim;
	scanf("%d",&t);
	for(tim=1;tim<=t;tim++)
	{
		memset(c,0,sizeof(c));
		top=0;
		scanf("%s%s%s",s1+1,s2+1,s3+1);
		l1=strlen(s1+1);
		l2=strlen(s2+1);
		l3=strlen(s3+1);
		c[0][0]=true;
		for(i=1;i<=l3;i++)
		{
			for(j=1;j<=i;j++)
				if(c[i-1][j-1])
				{
					if(j<=l1&&s1[j]==s3[i])
						c[i][j]=true;
					if(i-j+1<=l2&&s2[i-j+1]==s3[i])
						c[i][j-1]=true;
				}
		}
		for(i=1;i<=l1;i++)
			if(c[l3][i])
				break;
		if(i>l1)
			printf("Data set %d: no\n",tim);
		else
			printf("Data set %d: yes\n",tim);
	}
	return 0;
}