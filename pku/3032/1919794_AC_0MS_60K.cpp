#include <stdio.h>
int main()
{
	int n,nn;
	scanf("%d",&nn);
	while(nn-->0)
	{
		scanf("%d",&n);
		if(n==1)
			printf("1\n");
		else if(n==2)
			printf("2 1\n");
		else if(n==3)
			printf("3 1 2\n");
		else if(n==4)
			printf("2 1 4 3\n");
		else if(n==5)
			printf("3 1 4 5 2\n");
		else if(n==6)
			printf("4 1 6 3 2 5\n");
		else if(n==7)
			printf("5 1 3 4 2 6 7\n");
		else if(n==8)
			printf("3 1 7 5 2 6 8 4\n");
		else if(n==9)
			printf("7 1 8 6 2 9 4 5 3\n");
        else if(n==10)
			printf("9 1 8 5 2 4 7 6 3 10\n");
		else if(n==11)
			printf("5 1 6 4 2 10 11 7 3 8 9\n");
		else if(n==12)
			printf("7 1 4 9 2 11 10 8 3 6 5 12\n");
		else printf("4 1 13 11 2 10 6 7 3 5 12 9 8\n");
	}
	return 0;
}
