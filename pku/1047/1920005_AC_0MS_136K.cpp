#include <iostream>
#include <string.h>
using namespace std;
char s[100];
int num[100][100],nn[10],n[10];
int main()
{
	int l,i,j,t;
	while(cin>>s)
	{
		t=0;
		l=strlen(s);
		for(i=0;i<l;i++)
			num[0][i]=s[i]-'0';
		for(i=0;i<10;i++)
			n[i]=0;
		for(i=0;i<l;i++)
			n[num[0][i]]++;
		for(i=1;i<l&&t==0;i++)
		{
			for(j=0;j<10;j++)
				nn[j]=n[j];
			for(j=0;j<l;j++)
				num[i][j]=num[i-1][j]+num[0][j];
			for(j=l-1;j>0;j--)
				if(num[i][j]>9)
				{
					num[i][j-1]+=num[i][j]/10;
					num[i][j]%=10;
				}
			if(num[i][0]>9)
				t=1;
			for(j=0;j<l&&t==0;j++)
			{
				nn[num[i][j]]--;
				if(nn[num[i][j]]<0)
					t=1;
			}
		}
		if(t==1)
			cout<<s<<" is not cyclic\n";
		else
			cout<<s<<" is cyclic\n";
	}
	return 0;
}

			
		