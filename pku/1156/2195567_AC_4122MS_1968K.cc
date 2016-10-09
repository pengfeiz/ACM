#include <stdio.h>
#define size 700
#define maxw 100
#define inf 9999999
int a[size][size];

int main()
{
    int u,v,c,p[size],q[size],sp[size],sq[size];
    int i,j,k,r,m;
    scanf("%d%d%d",&u,&v,&c);
    for(i=0;i<v;i++)
        for(j=0;j<u;j++) 
			scanf("%d",&a[i][j]);
    r=1;
    for(i=0;i<u;i++)
	{
      	for(j=0;j<v;j++) 
			p[j]=inf,q[j]=-inf;
      	for(j=i;j<u&&j<i+maxw;j++)
		{
      		int ip,jp,iq,jq,f;
      		ip=jp=iq=jq=0;
      		f=-1;
      		m=0;
      		for(k=0;k<v;k++)
			{
      			if(a[k][j]<p[k]) 
					p[k]=a[k][j];
      			while(ip>jp&&p[sp[ip-1]]>=p[k]) 
					ip--;
      			sp[ip++]=k;
      			if(a[k][j]>q[k]) 
					q[k]=a[k][j];
      			while(iq>jq&&q[sq[iq-1]]<=q[k]) 
					iq--;
      			sq[iq++]=k;
      			if(q[k]-p[k]>c)
				{
      				ip=jp=iq=jq=0;
      				f=k;
      			}
				else
				{
      				while(q[sq[jq]]-p[sp[jp]]>c)
					{
      					if(sq[jq]<sp[jp]) 
							f=sq[jq++]; 
						else 
							f=sp[jp++];
      				}
      				if(k-f>m) 
						m=k-f;
      				int t=(j-i+1)*(k-f);
      				if(t>r) 
						r=t;
      			}			
      		}
      		if(m*maxw<=r) break;
      	}
    }
    printf("%d\n",r);
    return 0;
}