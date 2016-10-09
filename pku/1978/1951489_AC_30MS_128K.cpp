#include <iostream>
using namespace std;
int main()
{
	int a[51],n,i,m,k,p,c,j,s;
	while(cin>>n>>m&&(n||m))
	{
		for(i=0;i<n;i++)
			a[i]=n-i;
		for(k=0;k<m;k++)
		{
			cin>>p>>c;
			for(i=0;i<c;i++)
			{
				s=a[i+p-1];
				for(j=p+i-1;j>i;j--)
					a[j]=a[j-1];
				a[i]=s;
			}
		}
		cout<<a[0]<<endl;
	}
	return 0;
}




				