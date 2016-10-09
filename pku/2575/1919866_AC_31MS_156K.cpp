#include <iostream>
#define MAX 5000
using namespace std;
int main()
{
	int no[MAX],mm[MAX],n,i,m,t;
	while(cin>>n)
	{
		t=0;
		for(i=0;i<n;i++)
		{
			cin>>no[i];
			mm[i]=0;
		}
		m=0;
		for(i=0;i<n-1&&m==0;i++)
		{
			if(no[i]-no[i+1]>=n||no[i]-no[i+1]<=-n)
				m=1;
			else
			{
				if(no[i]-no[i+1]>0)
				{
					mm[no[i]-no[i+1]]++;
					if(mm[no[i]-no[i+1]]>1)
						m=1;
				}
				else
				{
					mm[no[i+1]-no[i]]++;
					if(mm[no[i+1]-no[i]]>1)
						m=1;
				}
				t++;
			}
		}
		if(m==0&&t==n-1)
			cout<<"Jolly\n";
		else
			cout<<"Not jolly\n";
	}
	return 0;
}
