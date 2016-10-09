#include <iostream.h>
#include <stdio.h>
#include <math.h>

long p[20];
long s[20];
unsigned __int64 sum = 0;
int COUNT =0;
long M=0;
long N=0;
unsigned __int64 getsum(int m){
int i=1;
long temp=M;
unsigned __int64 temp2 = 1;
for(i=1;i<=m;i++){
	temp/=p[s[i]];
}
for(i=1;i<=N;i++){
temp2=temp2*temp;}
return temp2;
}

void zuhe(int x,int y,int m){
	if(y<=m){
	int i;
	for(i=x;i<=COUNT-m+y;i++){
	s[y]=i;
	if(y==m){sum+=getsum(m);}
	else zuhe(x+1,y+1,m);
	x++;//为了改变上一步else zuhe(x+1,y+1);
	    //只是改变x，并没有改变y；
	}
	}
}


void main(){
long m,mm;
long n;
int count = 0;
long i=1;
long temp = 1;

while(cin>>n>>m){//对m进行分解
	count = 0;
	i = 1;
	temp = 1;
mm = m;
if(m==1){cout<<"1"<<endl;}
 else{
    for(i=2;i<=mm;i++){
	    if(m%i==0){
	      if(i!=temp){
	       count++;
	       p[count] = i;
	       temp = i;
		  }
	      m/=i;
		  if(m==1){break;}
	      i--;//例如8的质因数是2，2，2，我们必须
        //连续3次检测2是否是他的质因数
		}
	}
  N = n;M =mm;COUNT = count;
  //long temp = 0;
  unsigned __int64 temp = 0;
  unsigned __int64 SUM=0;
  unsigned __int64 gogo = 1;
     for(i=1;i<=count;i++){
     zuhe(1,1,i); 
     temp = sum;
	 sum=0;
     SUM+=( (int)pow(-1,i-1)*temp);
	 }
	 for(i = 1;i<=n;i++){
		 gogo = gogo*mm;}
  printf("%I64d",(gogo-SUM));
  cout<<endl;
 }


}
return 0;

}
