#include <iostream>
using namespace std;
int a[16][16], n[16][16];

int main () 
{
	int i,j,w,b;
	while(scanf("%d%d",&w,&b)!=EOF) 
	{
		for(i=0;i<16;i++) 
			for(j=0;j<16;j++) 
			{
				if(i&&a[i-1][j]+w>a[i][j])
					n[i][j]=a[i-1][j]+w;
				if(j&&a[i][j-1]+b>n[i][j])
					n[i][j]=a[i][j-1]+b;
			}
		for(i=0;i<16;i++) 
			for(j=0;j<16;j++) 
				a[i][j]=n[i][j];
	}
    printf("%d\n",a[15][15]);
	return 0;
}