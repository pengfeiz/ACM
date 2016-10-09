#include <iostream>
#include <string.h>
using namespace std;
int num[30],num2[30];
char s[30][8];
int main()
{
	int nn,i,m,n,c1,c2,j;
	cin>>nn;
	while(nn-->0)
	{
		cin>>n>>m;
		for(i=0;i<n;i++)
		{
			cin>>s[i];
			num[i]=i;
			num2[i]=-1;
		}
		for(i=0;i<m;i++)
		{
			cin>>c1>>c2;
			num[c1-1]=-1;
			num2[c2-1]=c1-1;
		}
		for(i=j=0;i<n;i++)
		{
			if(num[i]==-1)
				continue;
			while(num2[j]!=-1)
				j++;
			num2[j]=i;
		}
		for(i=0;i<n;i++)
		{
			if(i)
				cout<<" ";
			cout<<s[num2[i]];
		}
		cout<<endl;
	}
	return 0;
}

