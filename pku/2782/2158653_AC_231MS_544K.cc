#include <iostream>
#include <algorithm>
using namespace std;

int a[100000];

bool com(int a,int b)
{
	return a<b;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	memset(a,0,sizeof(a));
	int i,j,n=0,m,t=0;
	scanf("%d%d",&n,&m);
/*	for(n=0;n<19;n++)
		a[n]=rand()%(m-4)+5;
		*/
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n,com);
/*	for(i=0;i<n;i++)
		printf("%d ",a[i]);*/
	i=0;
	j=n-1;
	while(i<=j)
	{
		if(a[i]+a[j]<=m)
		{
			i++;
			j--;
		}
		else
			j--;
		t++;
	}
	printf("%d\n",t);
	return 0;
}



