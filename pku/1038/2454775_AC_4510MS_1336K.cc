#include<stdio.h>

int n,m,k,D,e[11]={1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049};
int mmax,blank[10],x,y,curr,tt,a1,a2,i,j,p; 
bool b[150][10],can1,can2,ll[60000]; 
unsigned char c[4][60000],bit[11][60000];
unsigned char *l0,*l1,*l2,*l3,*bit0,*bit1,*bit2; 
int l[60000],dd,p0;

int main() 
{ 
    scanf("%d",&D); 
    for(p=0;p<59049;p++)
		for(tt=p,i=0;i<11;i++,tt/=3)
			bit[i][p]=tt%3; 
	for(p=59048;p>-1;p--)
	{
		ll[p]=true;
		l[p]=p;
		i=0;
		do
		{
			if(bit[i][p]==2&&bit[i+1][p]==0&&bit[i+2][p]>bit[i+1][p])
				break;
		}while(++i<=7);
		if(i<=7) 
		{
			if(bit[i][p]<bit[i+2][p])
				dd=bit[i][p];
			else 
				dd=bit[i+2][p];
			p0=p+e[i+1];
			while(!ll[p0])
				p0=l[p0];
			l[p]=p0;
			ll[p]=false;
		}
	}
    while(D--) 
    { 
        scanf("%d%d%d",&n,&m,&k); 
        curr=2; 
        mmax=e[m]; 
        for(i=0;i<4;i++)
			for(j=0;j<mmax;j++)
				c[i][j]=0; 
        for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				b[i][j]=false; 
        for(i=0;i<k;i++) 
        { 
            scanf("%d %d",&x,&y); 
            b[x-1][y-1]=true; 
        } 
        for(j=0;j<m;j++)
			blank[j]=1-b[0][j]; 
        for(i=1;i<n;i++)
			for(j=0;j<m;j++) 
			{ 
				curr=(curr+1)%4; 
				if(!b[i][j])
					blank[j]++;
				else 
					blank[j]=0; 
				can1=(blank[j]>2&&blank[j-1]>2);
				can2=(j>1&&blank[j]>1&&blank[j-1]>1&&blank[j-2]>1); 
				l0=c[curr];
				l1=c[(curr+3)%4];
				l2=c[(curr+2)%4];
				l3=c[(curr+1)%4]; 
				a1=2*e[j]+2*e[j-1];
				a2=e[j]+e[j-1]+e[j-2]; 
				bit0=bit[j];
				bit1=bit[j-1];
				bit2=bit[j-2]; 
				for(p=0;p<mmax;p++) 
				{
					if(!ll[p]) 
						continue;
					if(bit0[p])
					{
						p0=l[p-e[j]];
						l0[p]=l1[p0]; 
					}
					else
					{ 
						l0[p]=l1[p]; 
						if(j&&bit1[p]==0)
						{ 
							if(can1&&(tt=l2[l[p+a1]]+1)>l0[p])
								l0[p]=tt; 
							if(can2&&bit2[p]==0&&(tt=l3[l[p+a2]]+1)>l0[p])
								l0[p]=tt;                         
						} 
                     
					} 
				}
			} 
        printf("%d\n",c[curr][0]); 
    } 
	return 0;
} 