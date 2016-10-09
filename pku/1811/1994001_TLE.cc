#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long hugeint;

int NN;
hugeint N;

hugeint gcd(hugeint A, hugeint B)
{
    while (A != 0)
    {
        hugeint C = B % A;
        B = A;
        A = C;
    }
    return B;
}

hugeint product_mod(hugeint A, hugeint B, hugeint C)
{
    hugeint R, D;
    R = 0;
    D = A;
    while (B > 0)
    {
        if (B % 2 == 1) R = (R + D) % C;
        D = (D + D) % C;
        B /= 2;
    }
    return R;
}

hugeint power_mod(hugeint A, hugeint B, hugeint C)
{
    hugeint R = 1, D = A;
    while (B > 0)
    {
        if (B % 2 == 1) R = product_mod(R, D, C);
        D = product_mod(D, D, C);
        B /= 2;
    }
    return R;
}
hugeint modular(hugeint a,hugeint b,hugeint n)
{
	hugeint d,x,c[64];
	d=1;
	x=0;
	while(b>0)
	{
		c[x]=b%2;
		x++;
		b/=2;
	}
	while(x-->=0)
	{
		d=(d*d)%n;
		if(c[x]==1)
			d=(d*a)%n;
	}
	return d;
}

bool witness(hugeint a,hugeint n)
{
	hugeint u,x,t=0,xx,i;
	u=n-1;
	while(u%2==0)
	{
		u/=2;
		t++;
	}
	xx=modular(a,u,n);
	for(i=0;i<t;i++)
	{
		x=(xx*xx)%n;
		if(x==1&&xx!=1&&xx!=n-1)
			return true;
		xx=x;
	}
	if(x!=1)
		return true;
	return false;
}

bool miller(hugeint n)
{
	if(n==2)
		return true;
	if(n%2==0||n==1)
		return false;
	int i;
	hugeint x;
	for(i=0;i<100;i++)
	{
		x=rand()%(n-2)+1;
		if(witness(x,n))
			return false;
	}
	return true;
}

hugeint pollard_rho(hugeint C, hugeint N)
{
    hugeint I, X, Y, K, D;
    I = 1;
    X = rand() % N;
    Y = X;
    K = 2;
    do
    {
        I++;
        D = gcd(N + N + Y - X, N);
        if (D > 1 && D < N) return D;
        if (I == K) Y = X, K *= 2;
        X = (product_mod(X, X, N) + N - C) % N;
    }
    while (Y != X);
    return N;
}

hugeint rho(hugeint N)
{
    if (miller(N)) return N;
    do
    {
        hugeint T = pollard_rho(rand() % (N - 1) + 1, N);
        if (T < N)
        {
              hugeint A, B;
              A = rho(T);
              B = rho(N / T);
              return A < B ? A : B;
        }
    }
    while (true);
}

int main()
{
    scanf("%d", &NN);
    while (NN-- > 0)
    {
        scanf("%I64d", &N);
        hugeint V = rho(N);
        if (V == N) cout << "Prime" << endl;
        else cout << (int)V << endl;
    }
    return 0;
} 
