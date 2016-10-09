#include <iostream>
#include <string.h>
using namespace std;
char s[5001];
short num[5002][5002];
short min(short a,short b)
{
	return a>b?b:a;
}
int main()
{
	int l,i,j;
	short t,p;
	while(cin>>l)
	{
		t=p=0;
		cin>>s+1;
		for(i=0;i<=l+1;i++)
			for(j=0;j<=l+1;j++)
				num[i][j]=0;
		for(i=1;i<=l;i++)
			for(j=l;j>0;j--)
			{
				if(s[i]==s[j])
					num[i][j]=num[i-1][j+1];
				else
					num[i][j]=min(num[i-1][j],num[i][j+1])+1;
			}
		cout<<num[l][1]<<endl;
	}
	return 0;
}


