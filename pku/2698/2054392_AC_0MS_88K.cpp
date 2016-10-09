#include <iostream>
using namespace std;
int a[10],b[100],c[10];
int main()
{
	int n,i,k,m,j,t,w;
	scanf("%d",&k);
	while(k-->0)
	{
		t=0;
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
			scanf("%d",&b[i]);
		for(i=0;i<n;i++)
			a[i]=-1;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[j]==-1)
				{
					t++;
					a[j]=b[i];
					break;
				}
				else if(b[i]==a[j])
					break;
			}
			if(j<n)
				continue;
			memset(c,0,sizeof(c));
			for(j=0;j<n;j++)
			{
				for(w=i+1;w<m;w++)
					if(a[j]==b[w])
					{
						c[j]=w;
						break;
					}
				if(w==m)
					c[j]=m;
			}
			w=0;
			for(j=1;j<n;j++)
				if(c[j]>c[w])
					w=j;
			a[w]=b[i];
			t++;
		}
		printf("%d\n",t);
	}
	return 0;
}

	
