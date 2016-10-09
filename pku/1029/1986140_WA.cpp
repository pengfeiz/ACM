#include <iostream>
using namespace std;
int main()
{
	int a[1001],b[100],d[100],n,m,i,k,f[1001];
	char c;
	while(cin>>n>>k)
	{
		memset(a,0,sizeof(a));
		while(k-->0)
		{
			memset(f,0,sizeof(f));
			cin>>m;
			for(i=0;i<m;i++)
				scanf("%d",&b[i]);
			for(i=0;i<m;i++)
				scanf("%d",&d[i]);
			cin>>c;
			if(c=='=')
				for(i=0;i<m;i++)
					a[b[i]]=a[d[i]]=2;
			else if(c=='>')
			{
				for(i=0;i<m;i++)
				{
					if(a[b[i]]==0)
						a[b[i]]=3;
					else if(a[b[i]]!=3)
						a[b[i]]=2;
					if(a[d[i]]==0)
						a[d[i]]=1;
					else if(a[d[i]]!=1)
						a[d[i]]=2;
					f[b[i]]=f[d[i]]=1;
				}
				for(i=1;i<=n;i++)			
					if(f[i]==0)
						a[i]=2;
			}
			else
			{
				for(i=0;i<m;i++)
				{
					if(a[d[i]]==0)
						a[d[i]]=3;
					else if(a[d[i]]!=3)
						a[d[i]]=2;
					if(a[b[i]]==0)
						a[b[i]]=1;
					else if(a[b[i]]!=1)
						a[b[i]]=2;
					f[b[i]]=f[d[i]]=1;
				}
				for(i=1;i<=n;i++)
					if(f[i]==0)
						a[i]=2;
			}
		}
		k=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]!=2&&k)
				break;
			if(a[i]!=2)
				k=i;
		}
		if(k==0||i<-n)
			cout<<0<<endl;
		else
			cout<<k<<endl;
	}
	return 0;
}




	
