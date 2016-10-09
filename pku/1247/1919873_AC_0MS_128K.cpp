#include <iostream>
#define MAX 30
using namespace std;
int main()
{
	int i,n,sit[30],tt,t2;
	while(cin>>n&&n!=0)
	{
		tt=t2=0;
		for(i=0;i<n;i++)
		{
			cin>>sit[i];
			tt+=sit[i];
		}
		if(tt%2==1)
			cout<<"No equal partitioning.\n";
		else
		{
			for(i=0;i<n;i++)
			{
				t2+=sit[i];
				if(t2==tt/2)
				{
					cout<<"Sam stops at position "<<i+1<<" and Ella stops at position "<<i+2<<".\n";
					break;
				}
				else if(t2>tt/2)
				{
					cout<<"No equal partitioning.\n";
					break;
				}
			}
		}
	}
	return 0;
}
