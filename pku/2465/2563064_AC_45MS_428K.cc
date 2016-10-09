#include <iostream>
using namespace std;

double a[110][201],b[110];
int c[110];

int n,d,p,q;

int main()
{
	int i,j;
	scanf("%d",&d);
	c[0]=0;
	b[0]=1e99;
	for(n=1;scanf("%d%lf",&c[n],&b[n])!=EOF;n++);
	c[n]=d;
	b[n++]=1e99;
	for(i=0;i<n;i++)
		for(j=0;j<=200;j++)
			a[i][j]=1e99;
	a[0][100]=0;
	for(p=0;p<n;p++)
	{
		for(i=0;i<=200;i++)
		{
			for(q=p;q<n&&c[q]-c[p]<=i;q++)
				if(a[p][i]<a[q][i-c[q]+c[p]])
					a[q][i-c[q]+c[p]]=a[p][i];
			for(j=i+1;j<=200;j++)
				if(a[p][i]+(j-i)*b[p]<a[p][j])
					a[p][j]=a[p][i]+(j-i)*b[p];
		}
	}
	if(a[n-1][100]<1e98)
		printf("%0.0lf\n",a[n-1][100]);
	else 
		printf("Impossible\n");
	return 0;
}

