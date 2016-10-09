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

/**����һ����2Ϊ����fft����˼·�����ڡ������źŴ���
 * ע�⣬�������FFT()ֻ֧��2^n����ģ����������Ļᡰ�ܷɡ�*/
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

	//��λ����
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

	//��������
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

/**������*/
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


/**ͬ��Ҫ��n=2^p���˺���������FFT���IFFT*/
void IFFT(cmpl X[],long n){
	long i;
	for(i=0;i<n;i++){
		X[i]=conj(X[i]);//ȡƵ����//������ĳЩ�汾�Ŀ���˺���Ϊconjg
	}
	FFT(X,n);
	for(i=0;i<n;i++){
		X[i]=conj(X[i]);//ȡʱ����
	}	
}


/**��������ֱ��Ǵ���a��b���Լ����ǵ�λ����c��Ž����,sizec=asize+bsize������ֵΪsizec*/
long hugeMult(int*a,long asize,int*b,long bsize,int*c){
	long m=asize+bsize-1;//��ȡֵ��Ϊ��ʹDFT/FFT�������׵�Բ�������ͨ�����ͬ��
	long n=1;
	while(n<m)n*=2;//ȡ�ö�Ӧ��2^p��ֵ
	//������asize���ϵ�λ��Ϊ�㣬Ӧ��0
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
		C[i]=A[i]*B[i];//ʱ��������Ƶ�����
	
	IFFT(C,n);
	
//	outCompArray(C,n);
	long csize=asize+bsize;
	for(i=0;i<csize;i++){
		c[i]=(int)((C[i].real()+0.5)/n);//ֱ��ת���Ļ��������⣬���������������İ취
	}
//	outIntArray(c,n);
	
	//ϵ������
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
	for(i=0;i<SIZE;i++){a[i]=1;b[i]=1;}//���ɲ����õ�����

	//a[0]=7,a[1]=6,a[2]=5,a[3]=4;
	//b[0]=7,b[1]=6,b[2]=5,b[3]=4;

	/**��������ֱ��Ǵ���a��b���Լ����ǵ�λ����c��Ž����,sizec=asize+bsize������ֵΪsizec*/	
	long sizec=hugeMult(a,SIZE,b,SIZE,c);
	//���ı�����õĴ���ʱ�������˵��������λ��

	//���
	for(i=sizec-1;i>0;i--){
		if(c[i]!=0)
			break;
	}
	cout<<i<<endl;//λ��
	//����������еı������ϵ�����ﵽX��λʱ���������������
	for(;i>=0;i--){
		cout<<c[i];
	}
	cout<<endl;

	system("pause");
	return 0;
	
}

