#include <iostream>
using namespace std;

int a[105][10005];
int d[105][10005];
int b[105];
char s[105];

int main()
{
	int n,i,l,p,k,j,maxx;
	while(scanf("%s%d",s,&n)!=EOF)
	{		
		maxx=999999;
		l=strlen(s);
		p=1;
		b[l-1]=1;
		for(i=l-2;i>=0;i--)
			b[i]=b[i+1]*10%n;
for(i=0;i<l;i++)
for(j=0;j<n;j++)
a[i][j]=d[i][j]=999999;
		for(i=0;i<=9;i++)
		{
			a[l-1][i%n]=1;
			if(d[l-1][i%n]>i)
				d[l-1][i%n]=i;
		}
		a[l-1][(s[l-1]-'0')%n]=0;
		d[l-1][(s[l-1]-'0')%n]=s[l-1]-'0';
		for(i=l-2;i>=0;i--)
			for(j=0;j<n;j++)
			{
				if(a[i+1][j]>n)
					continue;
				if(i==0)
					{
k=1;
p=(j+b[i])%n;
}
				else
				{
	k=0;
                                p=j;
}
				for(;k<=9;k++)
				{
					if((s[i]-'0')!=k)
					{
						if(a[i][p]>a[i+1][j]+1)
						{
							a[i][p]=a[i+1][j]+1;
							d[i][p]=k;
						}
						else if(a[i][p]==a[i+1][j]+1&&d[i][p]>k)
							d[i][p]=k;
					}
					else
					{
						if(a[i][p]>a[i+1][j])
						{
							a[i][p]=a[i+1][j];
							d[i][p]=k;
						}
						else if(a[i][p]==a[i+1][j]&&d[i][p]>k)
							d[i][p]=k;
					}
p=(p+b[i])%n;
				}
			}
		i=d[0][0];
		printf("%d",i);
		i=((n-i*b[0])%n+n)%n;
		k=1;
		while(k<l)
		{
			p=i;
			printf("%d",d[k][p]);
			i=((p-d[k][p]*b[k])%n+n)%n;
			k++;
		}
		printf("\n");
	}					
	return 0;
}
