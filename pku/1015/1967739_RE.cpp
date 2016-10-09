/* Solution: JURY */

#include <stdio.h>
#include <stdlib.h>

#define POOL_MAX 201
#define VALUE_MAX 21
#define JURY_MAX 21

FILE *inp;
int prosecution[POOL_MAX],defense[POOL_MAX];
int m,n;
int caseno = 1;

int last[JURY_MAX][2*VALUE_MAX*JURY_MAX+1];
int sum[JURY_MAX][2*VALUE_MAX*JURY_MAX+1];

int compare(const void *a, const void *b)
{
  return *((const int *) a) - *((const int *) b);
}

/* solve problem by dynamic programming:
   * for each number of jurors 1,...,m, and for each distance D(J)-P(J), 
     the maximum possible sum D(J)+P(J) (at the given distance) is computed by
     dynamic programming
   * at the end we just have to read off the minimal possible distance and the
     corresponding maximum sum
*/

void solve_case()
{
  int i,j,k,l,l2;
  int sol[JURY_MAX];

  /* initialize array */
  for(i=0;i<m;i++)
    for(j=0;j<2*VALUE_MAX*m+1;j++) 
      last[i][j] = sum[i][j] = -1;

  /* solve problem for 1 juror */
  for(i=0;i<n;i++)
    if(prosecution[i] + defense[i] > 
       sum[0][VALUE_MAX*m+prosecution[i]-defense[i]])
      {
	last[0][VALUE_MAX*m+prosecution[i]-defense[i]] = i;
	sum[0][VALUE_MAX*m+prosecution[i]-defense[i]] = 
	  prosecution[i] + defense[i];
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

/* read in one input case */

void skip_line() { while(getc(inp) >= ' '); }


int read_case()
{
  int i;

  fscanf(inp,"%d %d",&n,&m); 
  if(n == 0) return 0;
  skip_line();
  if(n < m)
    fprintf(stderr,"ERROR: n < m\n");
  for(i=0;i<n;i++)
    {
      fscanf(inp,"%d %d",prosecution+i,defense+i);
      skip_line();
    }
  return 1;
}

int main()
{
  inp = fopen("jury.in","r");
  while(read_case()) solve_case();
  fclose(inp);
  return 0;
}

