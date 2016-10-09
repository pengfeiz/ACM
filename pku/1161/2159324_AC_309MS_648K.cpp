#include <iostream>
using namespace std;
#define MAX 99999999

int main()
{
	int F[201][201],C[251][251],U[31],A[251][201],m,n,l,i,j,k,x,first,temp,last,min,sum;
	scanf("%d%d%d",&m,&n,&l);
	for(i=0;i<l;i++)
		scanf("%d",&U[i]);
	for(i=0;i<m;i++)
		for(j=0;j<m;j++)
		{	if(j==i)
				F[i][j]=0; 
			else 
				F[i][j]=MAX;
		}
	memset(C,0,sizeof(C));
	memset(A,0,sizeof(A));
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&temp,&first);
		last=first;
		A[first][i]=1;
		for(j=1;j<temp;j++)
		{
			scanf("%d",&x);
			A[x][i]=1;
			if(C[last][x]>0)
				F[C[last][x]-1][i]=F[i][C[last][x]-1]=1;
			else
				C[last][x]=C[x][last]=i+1;
			last=x;
		}
		if(C[last][first]>0)
			F[C[last][first]-1][i]=F[i][C[first][last]-1]=1;
		else 
			C[last][first]=C[first][last]=i+1;
	}
	for(k=0;k<m;k++)
		for(i=0;i<m;i++)
			for(j=0;j<m;j++)
				if(F[i][k]+F[k][j]<F[i][j])
					F[i][j]=F[i][k]+F[k][j];
	min=MAX;
	for(i=0;i<m;i++)
	{
		sum=0;
		for(j=0;j<l;j++)
		{
			temp=MAX;
			for(k=0;k<m;k++)
			{
				if(A[U[j]][k]==0)
					continue;
				if(temp>F[k][i])
					temp=F[k][i];
			}
			sum+=temp;
		}
		if(min>sum)
			min=sum;
	}
	printf("%d\n",min);
	return 0;
}


