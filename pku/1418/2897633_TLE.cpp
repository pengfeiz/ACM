//多圆覆盖以后剩余圆个数

#include <iostream>
#include <complex>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define PI 3.1415926535897932384626433832795028841971693993751058209

typedef complex<double> xy;

double Normalize(double Radius)
{
	while(Radius < 0.0) Radius += 2 * PI;
	while(Radius >= 2 * PI) Radius -= 2 * PI;
	return Radius;
}

int Highest_Cover(xy p, vector<xy> &points, vector<double> &rs)
{
	int i;
	for(i = rs.size() - 1; i >= 0; i--)
		if(abs(points[i] - p) < rs[i])
			return i;
	return -1;
}

int main(void)
{
	int i, j, k, n;
	while(scanf("%d", &n), n != 0)
	{
		vector<xy> points;
		vector<double> rs;
		for(i = 0; i < n; i++)
		{
			double x, y, r;
			scanf("%lf %lf %lf", &x, &y, &r);
			points.push_back(xy(x, y));
			rs.push_back(r);
		}
		vector<bool> visible(n, false);
		for(i = 0; i < n; i++)
		{
			vector<double> rads;
			rads.push_back(0.0);
			rads.push_back(2.0 * PI);
			for(j = 0; j < n; j++)
			{
				double a = rs[i];
				double b = abs(points[j] - points[i]);
				double c = rs[j];
				if(a + b < c || a + c < b || b + c < a) continue;
				double d = arg(points[j] - points[i]);
				double e = acos((a * a + b * b - c * c) / (2 * a * b));
				rads.push_back(Normalize(d + e));
				rads.push_back(Normalize(d - e));
			}
			sort(rads.begin(), rads.end());
			for(j = 0; j < rads.size() - 1; j++)
			{
				double rad = (rads[j] + rads[j + 1]) / 2.0;
				double dif = 4e-13;
				for(k = -1; k <= 1; k++)
				{
					xy nn = xy(points[i].real() + (rs[i] + dif * k) * cos(rad), points[i].imag() + (rs[i] + dif * k) * sin(rad));
					int t = Highest_Cover(nn, points, rs);
					if(t != -1) visible[t] = true;
				}
			}
		}
		int count = 0;
		for(i = 0; i < n; i++) if(visible[i]) count++;
		printf("%d\n", count);
	}
	return 0;
}