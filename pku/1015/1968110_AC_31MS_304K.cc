#include <iostream>
#include <stdlib.h>
using namespace std;

#define POOL_MAX 200
#define VALUE_MAX 20
#define JURY_MAX 20

int prosecution[POOL_MAX],defense[POOL_MAX];
int m,n;
int caseno=1;

int last[JURY_MAX][2*VALUE_MAX*JURY_MAX+1];
int sum[JURY_MAX][2*VALUE_MAX*JURY_MAX+1];

int compare(const void *a, const void *b)
{
  return *(int *)a-*(int *)b;
}

void solve_case()
{
	int i,j,k,l,l2;
	int sol[JURY_MAX];
	for(i=0;i<m;i++)
		for(j=0;j<2*VALUE_MAX*m+1;j++) 
			last[i][j]=sum[i][j]=-1;
	for(i=0;i<n;i++)
		if(prosecution[i]+defense[i]>sum[0][VALUE_MAX*m+prosecution[i]-defense[i]])
		{
			last[0][VALUE_MAX*m+prosecution[i]-defense[i]]=i;
			sum[0][VALUE_MAX*m+prosecution[i]-defense[i]]=prosecution[i]+defense[i];
		}

  /* build upon that to solve problem for 2,3,...m jurors */
  for(j=0;j<m-1;j++)
    for(k=0;k<2*VALUE_MAX*m;k++)
      if(last[j][k] >= 0)
	for(i=0;i<n;i++)
	  if(sum[j+1][k+prosecution[i]-defense[i]] <
	     sum[j][k] + prosecution[i] + defense[i])
	    {
	      /* make sure that every person is used only once in a jury */
	      for(l=j,l2=k;l>=0;l--)
		{
		  if(last[l][l2] == i) break;
		  l2 -= prosecution[last[l][l2]]-defense[last[l][l2]];
		}
	      if(l < 0)
		{
		  /* add person to jury */
		  last[j+1][k+prosecution[i]-defense[i]] = i;
		  sum[j+1][k+prosecution[i]-defense[i]] = 
		    sum[j][k] + prosecution[i] + defense[i];
		}
	    }
	    
  /* determine minimum possible |D(J)-P(J)| */
  for(i=0;i<=VALUE_MAX*m;i++)
    if(sum[m-1][VALUE_MAX*m+i] >= 0 || sum[m-1][VALUE_MAX*m-i] >= 0)
      {
	if(sum[m-1][VALUE_MAX*m+i] > sum[m-1][VALUE_MAX*m-i])
	  i = VALUE_MAX*m+i;
	else
	  i = VALUE_MAX*m-i;
	break;
      }
  
  /* output solution in the desired format */
  printf("Jury #%d\n",caseno++);
  printf("Best jury has value %d for prosecution and value %d for defence:\n",
	 (sum[m-1][i]+(i-VALUE_MAX*m))/2,(sum[m-1][i]-(i-VALUE_MAX*m))/2);
  for(j=m-1;j>=0;j--)
    {
      sol[j] = last[j][i]+1;
      i -= prosecution[last[j][i]]-defense[last[j][i]];
    }
  qsort(sol,m,sizeof(int),compare);
  for(i=0;i<m;i++) printf(" %d",sol[i]);
  printf("\n\n");
}

int read_case()
{
    int i;
    cin>>n>>m;
    if(n == 0) 
		return 0;
    for(i=0;i<n;i++)
        cin>>prosecution[i]>>defense[i];
    return 1;
}

int main()
{
    while(read_case()) 
		solve_case();
    return 0;
}

