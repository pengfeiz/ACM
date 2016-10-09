#include <stdio.h>
#define INF 1000000000
int b[1000010], c[1000010], a[1000010], n, m;
int maxsum(int m, int n, int *a)
{
	if(n < m || m < 1) return 0;
	int i, j, max, sum = 0;
	for(i = 0; i <= n; i++)
		b[i] = c[i] = 0;
	b[0] = 0; c[1] = 0;
	for(i = 1; i <= m; i++)
	{
		b[i] = b[i - 1] + a[i];
		c[i - 1] = b[i];
		max = b[i];
		for(j = i + 1; j <= i + n - m; j++)
		{
			b[j] = b[j - 1] > c[j - 1] ? b[j - 1] + a[j] : c[j - 1] + a[j];
			c[j - 1] = max;
			if(max < b[j]) max = b[j];
		}
		c[i + n - m] = max;
	}
	sum = -INF;
	for(j = m; j <= n; j++) if(sum < b[j]) sum = b[j];
	return sum;
}
int main(void)
{
	int i,tt;
scanf("%d",&tt);
m=2;
	while(tt--){
scanf("%d", &n);	
		for(i = 1; i <= n; i++) scanf("%d", &a[i]);
		printf("%d\n", maxsum(m, n, a));
	}
	return 0;
}
