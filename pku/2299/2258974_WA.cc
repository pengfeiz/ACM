#include<stdio.h>
#include<stdlib.h>
#define max 500010
__int64 count=0;
__int64 a[max],b[max];
void merge(int i,int m,int n)
{
	int j,t,k;
	for(j=m+1,k=i;i<=m&&j<=n;++k)
	{
		if(a[i]<=a[j])
			b[k]=a[i++];
		else
		{
			b[k]=a[j++];
			count+=m-i+1;
		}
	}
	if(i<=m)
		for (t=i;t<=m;t++)
			b[k++]=a[t];		
	if(j<=n)
		for (t=j;t<=n;t++)
			b[k++]=a[t];
	for(j=i;j<=n;j++)
		a[j]=b[j];
}

void msort(int s,int t)
{
	int m;
	if(s<t)
	{
		m=(s+t)/2;
		msort(s,m);
		msort(m+1,t);
		merge(s,m,t);
	}
}
int main()
{
	int n,i;
	//FILE *fp;
	//fp=fopen("c:\\hb.txt","r");
	//fscanf(fp,"%d",&n);
	scanf("%d",&n);
	while(n!=0)
	{
		for(i=1;i<=n;i++)
			//fscanf(fp,"%I64d",&a[i]);
			scanf("%64Id",&a[i]);
        msort(1,n);
		printf("%64Id\n",count);
		count=0;
		//fscanf(fp,"%d",&n);
		scanf("%d",&n);
	}
	return 0;
}