#include <iostream>
using namespace std;
#define MAX 1000
int a[MAX],b[MAX][MAX];	
int max(int a,int b)
{
	return a>b?a:b;
}		
int main()
{
	int n,i,j,l,t;
	cin>>l;
	while(l-->0)
	{
		cin>>n;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
			b[i][i]=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				b[i][j]=0;
		for(j=1;j<n;j++)
			for(i=0;i+j<n;i++)			
			{
				t=max(b[i+1][i+j],b[i][i+j-1]);
				if(a[i]==a[i+j])
					b[i][i+j]=max(t,b[i+1][i+j-1]+1);	
				else
					b[i][i+j]=t;
			}
		t=b[0][n-1];
		for(i=0;i<n-1;i++)
			if(b[0][i]+b[i+1][n-1]>t)
				t=b[0][i]+b[i+1][n-1];
		cout<<t<<endl;
	}
	return 0;
}

