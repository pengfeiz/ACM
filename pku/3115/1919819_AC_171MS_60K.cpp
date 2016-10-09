#include <stdio.h>
int main()
{
	long f,p,e,a,i,j,k,min,mm[30],mm2[30],p1,q;
	while(scanf("%ld %ld %ld %ld",&f,&p,&e,&a)&&!(f==0&&p==0&&e==0&&a==0))
	{
		scanf("%ld %ld",&j,&k);		
		mm[0]=j*k;
		for(i=1;i<f;i++)
		{
			scanf("%ld %ld",&j,&k);
			mm[i]=j*k+e*a;
		}
		for(j=1;j<p;j++)
		{
			for(i=0;i<f;i++)
			{
				scanf("%ld %ld",&p1,&q);
				min=2000000000;
				for(k=0;k<f;k++)
				{
					if(k==i&&mm[k]+p1*q<min)
						min=mm[k]+p1*q;
					else if(mm[k]+p1*q+e*a<min)
						min=mm[k]+p1*q+e*a;
				}
				mm2[i]=min;
			}
			for(i=0;i<f;i++)
				mm[i]=mm2[i];
		}
		min=2000000000;
		for(i=0;i<f;i++)
			if(mm[i]<min)
				min=mm[i];
		printf("%ld\n",min);
	}
	return 0;
}

				
					




