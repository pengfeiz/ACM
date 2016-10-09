#include <iostream>
using namespace std;
long a[26][26];
int b[26];
int main()
{
	int n,i,j,m;
	long tt,t,min,x;
	char c,c1;
	while(cin>>n&&n)
	{
		tt=0;
		t=1;
		for(i=0;i<n;i++)
		{
			b[i]=0;
			for(j=0;j<n;j++)
				a[i][j]=99999;
		}
		for(i=0;i<n-1;i++)
		{
			cin>>c1;
			cin>>m;
			for(j=0;j<m;j++)
			{
				cin>>c>>min;
				if(min<a[c-'A'][c1-'A'])
					a[c-'A'][c1-'A']=a[c1-'A'][c-'A']=min;
			}
		}
		b[0]=1;
		while(t++<n)
		{
			min=99999;
			for(i=0;i<n;i++)
			{
				if(b[i]==1)
				{
					for(j=0;j<n;j++)
						if(b[j]==0&&a[i][j]<min)
						{
							x=j;
							min=a[i][j];
						}
				}
			}
			b[x]=1;
			tt+=min;
		}
		cout<<tt<<endl;
	}
	return 0;
}


				
		
