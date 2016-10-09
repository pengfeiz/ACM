#include <iostream>
using namespace std;
int main()
{
	int a[6][2],i,j,n1,n2,n3,n[3],t=0;
	for(i=0;i<6;i++)
	{
		for(j=0;j<2;j++)
			cin>>a[i][j];
		if(a[i][0]>a[i][1])
			swap(a[i][0],a[i][1]);
	}
	for(i=0;i<5;i++)
		for(j=i+1;j<6;j++)
		{
			if(a[i][0]>a[j][0])
			{
				swap(a[i][0],a[j][0]);
				swap(a[i][1],a[j][1]);
			}
			else if(a[i][0]==a[j][0]&&a[i][1]>a[j][1])
			{
				swap(a[i][0],a[j][0]);
				swap(a[i][1],a[j][1]);
			}
		}
	for(i=0;i<6&&t==0;i+=2)
		if(a[i][0]!=a[i+1][0]||a[i][1]!=a[i+1][1])
			t=1;
	if(t==0)
	{
		n[0]=n[1]=n[2]=0;
		n1=n2=n3=-1;
		for(i=0;i<6&&t==0;i+=2)
		{
			for(j=0;j<2&&t==0;j++)
			{
				if(n1==-1||a[i][j]==n1)
				{
					n[0]++;
					n1=a[i][j];
					continue;
				}
				else if(n2==-1||a[i][j]==n2)
				{
					n[1]++;
					n2=a[i][j];
					continue;
				}
				else if(n3==-1||a[i][j]==n3)
				{
					n[2]++;
					n3=a[i][j];
					continue;
				}
				else t=1;
			}
		}	
		if(t==0&&(n[0]%2==1||n[1]%2==1||n[2]%2==1))
			t=1;
	}
	if(t==1)
		cout<<"IMPOSSIBLE\n";
	else
		cout<<"POSSIBLE\n";
	return 0;
}


			

