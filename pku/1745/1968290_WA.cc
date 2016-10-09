#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
long abs_sum(long nums[], long nCount);

bool Knap(long nums[], long nCount, long k)
{
 if(nCount == 0)
 {
  if(k == 0)
  {
   return true;
  }
  else
  {
   return false;
  }
 }
 else
 {
  bool bRet = Knap(nums, nCount-1, k - nums[nCount-1]);
  if(bRet == true)
  {
   return true;
  }
  else 
  {
   bRet = Knap(nums, nCount-1, k + nums[nCount-1]);
   if(bRet)
   {
    nums[nCount-1] *= -1;
   }
  
   return bRet;
  }
 }
}

long abs_sum(long nums[10000], long nCount)
{
 long result = 0;

 for(int i=0; i<nCount; ++i)
 {
  result += abs(nums[i]);
 }

 return result;
}

int main()
{
 long  nums[10000] = {0};
 long  n = 10, k;
 int   i;
 
 while(scanf("%d%d", &n, &k) == 2)
 {
  for(i=0; i<n; ++i)
   scanf("%ld", &nums[i]);

  long  total = abs_sum(nums, n);
  for(i=k; i<total; i+=k)
  {
   if(Knap(nums, n, i) == true)
   {
    printf("Divisible");
    break;
   }
  }

  if(i >= total)
   printf("Not divisible");
 }


 return 0;
}

		