#include <stdio.h>
#include <math.h>

bool b[16000001]={0};

int main()
{
	int a,c,r,m,i,ma=0,q,n1,n2;
	scanf("%d%d%d%d",&a,&c,&m,&r);
	r%=m;
	b[r]=true;
	n1=n2=r;
	while(1)
	{
		q=(a*r+c);
		if(q>=m)
			q%=m;
		if(q>n2)
			n2=q;
		if(q<n1)
			n1=q;
		if(b[q])
			break;
		b[q]=true;
		r=q;
	}
	q=n1;
	for(i=q+1;i<=n2;i++)
	{
		if(b[i])
		{
			m=i-q;
			if(m>ma)
				ma=m;
			q=i;
		}
	}
	printf("%d\n",ma);
	return 0;
}