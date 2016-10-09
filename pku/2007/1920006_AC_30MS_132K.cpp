#include <iostream>
using namespace std;
double num[100][3];
int main()
{
	int n=0,i,j,t,max,he[100],p,x,y;
	while(cin>>num[n][0]>>num[n][1])
		n++;
	x=num[0][0];
	y=num[0][1];
	max=0;
	for(i=0;i<n;i++)
	{
		he[i]=-1;
		if(num[i][0]>num[max][0])
			max=i;
	}
	t=0;
	for(i=0;i<n;i++)
	{
		if(num[i][0]==num[max][0])
		{
			he[t]=i;
			num[i][2]=-99999999;
			t++;
		}
	}
	for(i=0;i<t-1;i++)
	{
		for(j=0;j<t;j++)
			if(num[he[i]][1]>num[he[j]][1])
			{
				max=he[i];
				he[i]=he[j];
				he[j]=max;
			}
	}
	max=he[0];
	p=t;
	for(i=0;i<n;i++)
	{
		if(num[i][0]==num[max][0])
			continue;
		num[i][2]=(num[i][1]-num[max][1])/(num[i][0]-num[max][0]);
		he[p]=i;
		p++;
	}
	for(i=t;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(num[he[i]][2]>num[he[j]][2])
			{
				max=he[i];
				he[i]=he[j];
				he[j]=max;
			}
	for(i=0;i<n;i++)
		if(num[he[i]][0]==x&&num[he[i]][1]==y)
			break;
	p=0;
	while(p<n)
	{		
		i%=n;
		cout<<"("<<num[he[i]][0]<<","<<num[he[i]][1]<<")\n";
		i++;
		p++;
	}
	return 0;
}

			
			

	
