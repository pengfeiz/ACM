#include<iostream>
#include <algorithm>

using namespace std;

#define Max 1001
int a[Max][Max],b[Max][Max],c[Max][Max],xx[Max],y[Max],z[Max],xy[Max];
int main()
{
  int i,j,n;
  //freopen("in.txt","r",stdin);
  memset(a,0,sizeof(a));
  memset(b,0,sizeof(b));
  memset(c,0,sizeof(c));

  scanf("%d",&n);
for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
		  scanf("%d",&a[i][j]);

 for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
		  scanf("%d",&b[i][j]);

 for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
		  scanf("%d",&c[i][j]);
  memset(xy,0,sizeof(xy));
  memset(y,0,sizeof(y));
  memset(z,0,sizeof(z));


  for(i=0;i<n;i++)
      xx[i]=rand()%10;
  xx[0]=-123;
  for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
		  y[i]+=xx[j]*a[j][i];

	  for(i=0;i<n;i++)
		 for(j=0;j<n;j++)
		   xy[i]+=y[j]*b[j][i];

		  for(i=0;i<n;i++)
			  for(j=0;j<n;j++)
				  z[i]+=xx[j]*c[j][i];

			  for(i=0;i<n;i++)
			  {
				  if(xy[i]!=z[i])
				  {	
					  printf("NO\n");
					  return 0;
				  }
			  }

	printf("YES\n");
	return 0;
}
