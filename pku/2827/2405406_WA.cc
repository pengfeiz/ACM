#include <iostream>
#include <algorithm>
using namespace std;
int e[10000][3],pe[20000],m,n,a[20000],c[20000];
int sear(int v)
{
	int l,r,k;
	l=0; r=m-1;
	while (l<r)
	{
		k=(l+r)/2;
		if (pe[k]==v) return k;
		if (pe[k]<v) l=k+1;
		else r=k-1;
	}
	return l;
}
int findways(int v)
{
	int ch,i,l;
	i=v; l=0; 
	while (a[i]!=i) l+=c[i],i=a[i];
	while (v!=i)
	{
		ch=l-c[v]; c[v]=l; l=ch;
		ch=a[v]; a[v]=i; v=ch;
	}
	return v;
}
int main()
{
	int l,i,j;
	while (scanf("%d",&n)!=EOF)
	{
		for (l=0;l<n;l++) 
		{
			scanf("%d%d%d",&e[l][0],&e[l][1],&e[l][2]); 
			if (e[l][0]>e[l][1]) {i=e[l][0]; e[l][0]=e[l][1]; e[l][1]=i;}
			e[l][0]--;
			pe[l*2]=e[l][0]; pe[l*2+1]=e[l][1];
		}
		sort(pe,pe+n+n); 
		pe[2*n]=-1;
		for (i=0;i<n+n;i++)
			if (pe[i]!=pe[i+1]) pe[++j]=pe[i];
		m=j+1;
		for (l=0;l<n;l++)
		{
			e[l][0]=sear(e[l][0]); 
			e[l][1]=sear(e[l][1]); 
		}
		for (l=0;l<m;l++) a[l]=l,c[l]=0;
		for (l=0;l<n;l++)
		{
			i=findways(e[l][0]); j=findways(e[l][1]);
			if (i==j) 
				if (c[e[l][1]]-c[e[l][0]]==e[l][2]) printf("Accept\n"); 
				else printf("Bug Detected %d\n",c[e[l][1]]-c[e[l][0]]); 
			else
			{
				a[j]=i;
				c[j]=e[l][2]+c[e[l][0]]-c[e[l][1]];
				printf("Accept\n"); 
			}
		}
	}
	return 0;
} 