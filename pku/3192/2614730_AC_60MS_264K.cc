#include <iostream>
#include <algorithm>
using namespace std;

char s[7][10];
char ss[8];
char c[1001];
int x[7],ll[7],y[7];
int n;

int main()
{
	int m=1,i,j,l,ml,k,ii;
	ml=9999999;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",s[i]);
		ll[i]=strlen(s[i]);
	}
	for(i=1;i<=n;i++)
		m*=i;
	for(i=0;i<n;i++)
		ss[i]=i+'0';
	while(m--)
	{
		for(i=0;i<n;i++)
			x[i]=ss[i]-'0';
		for(j=0;j<n;j++)
			y[j]=i&(1<<j);
		for(j=0;j<ll[x[0]];j++)
			c[j]=s[x[0]][j];
		l=ll[x[0]];
		for(j=1;j<n;j++)
		{
			for(k=0;k<l;k++)
			{
				for(ii=0;ii<ll[x[j]]&&ii+k<l;ii++)
					if(s[x[j]][ii]!=c[k+ii])
						break;
				if(ii+k==l)
				{
					l=k+ll[x[j]];
					for(;ii<ll[x[j]];ii++)
						c[ii+k]=s[x[j]][ii];
					break;
				}
				if(ii==ll[x[j]])
					break;
			}
			if(k==l)
			{
				for(ii=0;ii<ll[x[j]];ii++)
					c[l+ii]=s[x[j]][ii];
				l+=ll[x[j]];
			}
		}
		if(l<ml)
			ml=l;
		next_permutation(ss,ss+n);
	}
	printf("%d\n",ml);
	return 0;
}