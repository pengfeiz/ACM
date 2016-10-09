#include <iostream>
using namespace std;
#define MAX 100002
__int64 a[MAX],b[MAX][2],max;
int main()
{	
	int n,i;
	while(cin>>n&&n)
	{
		max=0;
		for(i=1;i<=n;i++)
		{
			scanf("%I64d",&a[i]);
			b[i][0]=i-1;
			b[i][1]=i+1;
		}
		for(i=1;i<=n;i++)
			while(a[i]<=a[b[i][0]])
				b[i][0]=b[b[i][0]][0];
		for(i=n;i>0;i--)
			while(a[i]<=a[b[i][1]])
				b[i][1]=b[b[i][1]][1];
		for(i=1;i<=n;i++)
			if(a[i]*(b[i][1]-b[i][0]-1)>max)
				max=a[i]*(b[i][1]-b[i][0]-1);
		printf("%I64d\n",max);
	}
	return 0;
}