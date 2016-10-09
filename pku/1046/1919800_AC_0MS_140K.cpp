#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double c[16][3],nb,n1,n2,n3;
	int i,t;
	for(i=0;i<16;i++)
		cin>>c[i][0]>>c[i][1]>>c[i][2];
	while(cin>>n1>>n2>>n3&&n1!=-1&&n2!=-1&&n3!=-1)
	{
		t=0;
		nb=10000000;
		for(i=0;i<16;i++)
		{
			if(sqrt(pow(n1-c[i][0],2)+pow(n2-c[i][1],2)+pow(n3-c[i][2],2))<nb)
			{
				t=i;
				nb=sqrt(pow(n1-c[i][0],2)+pow(n2-c[i][1],2)+pow(n3-c[i][2],2));
			}
		}
		cout<<"("<<n1<<","<<n2<<","<<n3<<") maps to ("<<c[t][0]<<","<<c[t][1]<<","<<c[t][2]<<")\n";
	}
	return 0;
}


