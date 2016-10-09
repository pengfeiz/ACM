#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;
const char NUL = '\0';

const int V = 1000;
const int E = 100000;
const int K = 1000;

struct Ent
{
	int d;
	int v;
};

int G[V][V][2], deg[V], nvert, ne;
int G2[V][V][2], deg2[V];
Ent heap[E * 30];
int nheap;
int visit[V];
int dist[V];

bool Cmp(const Ent &a, const Ent &b)
{
	return a.d > b.d;
}

bool Cmp2(const Ent &a, const Ent &b)
{
	return a.d + dist[a.v] > b.d + dist[b.v];
}

void Dijkstra(int t)
{
	memset(dist, -1, sizeof(*dist) * nvert);
	memset(visit, 0, sizeof(*visit) * nvert);
	dist[t] = 0;
	heap[0].d = 0; heap[0].v = t; nheap = 1;
	while(nheap)
	{
		int v = heap[0].v, d = heap[0].d;
		pop_heap(heap, heap + nheap--, Cmp);
		if(visit[v]) continue;
		visit[v] = 1;
		for(int i = 0; i < deg2[v]; i++)
		{
			int nv = G2[v][i][0];
			int nd = d + G2[v][i][1];
			if(dist[nv] == -1 || nd < dist[nv])
			{
				dist[nv] = nd;
				heap[nheap].d = nd;
				heap[nheap].v = nv;
				push_heap(heap, heap + ++nheap, Cmp);
			}
		}
	}
}

int Solve(int s, int t, int k)
{
	if(s == t) ++k;
	Dijkstra(t);
	memset(visit, 0, sizeof(*visit) * nvert);
	if(dist[s] == -1) return -1;
	heap[0].d = 0; heap[0].v = s; nheap = 1;
	while(nheap)
	{
		int v = heap[0].v;
		int d = heap[0].d;
		pop_heap(heap, heap + nheap--, Cmp2);
		if(visit[v] == k) continue;
		++visit[v];
		if(v == t)
		{
			if(visit[v] == k) return d;
		}
		for(int i = 0; i < deg[v]; i++)
		{
			int nv = G[v][i][0];
			if(dist[nv] == -1 || visit[nv] == k) continue;
			int nd = d + G[v][i][1];
			heap[nheap].v = nv;
			heap[nheap].d = nd;
			push_heap(heap, heap + ++nheap, Cmp2);
		}
	}
	return -1;
}

int main(void)
{
	scanf("%d %d", &nvert, &ne);
	for(int i = 0; i < ne; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		--a; --b;
		G[a][deg[a]][0] = b;
		G[a][deg[a]][1] = c;
		++deg[a];
		G2[b][deg2[b]][0] = a;
		G2[b][deg2[b]][1] = c;
		++deg2[b];
	}
	int s, t, k;
	scanf("%d %d %d",&s,&t,&k);
	printf("%d\n", Solve(--s, --t, k));
	return 0;
}
