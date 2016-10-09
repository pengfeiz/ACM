#include <iostream>
#define MAX 1000
using namespace std;
float num[MAX];
float dosth(float num[MAX],int m)
{
	int i;
	float t=0,sum=0;
	for(i=0;i<m;i++)
		sum+=num[i];
	sum=sum/m;
	for(i=0;i<m;i++)
		if(num[i]>sum)
			t++;
	return t/m*100;
}
int main()
{
	int i,j,n,m;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>m;
		for(j=0;j<m;j++)
			cin>>num[j];
		printf("%.3f%c\n",dosth(num,m),'%');
	}
	return 0;
}

