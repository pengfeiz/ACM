#include <iostream>
#include <fstream>
using namespace std;
#define MAX 30
int tl[MAX],lake[MAX],lake2[MAX],la[MAX],l[MAX],ll[MAX];
int main()
{
//	ifstream cin("g.9.dat");
	int t,n,i,tt,max,qt,j,tr;
	while(cin>>n&&n)
	{
		max=tl[0]=0;
		cin>>t;
		t*=12;
		for(i=0;i<n;i++)
			cin>>lake[i];
		for(i=0;i<n;i++)
			cin>>la[i];
		for(i=1;i<n;i++)
		{
			cin>>tl[i];
			tl[i]+=tl[i-1];
		}
		max=0;
		for(i=n;i>0;i--)
		{
			memcpy(lake2,lake,sizeof(lake));
			memset(l,0,sizeof(l));
			qt=t;
			qt-=tl[i-1];
			tt=0;
			while(qt-->0)
			{
				for(j=tr=0;j<i;j++)
				{
					if(lake2[j]<=0)
						continue;
					if(lake2[j]>lake2[tr])
						tr=j;
				}
				if(lake2[tr]>0)
				{
					tt+=lake2[tr];
					lake2[tr]-=la[tr];
				}
				l[tr]++;
			}
			if(tt>=max)
			{
				memcpy(ll,l,sizeof(l));
				max=tt;
			}
		}
		for(i=0;i<n;i++)
		{
			if(i)
				cout<<", ";
			cout<<ll[i]*5;
		}
		cout<<"\nNumber of fish expected: "<<max<<endl<<endl;
	}
	return 0;
}