#include <iostream>
#include <math.h>
#define MAX 6000
using namespace std;
int main()
{
	int i,t[3],tt;
	double k,q,j[3],num[MAX],w;
	k=2147483647;
	t[0]=30;
	t[1]=19;
	t[2]=13;
	i=0;
	for(j[0]=0;j[0]<=t[0];j[0]++)
		for(j[1]=0;j[1]<=t[1];j[1]++)
			for(j[2]=0;j[2]<=t[2];j[2]++)
				{
					if((q=pow(2,j[0])*pow(3,j[1])*pow(5,j[2]))<k)
					{
						num[i]=q;
						i++;
					}
				}
	for(i=0;i<1691;i++)
		for(tt=i+1;tt<1691;tt++)
			if(num[i]>num[tt])
			{
				w=num[i];
				num[i]=num[tt];
				num[tt]=w;
			}
	while(cin>>i&&i!=0)
        cout<<(long)num[i-1]<<endl;
	return 0;
}
				
