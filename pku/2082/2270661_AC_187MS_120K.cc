#include <iostream>
using namespace std;
int a[50][2];
int n;

int main()
{
	int i,w,h,m,t,s,max,l;
	while(scanf("%d",&n),n!=-1)
	{
		m=t=max=0;
		while(n-->=0)
		{
			if(n==-1)
				w=h=0;
			else
				scanf("%d%d",&w,&h);
			l=m;
			for(i=t;i>0&&a[i][1]>=h;i--)
			{
				if(a[i][0]<l)
					l=a[i][0];
				s=(m-a[i][0])*a[i][1];
				if(s>max)
					max=s;
			}
			t=i+1;
			a[t][0]=l;
			a[t][1]=h;
			m+=w;
		}
		printf("%d\n",max);
	}
	return 0;
}