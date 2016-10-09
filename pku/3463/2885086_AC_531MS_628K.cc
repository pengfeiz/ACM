/*
  [BAPC'06] SIGHTSEEING
  by: Jan Kuipers
*/

using namespace std;

#include <iostream>
#include <vector>
#include <queue>

int main () {

  int runs;
  cin>>runs;
  while (runs--) {

    int N,M,start,end;
    cin>>N>>M;
    vector<vector<int> > to(N),len(N);

    for (int i=0; i<M; i++) {
      int a,b,l;
      cin>>a>>b>>l;
      a--; b--;

      to[a].push_back(b);
      len[a].push_back(l);
    }

    cin>>start>>end;
    start--; end--;

    vector<int> dist(N,INT_MAX), seen0(N,0), seen1(N,0);
    vector<long long> cnt0(N,0), cnt1(N,0);
    priority_queue<pair<int,int> > pq;
    
    pq.push(make_pair(0,start));
    dist[start]=0;
    cnt0[start]=1;

    while (!pq.empty()) {
      long long cnt = -1;
      int n = pq.top().second;
      int d = -pq.top().first;
      pq.pop();

      if (d==dist[n]  ) if (seen0[n]) continue; else seen0[n]=1, cnt=cnt0[n];
      if (d==dist[n]+1) if (seen1[n]) continue; else seen1[n]=1, cnt=cnt1[n];
      if (d> dist[n]+1) continue;

      for (int i=0; i<to[n].size(); i++) {
	int nn = to[n][i];
	int nd = d+len[n][i];

	if (nd<dist[nn]) {
	  cnt1[nn] = nd==dist[nn]-1 ? cnt0[nn] : 0;
	  cnt0[nn] = cnt;
	  dist[nn] = nd;
	}
	else if (nd==dist[nn])
	  cnt0[nn] += cnt;
	else if (nd==dist[nn]+1)
	  cnt1[nn] += cnt;
	else
	  continue;

	pq.push(make_pair(-nd,nn));
      }
    }

    cout << cnt0[end]+cnt1[end] << endl;
  }
  
  return 0;
}
