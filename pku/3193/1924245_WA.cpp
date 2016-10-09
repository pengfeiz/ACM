#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s[1000][70],c[70];
void qsort(char s[1000][70],int l,int r)
{
	int i=l,j=r,mid=(l+r)/2;
	char temp[70];
	do
	{
		while(strcmp(s[i],s[mid])<0)
			i++;
		while(strcmp(s[j],s[mid])>0)
			j--;
		if(i<=j)
		{	
			strcpy(temp,s[i]);
			strcpy(s[i],s[j]);
			strcpy(s[j],temp);
			i++;
			j--;
		}
	}while(i<=j);
	if(l<j)
		qsort(s,l,j);
	if(i<r)
		qsort(s,i,r);
}
int main()
{
	int n,m,i,t=0,j,mid,k;
	scanf("%d%d",&n,&m);
	getchar();
	for(i=0;i<n;i++)
		gets(s[i]);
	qsort(s,0,n-1);
	for(j=0;j<m;j++)
	{
		gets(c);
		i=0;
		k=n-1;
		while(i<k-2)
		{
			mid=(i+k)/2;
			if(strcmp(s[mid],c)>0)
				k=mid;
			else
				i=mid;
		}
		if(k>1&&strstr(s[k-2],c)==s[k-2])
			t++;
		else if(k>0&&strstr(s[k-1],c)==s[k-1])
			t++;
		else if(strstr(s[k],c)==s[k])
			t++;
	}
	printf("%d\n",t);
	return 0;
}

