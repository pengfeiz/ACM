#include <iostream>
#include <math.h>
#define MAX 100
using namespace std;
int compare(const void *a,const void *b)
{
	return *(double *)a-*(double *)b;
}
int main()
{
	double s[MAX],t;
	long n,i,m,j,k,num[MAX+1];
	char c[20];
	while(cin>>n>>m&&(n||m))
	{
		k=0;
		for(i=0;i<n;i++)
		{
			t=num[i]=0;
			scanf("%s",c);
			for(j=0;j<m;j++)
			{
				if(c[j]=='A')
					t+=pow(4,double(j));
				else if(c[j]=='T')
					t+=2*pow(4,double(j));
				else if(c[j]=='G')
					t+=3*pow(4,double(j));
				else
					t+=4*pow(4,double(j));
			}
			s[k]=t;
			k++;
		}
		qsort(s,k,sizeof(double),compare);
		num[k]=-3;
		for(i=1,m=0,n=s[0];i<=k;i++)
		{
			if(s[i]==n)
				m++;
			else
			{
				num[m]++;
				m=0;
				n=s[i];
			}
		}
		for(i=0;i<k;i++)
			cout<<num[i]<<endl;
	}
	return 0;
}


