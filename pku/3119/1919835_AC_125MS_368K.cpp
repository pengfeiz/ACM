#include <stdio.h>
#define MAX 80000
int main()
{
	long nn,ii,a,b,n,i,tx,ty,x,y,p,num[MAX];
	scanf("%ld",&nn);
	for(ii=1;ii<=nn;ii++)
	{
		y=ty=0;
		p=0;
		x=1;
		tx=-1;
		num[0]=2;
		printf("Caso %ld\n",ii);
		scanf("%ld %ld %ld",&a,&b,&n);
		while(p<75000)
		{
			if(a*(x+tx)+b!=(y+ty))
			{
				if((y+ty)>a*(x+tx)+b)
					num[p]=1;
				else
					num[p]=0;
				p++;
			}
			x+=tx;
			y+=ty;
			if(x==y&&x>0)
			{
				tx=0;
				ty=-1;
			}
			else if(x==-y&&x<0)
			{
				tx=1;
				ty=0;
			}
			else if(x==-y&&y<0)
			{
				tx=-1;
				ty=0;
			}
			else if(x==y-1&&x<0)
			{
				tx=0;
				ty=1;
			}
		}
		if(num[0]==2)
			num[0]=num[1];
		for(i=0;i<n;i++)
		{
			scanf("%ld %ld",&x,&y);
			if(num[x]==num[y])
				printf("Mesmo lado da fronteira\n");
			else
				printf("Lados opostos da fronteira\n");
		}
	}
	return 1;
}
		
