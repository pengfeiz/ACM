#include <iostream>
using namespace std;
#define MAX 1005
int a[MAX],b[MAX],c[MAX],d[2*MAX];
int main()
{
//	freopen("in.txt","r",stdin);
	int na,nb,nc,n,i,j,nd,k,t;
	scanf("%d",&n);
	while(n-->0)
	{
		scanf("%d",&na);
		for(i=0;i<na;i++)
			scanf("%d",&a[i]);
		scanf("%d",&nb);
		for(i=0;i<nb;i++)
			scanf("%d",&b[i]);
		scanf("%d",&nc);
		for(i=0;i<nc;i++)
			scanf("%d",&c[i]);
		memset(d,0,sizeof(d));
		for(j=0;j<nb;j++)
			if(b[j])
				for(k=0;k<na;k++)
					d[j+k]+=a[k];
		nd=nb+na-1;
		for(i=nd-1;i>0;i--)
			d[i]%=2;
		t=0;
		for(i=0;i<=nd-nc;i++)
		{
			if(d[i])
				for(j=0;j<nc;j++)
				{
					d[i+j]+=c[j];
					d[i+j]%=2;
				}
		}
		for(i=nd-nc;i<nd;i++)
			if(d[i])
				break;
		printf("%d",nd-i);
		for(;i<nd;i++)
			printf(" %d",d[i]);
		printf("\n");
	}
	return 0;
}







