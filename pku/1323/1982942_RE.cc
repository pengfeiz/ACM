#include <iostream>
using namespace std;
#define MAX 100
int main()
{
	int a[MAX],n,m,i,b[50],j,k,t,q,time=0;
	while(cin>>n>>m&&(n||m))
	{
		time++;
		cout<<"Case "<<time<<": ";
		t=0;
		memset(a,0,sizeof(a));
		for(i=0;i<m;i++)
		{
			cin>>b[i];
			a[b[i]]=1;
		}
		for(i=0;i<m-1;i++)
			for(j=i+1;j<m;j++)
				if(b[i]<b[j])
					swap(b[i],b[j]);
		j=n*m;
		k=1;
		for(i=0;i<m;i++)
		{
			while(a[j]==1)
				j--;
			if(b[i]<j)
			{
				a[j]=1;
				q=n-2;
				while(q-->0)
				{
					while(a[k]==1)
						k++;
					a[k]=1;
				}
			}
			else
			{
				q=n-1;
				while(q-->0)
				{
					while(a[k]==1)
						k++;
					a[k]=1;
				}
				t++;
			}
		}
		cout<<t<<endl;
	}
	return 0;
}



