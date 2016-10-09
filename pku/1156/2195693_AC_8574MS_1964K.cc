#include <stdio.h>
#define MAX 700

int a[MAX][MAX];
int b[MAX],c[MAX],n,m,C;

int main()
{
	int i,j,l,r,ii,jj,w,tt,len,mi,ma,t;
	scanf("%d%d%d",&m,&n,&C);
	for(i =0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	tt=1;
	for(l=0;l<m;l++)
	{
		w=m-l;
		if(w>100)
			w=100;
		if(w*n<=tt)
			break;
		for(i=0;i<n;i++)
			b[i]=c[i]=a[i][l];
		for(r=l;r<m&&r-l<100;r++)
		{
			for(i=0;i<n;i++)
			{
				if(a[i][r]<b[i])
					b[i]=a[i][r];
				if(a[i][r]>c[i])
					c[i]=a[i][r];
			}
			len=r-l+1;
			for(ii=0;ii<n;ii++)
			{
				if(len*(n-ii)<=tt)
					break;
				if(c[ii]-b[ii]>C)
					continue;
				mi=b[ii];
				ma=c[ii];
				t=0;
				for(jj=ii;jj<n;jj++)
				{
					if(c[jj]-b[jj]>C)
					{
						ii=jj;
						break;
					}
					if(b[jj]<mi) 
						mi=b[jj];
					if(c[jj]>ma) 
						ma=c[jj];
					if(ma-mi>C)
						break;
					t+=len;
				}
				if(t>tt)
					tt=t;
			}
		}
	}
	printf("%d\n",tt);
	return 0;
}