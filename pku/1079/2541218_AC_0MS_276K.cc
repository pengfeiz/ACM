#include <iostream>
#include <math.h>
using namespace std;
#define esp 1e-7

int main() 
{ 
	int tim=0,n,m,i,e;
	double a,b,f;
	while(scanf("%d%d",&n,&m)!=EOF) 
    { 
		if(tim++)
			printf("\n");
		a=(double)n/m; 
		b=floor(a+0.5); 
		printf("%.0lf/1\n",b);
		for(i=2;i<=m;i++) 
		{ 
			e=a*i+0.5;
			f=(double)e/i; 
			if(fabs(f-a)<fabs(b-a)-esp) 
            { 
				b=f;
				printf("%d/%d\n",e,i);
				if(b==a) 
					break; 
            } 
        } 
    } 
	return 0; 
} 
