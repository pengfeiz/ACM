#include <iostream>
using namespace std;
#define MAX 100000

double a[MAX];
int main()
{
	int i;
	a[0]=0.0;
	for(i=1;i<MAX;i++)
		a[i]=a[i-1]+1/(2*i);
	printf("Cards  Overhang\n");
	while(scanf("%d",&i)!=EOF)
		printf("%5d%10.3lf\n");
	return 0;
}