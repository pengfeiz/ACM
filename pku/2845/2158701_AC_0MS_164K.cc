#include <iostream>
using namespace std;
char s1[1005],s2[1005];
int a[1005],b[1005],c[1005];
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(j=1;j<=n;j++)
	{
		scanf("%s %s",s1,s2);
		printf("%d ",j);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		a[0]=strlen(s1);
		b[0]=strlen(s2);
		for(i=a[0];i>0;i--)
			a[i]=s1[a[0]-i]-'0';
		for(i=b[0];i>0;i--)
			b[i]=s2[b[0]-i]-'0';
		memset(c,0,sizeof(c));
		c[0]=max(a[0],b[0]);
		for(i=1;i<=c[0];i++)
			c[i]=a[i]+b[i];
		for(i=1;i<c[0];i++)
		{
			c[i+1]+=c[i]/2;
			c[i]%=2;
		}
		while(c[c[0]]>1)
		{
			c[c[0]+1]=c[c[0]]/2;
			c[c[0]]%=2;
			c[0]++;
		}
		while(c[c[0]]==0&&c[0])
			c[0]--;
		if(c[0]==0)
			printf("0");
		for(i=c[0];i>0;i--)
			printf("%d",c[i]);
		printf("\n");
	}
	return 0;
}
