#include <iostream>
#include <math.h>
using namespace std;
long num[5]={0,45,9045,1395495,189414495};
long num2[6]={0,9,189,2889,38889,488889};
int main()
{
	long nn,n,i,j,p,w;
	cin>>nn;
	while(nn-->0)
	{
		cin>>n;
		for(i=0;i<5;i++)
			if(n<=num[i])
				break;
		w=i-1;
		n-=num[w];
		j=1;
		while(n>0)
		{
			n-=num2[w]+j*i;
			j++;
		}
		n+=num2[w]+(j-1)*i;
		for(i=0;i<6;i++)
			if(num2[i]>=n)
				break;
		w=i;
		n-=num2[w-1];
		p=(n+w-1)/w;
		if(w==1)
			i=0;
		else
		{
			i=w-n%w;
			i=i%w;
		}
		p=p+pow(10,double(w-1))-1;
		n=(p/(long)pow(10,double(i)))%10;
		cout<<n<<endl;
	}
	return 0;
}




