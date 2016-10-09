#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double num[10],n;
	int i;
	for(i=0;i<10;i++)
		num[i]=pow(9,i)*2+1;
	while(cin>>n)
	{
		for(i=0;i<10;i++)
			if(n<num[i])
				break;
		if(i%2==1)
			cout<<"Ollie wins.\n";
		else
			cout<<"Stan wins.\n";
	}
	return 0;
}

		
