#include <iostream>
#include <math.h>
#define MAX 6000
using namespace std;
int main()
{
	int i,t[4],tt,num[MAX],w;
	double k,q,j[4];
	k=2000000001;
	t[0]=30;
	t[1]=19;
	t[2]=13;
	t[3]=11;
	i=0;
	for(j[0]=0;j[0]<=t[0];j[0]++)
		for(j[1]=0;j[1]<=t[1];j[1]++)
			for(j[2]=0;j[2]<=t[2];j[2]++)
				for(j[3]=0;j[3]<=t[3];j[3]++)
				{
					if((q=pow(2,j[0])*pow(3,j[1])*pow(5,j[2])*pow(7,j[3]))<k)
					{
						num[i]=(int)q;
						i++;
					}
				}
	for(i=0;i<5842;i++)
		for(tt=i+1;tt<5842;tt++)
			if(num[i]>num[tt])
			{
				w=num[i];
				num[i]=num[tt];
				num[tt]=w;
			}
	while(cin>>i&&i!=0)
	{
        if(i%10==1&&i%100!=11)
            cout<<"The "<<i<<"st humble number is ";
        else if(i%10==2&&i%100!=12)
            cout<<"The "<<i<<"nd humble number is ";
        else if(i%10==3&&i%100!=13)
            cout<<"The "<<i<<"rd humble number is ";
        else 
            cout<<"The "<<i<<"th humble number is ";
        cout<<num[i-1]<<"."<<endl;
    }
	return 0;
}
				
