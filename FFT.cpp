#include<complex>
#include<iostream>
#include<cmath>


using namespace std;

typedef complex<double> cmpl;


const long SIZE=100000;
const int R=10;
int a[SIZE];
int b[SIZE];
int c[SIZE*2];
cmpl A[SIZE*4],B[SIZE*4],C[SIZE*4];

/**这是一个以2为基的fft程序，思路来自于《数字信号处理》
 * 注意，这个函数FFT()只支持2^n个点的，其它点数的会“跑飞”*/
void FFT(cmpl A[],long N)
{
	cmpl temp;
	cmpl W,factor;
	cmpl t;
	long i,j,k;
	long I,J,K;
//	
//    for(i=0;i<N;i++)
//		A[i]=makeComp(x[i],0);

	//码位倒置
	J=1;
	for(I=1;I<N; I++){
		if (I<J){
			temp=A[J-1];
			A[J-1]=A[I-1];
			A[I-1]=temp;
		}
		K=N/2;
		while(K<J) { J-=K; K/=2; };
		J+=K;
	}

	//蝶形运算
	for(i=2;i<=N;i*=2){
		W=cmpl(cos(-2*M_PI/i),sin(-2*M_PI/i));
		for(j=0;j<N;j+=i){
			factor=cmpl(1,0);
			for(k=0;k<i/2;k++){
				t=A[j+k+i/2]*factor;
				A[j+k+i/2]=A[j+k]-t;
				A[j+k]	  =A[j+k]+t;
				factor=factor*W;
			}
		}
	}
}

/**调试用*/
void outCompArray(cmpl X[],long N)
{
	long i;
	for(i=0;i<N;i++){
		printf("X[%d]=%lf+i%lf\t",i,X[i].real(),X[i].imag());
	}
	printf("\n");
}
void outIntArray(int x[],long N)
{
	long i;
	for(i=0;i<N;i++){
		printf("x[%d]=%d\t",i,x[i]);
	}
	printf("\n");
}


/**同样要求n=2^p，此函数利用正FFT解决IFFT*/
void IFFT(cmpl X[],long n){
	long i;
	for(i=0;i<n;i++){
		X[i]=conj(X[i]);//取频域共轭//可能在某些版本的库里此函数为conjg
	}
	FFT(X,n);
	for(i=0;i<n;i++){
		X[i]=conj(X[i]);//取时域共轭
	}	
}


/**输入参数分别是大数a和b，以及它们的位数，c存放结果用,sizec=asize+bsize，返回值为sizec*/
long hugeMult(int*a,long asize,int*b,long bsize,int*c){
	long m=asize+bsize-1;//此取值是为了使DFT/FFT等相配套的圆卷积与普通卷积相同。
	long n=1;
	while(n<m)n*=2;//取得对应的2^p的值
	//这里，如果asize以上的位不为零，应赋0
//	cmpl A[n],B[n],C[n];
	
	long  i;
	for(i=0;i<asize;i++){
		A[i]=a[i];
	}
	for(;i<n;i++){
		A[i]=0;
	}
	for(i=0;i<asize;i++){
		B[i]=b[i];
	}
	for(;i<n;i++){
		B[i]=0;
	}
//	outCompArray(A,n);
//	outCompArray(B,n);
	
	FFT(A,n);
	FFT(B,n);
	
	for(i=0;i<n;i++)
		C[i]=A[i]*B[i];//时域卷积等于频域相乘
	
	IFFT(C,n);
	
//	outCompArray(C,n);
	long csize=asize+bsize;
	for(i=0;i<csize;i++){
		c[i]=(int)((C[i].real()+0.5)/n);//直接转换的话会有问题，这里采用四舍五入的办法
	}
//	outIntArray(c,n);
	
	//系数整理
	for(i=0;i<csize-1;i++){
		if(c[i]>=R){
			c[i+1]+=c[i]/R;
			c[i]%=R;
		}
	}
	//outIntArray(c,n);
	
	return csize;
}


int main(){
	//cout<<endl<<"fasdfas"<<endl;
	long i;
	for(i=0;i<SIZE;i++){a[i]=1;b[i]=1;}//生成测试用的数据

	//a[0]=7,a[1]=6,a[2]=5,a[3]=4;
	//b[0]=7,b[1]=6,b[2]=5,b[3]=4;

	/**输入参数分别是大数a和b，以及它们的位数，c存放结果用,sizec=asize+bsize，返回值为sizec*/	
	long sizec=hugeMult(a,SIZE,b,SIZE,c);
	//当改变计算用的大数时，别忘了调整这里的位数

	//输出
	for(i=sizec-1;i>0;i--){
		if(c[i]!=0)
			break;
	}
	cout<<i<<endl;//位数
	//输出：（在有的编译器上当输出达到X万位时将不能正常输出）
	for(;i>=0;i--){
		cout<<c[i];
	}
	cout<<endl;

	system("pause");
	return 0;
	
}

