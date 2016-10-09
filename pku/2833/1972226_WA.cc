#include <iostream>
using namespace std;
int main()
{
	__int64 a[10],b[10],i,j,na,nb,n,tt,m,ta,tb,mm;
	while(scanf("%I64d%I64d%I64d",&na,&nb,&n)!=EOF)
	{
		ta=tb=tt=0;
		for(i=0;i<na;i++)
			a[i]=0;
		for(i=0;i<nb;i++)
			b[i]=100000001;
		for(i=0;i<n;i++)
		{
			scanf("%I64d",&m);
			mm=m;
			tt+=m;
			if(ta<na)
				a[ta++]=mm;
			else
			{
				for(j=0;j<na;j++)
					if(mm>a[j])
						swap(mm,a[j]);
			}
			if(tb<nb)
				b[tb++]=m;
			else
			{
				for(j=0;j<nb;j++)
					if(m<b[j])
						swap(m,b[j]);
			}
		}
		for(i=0;i<na;i++)
			tt-=a[i];
		for(i=0;i<nb;i++)
			tt-=b[i];
		printf("%.6lf\n",double(tt)/double(n-na-nb));
	}
	return 0;
}
			




		
