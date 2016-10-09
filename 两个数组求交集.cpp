#include<iostream>
#include<queue>
#define M 2
#define N 3
using namespace std;
int main()
{
	int a[M],b[N];
	queue<int> q;
	for(int i=0;i<M;i++){
		a[i] = rand()%M;
		
		printf("%5d",a[i]);
		
	}
	printf("\n");
		for(int i=0;i<N;i++){
		b[i] = rand()%N;
		
		printf("%5d",b[i]);
		
	}	printf("\n");

	system("pause");
	return 0;
}
