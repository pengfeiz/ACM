#include <iostream>
using namespace std;
#define MAX 10000001
int n,q;
int a[MAX][2];
void Stern_Brocot_Tree(int dom,int don,int leftm,int leftn,int rightm,int rightn)
{
	if(don>n)
		return;
	Stern_Brocot_Tree(dom+leftm,don+leftn,leftm,leftn,dom,don);
	a[q][0]=dom;
	a[q][1]=don;
	q++;
	Stern_Brocot_Tree(dom+rightm,don+rightn,dom,don,rightm,rightn);
}

int main()
{
	int m,c;
	q=1;
	a[0][0]=0;
	a[0][1]=1;
	scanf("%d%d",&n,&c);
	Stern_Brocot_Tree(1,2,0,1,1,1);
	a[q][0]=a[q][1]=1;
	while(c--)
	{
		scanf("%d",&m);
		if(m>q+1)
			printf("No Solution\n");
		else
			printf("%d/%d\n",a[m-1][0],a[m-1][1]);
	}
	return 0;
}
