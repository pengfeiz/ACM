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

bool quick_check_prime(hugeint Prime, int Times)
{
    if (Prime < 2) return false;
    if (Times > Prime - 2) Times = Prime - 2;
    for (int I = 0; I < Times; I++)
        if (power_mod(I + 2, Prime - 1, Prime) != 1) return false;
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
    if (quick_check_prime(N, 50)) return N;
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
