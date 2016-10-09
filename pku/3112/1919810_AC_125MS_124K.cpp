#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int n1[2000],n2[2000],n,m,p,i,j,num,t=0;
	while(scanf("%d %d %d",&n,&m,&p)&&!(n==0&&m==0&&p==0))
	{
		t++;
		for(i=0;i<2000;i++)
			n1[i]=0;
		for(i=0;i<2000;i++)
			n2[i]=0;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&num);
				if(num==1)
					n1[j]++;
				else
				{
					n2[n1[j]]++;
					n1[j]=0;
				}
			}
		}
		num=0;
		for(i=0;i<n;i++)
			n2[n1[i]]++;
		for(i=0;i<2000;i++)
			if(i>=p)
				num+=n2[i];
		cout<<num<<endl;
	}
	return 0;
}

