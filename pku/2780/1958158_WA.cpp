#include <iostream>
using namespace std;
#define MAX 1000
double a[MAX],b[MAX][2];
int com(const void *a,const void *b)
{
	return *(double *)a-*(double *)b;
}
int main()
{
	long n,i,j,f,k,max;
	while(cin>>n)
	{
		memset(a,0,1000);
		max=0;
		for(i=0;i<n;i++)
			scanf("%lf%lf",&b[i][0],&b[i][1]);
		for(i=0;i<n-1;i++)
		{
			for(j=k=f=0;j<n;j++)
			{
				if(i==j)
					continue;
				else if(b[i][0]==b[j][0])
					f++;
				else
				{
					a[k]=(b[i][1]+b[j][1])/(b[i][0]+b[j][0]);
					k++;
				}
			}
			qsort(a,k,sizeof(double),com);
			for(i=j=1;i<n;i++)
			{
				if(a[i]==a[i-1])
					j++;
				else
				{
					if(j>max)
						max=j;
					j=1;
				}
				if(f>max)
					max=f;
			}
		}				
		cout<<max+1<<endl;
	}
	return 0;
}