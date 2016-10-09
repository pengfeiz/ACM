#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s[1000][70],c[70];
int main()
{
	int n,m,i,t=0,j,mid,k;
	scanf("%d%d",&n,&m);
	getchar();
	for(i=0;i<n;i++)
		gets(s[i]);
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(strcmp(s[i],s[j])>0)
			{
				strcpy(c,s[i]);
				strcpy(s[i],s[j]);
				strcpy(s[j],c);
			}
	for(j=0;j<m;j++)
	{
		gets(c);
		i=0;
		k=n-1;
		while(i<k-1)
		{
			mid=(i+k)/2;
			if(strcmp(c,s[mid])>0)
				i=mid+1;
			else
				k=mid;
		}
		for(;i<=k;i++)
			if(strlen(s[i])>=strlen(c)&&strstr(s[i],c)==s[i])
			{
				t++;
				break;
			}
	}
	printf("%d\n",t);
	return 0;
}

