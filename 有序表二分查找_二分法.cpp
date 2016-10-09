#include <iostream>
using namespace std;

const int maxm=10000001;

int a[maxm],n;

int maxx(int a,int b)
{return a>b?a:b;}

int find(int i,int j)
{
	int mid=(i+j)/2;
	if(mid==i)
		return a[i];
	if(a[i]<a[mid]&&a[j]>a[mid])
		return find(mid,j);
	if(a[i]>a[mid]&&a[j]<a[mid])
		return find(i,mid);
	return maxx(find(i,mid),find(mid,j));
}

int binarysearch(int *a,int key)
{
    int low =0;
    int high = n-1;
    int mid;
    while(low<high)
    {
      mid = (low+high)/2;
      if(a[mid] == key)
                return mid;
      else if(key>a[mid])
                 low = mid+1;
      else 
                 high = mid-1;
    }   
    return -1;
    
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	//n=10000000;
//	for(i=0;i<n/2;i++)
	//	a[i]=i;
//	for(i=n/2;i<n;i++)
//		a[i]=n-i;
	//printf("%d\n",find(0,n));
	printf("%d\n",binarysearch(a,4));
	system("pause");
	return 0;
}
