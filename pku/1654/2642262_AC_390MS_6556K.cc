#include <iostream>
#include <math.h>
using namespace std;
#define MAX 1000000
int h[10][2]={0,0,-1,-1,0,-1,1,-1,-1,0,0,0,1,0,-1,1,0,1,1,1},a[MAX][2];
int main()
{
	int n,q,l,i,t,x[3],y[3];
	__int64 s;
	char c;
	scanf("%d",&n);
	while(n-->0)
	{
		l=1;
		a[0][0]=a[0][1]=s=0;
		while(scanf("%c",&c)&&(c-'5'))
		{
			a[l][0]=h[c-'0'][0]+a[l-1][0];
			a[l][1]=h[c-'0'][1]+a[l-1][1];
			l++;
		}
		t=l-2;
		while(t-->0)
		{
			q=0;
			for(i=0;i<l;i++)
			{
				x[q]=a[i][0];
				y[q]=a[i][1];
				q++;
				if(q==3)
				{
					q=2;
					s+=x[0]*y[1]+x[1]*y[2]+x[2]*y[0]-x[2]*y[1]-x[0]*y[2]-x[1]*y[0];
					x[1]=x[2];
					y[1]=y[2];					
					t--;
				}
			}
		}
		if(s<0)
			s*=-1;
		printf("%I64d",s/2);
		if(s%2==1)
			cout<<".5";
		cout<<endl;
	}
	return 0;
}


