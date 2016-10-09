#include <iostream>
#include <algorithm>
using namespace std;
bool com1(char a,char b)
{return b>a;}
bool com2(char a,char b)
{return b<a;}
char a[101];
int main()
{
	int l,i,j,ma;
	char s[21][100];
	int b[21];
	while(scanf("%s",a)!=EOF)
	{
		memset(b,127,sizeof(b));
		l=strlen(a);
		for(i=0;i<10;i++)
			next_permutation(a,a+l,com2);
		for(i=0;i<21;i++)
		{
			strcpy(s[i],a);
			next_permutation(a,a+l,com1);
		}
		l=strlen(a);
		for(i=0;i<21;i++)
			for(j=0;j<l-1;j++)
			{
				if(abs(s[i][j]-s[i][j+1])<b[i])
					b[i]=abs(s[i][j]-s[i][j+1]);
			}
		ma=0;
		for(i=0;i<21;i++)
			if(b[i]>b[ma])
				ma=i;
		printf("%s%d\n",s[ma],b[ma]);
	}
	return 0;
}
