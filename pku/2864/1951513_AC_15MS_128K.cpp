#include <iostream>
using namespace std;
int a[100];
int main()
{
	int n,m,i,j,k;
	while(cin>>n>>m&&(n||m))
	{
		for(i=0;i<n;i++)
			a[i]=0;
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
			{
				scanf("%d",&k);
				if(k==1)
					a[j]++;
			}
		for(i=0;i<n;i++)
			if(a[i]==m)
				break;
		if(i==n)
			cout<<"no\n";
		else
			cout<<"yes\n";
	}
	return 0;
}