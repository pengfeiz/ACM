#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int num[100][100],n,i,j,t,q,last,k,no[1000],pp[1000];
	while(cin>>n)
	{
		for(i=0;i<n;i++)
		{
			no[i]=0;
			pp[i]=0;
			for(j=0;j<n;j++)
				scanf("%d",&num[i][j]);
		}
		cout<<"1\n"<<n<<"\n";
		t=0;
		last=pp[0]=1;
		no[0]=0;
		while(last<n)
		{
			q=t;
			for(i=0;i<n;i++)
				if(num[t][i]==1&&pp[i]==0)
				{
					no[last]=i;
					pp[i]=1;
					last++;
					t=i;
					break;
				}
			if(q!=t)
				continue;
			for(i=0;i<n;i++)
				for(j=0;j<last-1;j++)
					if(num[j][i]==1&&num[i][j+1]==1&&pp[i]==0)
					{
						for(k=last;k>j;k--)
							no[k]=no[k-1];
						no[j+1]=i;
						pp[i]=1;
						last++;
					}
		}
		for(i=0;i<n;i++)
		{
			if(i)
				cout<<" ";
			cout<<no[i]+1;
		}
		cout<<endl;
	}
	return 0;
}


	


