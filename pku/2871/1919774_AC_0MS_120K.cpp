#include <iostream>
using namespace std;
int main()
{
	float n,m;
	cin>>m;
	while(1)
	{
		n=m;
		cin>>m;
		if(m==999)
		{
			cout<<"End of Output\n";
			break;
		}
		else
			printf("%.2f\n",m-n);
	}
	return 0;
}

