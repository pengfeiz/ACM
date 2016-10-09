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
	int n,i,j,l,t,k;
	cin>>l;
	while(l-->0)
	{
		cin>>n;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				b[i][j]=0;
		for(j=1;j<n;j++)
			for(i=0;i+j<n;i++)			
			{
				t=0;
				for(k=i;k<j;k++)
					if(b[i][k]+b[k+i+1][j+i]>t)
						t=b[i][k]+b[k+i+1][j+i];
				if(a[i]==a[i+j])
					b[i][i+j]=max(t,b[i+1][i+j-1]+1);	
				else
					b[i][i+j]=t;
			}
		cout<<t<<endl;
	}
	return 0;
}

