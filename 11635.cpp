//11635 - Hotel booking
//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define fr1(a, n) for(a = 1; a <= n; a++)
#define frR(a, n) for (a = n; a >= 0; a--)
#define sc(a) scanf("%d", &a)
#define pr(a) printf("%d\n", a)
#define p(i, j) make_pair(i, j)
#define fi first
#define se second
#define pb push_back
#define clr(a) memset(a, 0, sizeof a);

const int oo = 0x3f3f3f3f;

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

int main(){
	priority_queue<ii, vii, greater<ii> > pq;
	queue<int> q;
	vector<vii> adjList;
	vector<vi> adj;
	int n, m, h, i, j;
	int u, v, w;
	int hotels[102], dist[10001];
	
	while(scanf("%d", &n) > 0){
		if(n == 0) break;
		adjList.assign(n+1, vii());
		hotels[0] = 1;
		sc(h);
		for(i = 1; i <= h; i++) sc(hotels[i]);
		hotels[h+1] = n;
		sc(m);
		fr(i,m){
			scanf("%d %d %d", &u, &v, &w);
			adjList[u].pb(ii(v,w));
			adjList[v].pb(ii(u,w));
		}
		adj.assign(h+2, vi());
		fr(i, h+2){
			pq.push(ii(0,hotels[i]));
			memset(dist, 0x3f, sizeof dist);
			dist[hotels[i]] = 0;
			while(!pq.empty()){
				int at = pq.top().se;
				int c = pq.top().fi;
				pq.pop();
				if(dist[at] > c) continue;
				int i;
				fr(i,adjList[at].size()){
					int next = adjList[at][i].fi;
					int cost = adjList[at][i].se;
					if(c + cost < dist[next]){
						dist[next] = c + cost;
						pq.push(ii(c+cost, next));
					}
				}
			}
			fr(j,h+2){
				if(hotels[i] != hotels[j]){
					if(dist[hotels[j]] <= 600){
						adj[i].pb(j);
					}
				}
			}
		}
		memset(dist, 0x3f, sizeof dist);
		dist[0] = -1;
		q.push(0);
		
		while(!q.empty()){
			int at = q.front();
			q.pop();
			fr(i,adj[at].size()){
				int next = adj[at][i];
				if(dist[at] + 1 < dist[next]){
					dist[next] = dist[at]+1;
					q.push(next);
				}
			}
		}
		
		if(dist[h+1] < oo){
			printf("%d\n", dist[h+1]);
		}
		else{
			printf("-1\n");
		}
		
	}
	
	
	return 0;
}
