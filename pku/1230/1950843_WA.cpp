#include <iostream>
using namespace std;
int a[101][3];
int main()
{
	int nn,n,k,y1,y2,i,j,num,l,tt,max,last;
	cin>>nn;
	while(nn-->0)
	{
		cin>>n>>k;
		l=0;
		for(num=last=0;num<n;num++)
		{
			cin>>a[num][1]>>y1>>a[num][2]>>y2;
			if(last<y1)
				last=y1;
			if(last<y2)
				last=y2;
			if(a[num][1]>a[num][2])
			{
				y1=a[num][1];
				a[num][1]=a[num][2];
				a[num][2]=y1;
			}
			a[num][0]=0;
		}
		tt=0;
		for(j=0;j<=last;j++)
		{
			for(i=0;i<num;i++)
			{
				if(a[i][1]==j)
				{
					tt++;
					a[i][0]=1;
				}
				if(a[i][2]<j&&a[i][0]==1)
				{
					a[i][0]=0;
					tt--;
				}
			}
			while(tt>k)
			{
				for(i=0;i<num;i++)
					if(a[i][0]==1)
					{
						max=i;
						break;
					}
				for(i=max+1;i<num;i++)
					if(a[i][0]==1&&a[i][2]>a[max][2])
						max=i;
				a[max][0]=0;
				l++;
				tt--;
			}
		}
		cout<<l<<endl;
	}
	return 0;
}
