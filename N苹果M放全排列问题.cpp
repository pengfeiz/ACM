#include <stdio.h>
#include<stdlib.h>
int m=10,n=8,total=0; //把m个无区别的球放进n个有区别的盒子，可重组合数total=C(m+n-1,m); 
int da[9];
int digui(int x,int y){
	int i;
	if (x==1) {
		total++;
		for (i=n;i>=2;i--) printf("%d ",da[i]);
		printf("%d\n",y);
		return 0;
	}
    for (i=0;i<=y;i++) {
		da[x]=i;
		digui(x-1,y-i);
	}
	
	return 0;
}
int main(){
    printf("start");
	freopen("out.txt","w",stdout);
	digui(n,m);
	printf("%d\n",total);
	printf("finish");
	system("pause");

	return 0;
} 
