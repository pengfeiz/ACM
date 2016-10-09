#include <iostream>
#include <string>
using namespace std;

unsigned long fac[10];
unsigned long howmany[9];
unsigned long bound[9][2];

void getfac(void)
{
	fac[0]=1;
	for(unsigned long i=1; i<=9; ++i)
		fac[i]=i*fac[i-1];
}

void gethowmany(void)
{
	howmany[1]=9;
	for(unsigned i=2; i<=8; ++i)
		howmany[i]=9*fac[9]/fac[10-i];
	for(unsigned j=2; j<=8; ++j)
		howmany[j]+=howmany[j-1];
}

void getbound(void)
{
	unsigned long p=1;
	for(long i=1; i<9; ++i){
		bound[i][0]=p;
		bound[i][1]=(p*=10)-1;
	}
}

string i2s(unsigned long i)
{
	string s;
	for(; i; i/=10)
		s=(char)(i%10+'0')+s;
	return s;
}

unsigned long count(string s)
{
	int len=s.length();
	unsigned long t=(s[0]-'0'-1)*fac[9]/fac[10-len];
	bool repeat=false;
	for(int i=1; i<len; ++i){
		int less=0;
		for(int j=0; j<i; ++j)
			if(s[j]<s[i])
				++less;
			else if(s[j]==s[i])
				repeat=true;
		t+=(s[i]-'0'-less)*fac[9-i]/fac[10-len];
		if( repeat )
			break;
	}
	if( repeat )
		return t;
	else
		return t+1;
}

bool repeated(unsigned long n)
{
	string s=i2s(n);
	int flag[10];
	memset(flag,0,sizeof(flag));
	for(int i=0; i<s.length(); ++i)
		++flag[s[i]-'0'];
	for(int j=0; j<10; ++j)
		if(flag[j]>1)
			return true;
	return false;
}

unsigned long select(unsigned long n,unsigned long a,unsigned long b)
{
	unsigned long m=(a+b)/2;
	unsigned long temp=count( i2s(m) );
	if( temp>n )
		return select(n,a,m);
	else if( temp<n )
		return select(n,m,b);
	else{
		while( repeated(m) )
			--m;
		return m;
	}
}

long main()
{
	getfac();
	gethowmany();
	getbound();

	unsigned long n;
	while(cin>>n,n){
		if(n<10)
			cout<<n<<endl;
		else{
			int i;
			for(i=1; howmany[i]<n; ++i)
				;
			cout<<select(n-howmany[i-1],bound[i][0],bound[i][1])<<endl;
		}
	}

	return 0;
}