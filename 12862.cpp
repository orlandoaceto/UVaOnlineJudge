//12862 - Intrepid climber
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

vector<vii> adj;
vector<bool> frd;
int total, maxi;

void dfs(int v, int parent, int dist, int &friends){
	int i;
	
	int f;
	
	friends = 0;
	if(frd[v]){
		maxi = max(maxi, dist);
		friends = 1;
	}
	
	fr(i,adj[v].size()){
		if(adj[v][i].fi != parent){
			dfs(adj[v][i].fi, v, dist + adj[v][i].se, f);
			if(f > 0){
				total += adj[v][i].se;
				friends += f;
			}
		}
	}
	
}

int main(){
	int n, f, i, j;
	int u, v, w;
	
	while(scanf("%d %d", &n, &f) > 0){
		adj.assign(n+1, vii());
		frd.assign(n+1, 0);
		
		fr(i,n-1){
			scanf("%d %d %d", &u, &v, &w);
			adj[u].pb(ii(v, w));
			adj[v].pb(ii(u, w));
		}
		fr(i,f){
			sc(u);
			frd[u] = 1;
		}
		total = 0;
		maxi = 0;
		int x;
		dfs(1, 0, 0, x);
		printf("%d\n", total - maxi);
	}
	
	return 0;
}
