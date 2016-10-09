#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAXN=500;

int A[MAXN][MAXN],B[MAXN][MAXN],C[MAXN][MAXN];
int x[MAXN],ans1[MAXN],ans2[MAXN],ans3[MAXN];

int main() {
	int n,t;
	t=15;
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>A[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>B[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>C[i][j];
	while(t--) {
		srand((long)time(NULL));
		for(int i=0;i<n;i++)
			x[i]=rand()%10;
		for(int i=0;i<n;i++) {
			long long total=0;
			for(int j=0;j<n;j++)
				total+=x[j]*A[j][i];
			ans1[i]=total;
		}
		for(int i=0;i<n;i++) {
			long long total=0;
			for(int j=0;j<n;j++)
				total+=ans1[j]*B[j][i];
			ans2[i]=total;
		}
		for(int i=0;i<n;i++) {
			long long total=0;
			for(int j=0;j<n;j++)
				total+=x[j]*C[j][i];
			ans3[i]=total;
		}
		bool ok=true;
		for(int i=0;i<n;i++)
			if(ans2[i]!=ans3[i]) {
				ok=false;
				break;
			}
		if(ok==false) {
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}
