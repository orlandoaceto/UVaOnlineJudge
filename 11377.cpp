//11377 - Airport Setup
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
	int n, m, k, i, j, t, q, num;
	int a, b, c;
	vector<vii> adjList;
	vector<bool> airport;
	priority_queue<ii, vii, greater<ii> > qu;
	int dist[2010];
	
	sc(t);
	fr1(num, t){
		scanf("%d %d %d", &n, &m, &k);
		adjList.assign(n+1, vii());
		airport.assign(n+1, 0);
		fr(i,k){
			sc(a);
			airport[a] = 1;
		}
		
		fr(i,m){
			scanf("%d %d", &a, &b);
			adjList[a].pb(ii(b, airport[b]?0:1));
			adjList[b].pb(ii(a, airport[a]?0:1));
		}
		
		sc(q);
		printf("Case %d:\n", num);
		while(q--){
			scanf("%d %d", &a, &b);
			if(a != b){
				memset(dist, 0x3f, sizeof dist);
				qu.push(ii(airport[a]?0:1, a));
				dist[a] = airport[a]?0:1;
				while(!qu.empty()){
					a = qu.top().se;
					c = qu.top().fi;
					qu.pop();
				
					if(c > dist[a]) continue;
				
					fr(i,adjList[a].size()){
						int next = adjList[a][i].fi;
						int cost = adjList[a][i].se;
						if(dist[next] > dist[a] + cost){
							dist[next] = dist[a] + cost;
							qu.push(ii(dist[next], next));
						}
					}
				}
				if(dist[b] < oo){
					printf("%d\n", dist[b]);
				}
				else{
					printf("-1\n");
				}
			}
			else{
				printf("0\n");
			}
		}
		printf("\n");
	}
	
	return 0;
}
