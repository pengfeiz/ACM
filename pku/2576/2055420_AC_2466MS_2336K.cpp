#include <iostream>
using namespace std;
#define MAX 100
#define MAX2 45001
bool b[51][MAX2];
int main()
{	
	int n,i,j,k,a[MAX],l,t=0,min;
	scanf("%d",&n);
	memset(b,0,sizeof(b));
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		t+=a[i];
	}
	b[0][0]=1;
	for(i=0;i<n;i++)
		for(j=(n-1)/2;j>=0;j--)
			for(k=0;k<MAX2;k++)
				if(b[j][k])
					b[j+1][k+a[i]]=true;
	i=(n+1)/2;
	min=999999;
	for(j=0;j<MAX2;j++)
		if(b[i][j]&&abs(t-2*j)<min)
		{
			min=abs(t-2*j);
			l=j;
		}
	if(2*l>t)
		l=t-l;
	printf("%d %d\n",l,t-l);
	return 0;
}
