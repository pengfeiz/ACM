#include <stdio.h>
int n23[3][5]={{6,2,4,8,1},{1,3,9,7},{1,5}};
int d2, d3, d5;
void Get3(int n) {
	int mod10=n%10;
	d3+=n/10*6;
	if(mod10==9) d3 += 6;
	else if(mod10>6) d3+=4;
	else if(mod10>2) d3+=1;
}
void fact5(int n) {
	for(;n>4;n/=5){
		d5+=(n+5)/10;
		Get3(n/5);
	}
}
void fact2(int n) {
	for(;n>1;n/=2){
		d2+=n/2;
		Get3(n);
		fact5(n);
	}
}
int main() {
	int n, m;
	while(scanf("%d %d", &n, &m)!=EOF) {
		d2=d3=d5=0;
		fact2(n-m);
		d2=-d2; d3=-d3; d5=-d5;
		fact2(n);
		if(d2<=d5) d5=(d5-d2)>=1, d2=4;
		else d2=(d2-d5)%4, d5=0;
		d3=d3%4;
		printf("%d\n", (n23[0][d2]*n23[1][d3]*n23[2][d5])%10);
	}
	return 0;
}