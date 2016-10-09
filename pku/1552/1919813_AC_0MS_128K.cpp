#include <iostream>
using namespace std;
int main()
{
	int num[20],n,i,j,t;
	while(1)
	{
		n=t=0;
		while(1)
		{
			cin>>num[n];
			if(num[n]==0||num[n]==-1)
				break;
			n++;
		}
		if(num[n]==-1)
			break;
		else 
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
				{
					if(i==j)
						continue;
					else if(num[i]==2*num[j])
						t++;
				}
		cout<<t<<endl;
	}
	return 0;
}

