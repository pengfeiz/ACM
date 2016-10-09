#include <iostream>
#include <math.h>
using namespace std;

bool b[16000001]={0};

int main()
{
	int a,c,r,m,i,ma=0,q;
	scanf("%d%d%d%d",&a,&c,&m,&r);
	b[r]=true;
	while(1)
	{
		q=(a*r+c)%m;
		if(b[q])
			break;
		b[q]=true;
		r=q;
	}
	for(i=0;i<=16000000;i++)
		if(b[i])
			break;
		q=i;
	for(i=i+1;i<=16000000;i++)
	{
		if(b[i])
		{
			if(i-q>ma)
				ma=i-q;
			q=i;
		}
	}
	printf("%d\n",ma);
	return 0;
}