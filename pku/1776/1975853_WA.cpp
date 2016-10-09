#include <iostream>
using namespace std;
int a[1000][1000],b[1000],c[1000];
int main()
{
	int n,i,j,l,t,k;
	while(cin>>n)
	{
		memset(c,0,n*sizeof(int));
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				scanf("%d",&a[i][j]);
			a[i][i]=0;
		}
		t=0;
		for(i=1;i<n&&t==0;i++)
		{
			if(a[i][0]==1)
				t=1;
			if(a[0][i]==1)
				t=2;
		}
		l=2;
		if(t==1)
		{
			b[0]=i;
			b[1]=0;
		}
		else
		{
			b[0]=0;
			b[1]=i;
		}
		c[0]=1;
		c[i]=1;
		for(i=0;i<n;i++)
		{
			if(c[i]==1)
				continue;
			for(j=0;j<l;j++)
				if(a[i][b[j]]==1)
					break;
			if(j<l)
				for(k=l;k>j;k--)
					b[k]=b[k-1];
			b[j]=i;
			c[i]=1;
			l++;
		}
		printf("1\n%d\n",n);
		for(i=0;i<n;i++)
		{
			if(i)
				cout<<" ";
			cout<<b[i]+1;
		}
		cout<<endl;
	}
	return 0;
}

			
