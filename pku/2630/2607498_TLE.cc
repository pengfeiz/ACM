#include <stdio.h>

int M[25];
int Goal;
int R,C;
int no=1;
int m,pos,minn,p;

void Rec(int s,int i)
{
	if(s==Goal)
	{
		if(p<minn||(p==minn&&pos<m))
		{
			m=pos;
			minn=p;
		}
		return;
	}
	if(i+1<R*C)
	{
		Rec(s,i+1);
		p++;
		pos|=1<<(i+1);
		Rec(s^M[i+1],i+1);
		pos&=~(1<<(i+1));
		p--;
	}
}
  
int main()
{
	int r,c,i,j,r1,c1;
	char S[3][3],P[7][7];
	while(scanf("%d%d",&R,&C),R&&C)
	{
		printf("Case #%d\n",no++);
		Goal=0;
		for(i=0;i<R*C;i++)
		{
			Goal|=1<<i;
			M[i]=0;
		}
		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
				scanf(" %c",&S[i][j]);
		for(r=1;r<=R;r++)
			for(c=1;c<=C;c++)
			{
				for(i=0;i<7;i++)
					for(j=0;j<7;j++)
						P[i][j]=0;
				for(i=0;i<3;i++)
					for(j=0;j<3;j++)
						if(S[i][j]=='*') 
							P[r-1+i][c-1+j]=1;
				for(r1=1;r1<=R;r1++)
					for(c1=1;c1<=C;c1++)
						M[(r-1)*C+c-1]|=(P[r1][c1])<<((r1-1)*C+c1-1);
			}
		p=pos=0;
		m=(1<<(R*C));
		minn=R*C;
		Rec(0,0);
		p=1;
		pos=1;
		Rec(M[0],0);
		if(m==(1<<(R*C)))
			printf("Impossible.");
		else
		{
			int first=1;
			for(j=0;j<R*C;j++) 
				if(m&1<<j)
				{
					if(!first)
						printf(" ");
					else 
						first=0;
					printf("%d",j+1);
				}
		}	
		printf("\n");
	}
	return 0;
}



