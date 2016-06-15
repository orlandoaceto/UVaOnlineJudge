//796 - Critical Links
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

vector<vi> adjList;
vi dfs_num;
vi dfs_low;
vi dfs_parent;
int dfsNumberCounter;
vii bridges;

void dfs(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	
	for(int i = 0; i < adjList[u].size(); i++){
		int v = adjList[u][i];
		
		if(dfs_num[v] == -1){
			dfs_parent[v] = u;
		
			dfs(v);
		
			if(dfs_low[v] > dfs_num[u]){
				bridges.pb(p(min(v,u),max(v,u)));
			}
		
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if(v != dfs_parent[u]){
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

int main(){
	int n, i, j, m, a, b;
	
	while(scanf("%d\n", &n) > 0){
		adjList.assign(n, vi());
		fr(i,n){
			scanf(" %d (%d)", &a, &m);
			fr(j,m){
				scanf(" %d", &b);
				adjList[a].pb(b);
			}
		}
		
		
		dfsNumberCounter = 0;
		dfs_num.assign(n, -1);
		dfs_low.assign(n, 0);
		dfs_parent.assign(n, 0);
		bridges.clear();
		dfsNumberCounter = 0;
		fr(i,n){
			if(dfs_num[i] == -1){
				dfs(i);
			}
		}
		
		
		sort(bridges.begin(), bridges.end());
		printf("%d critical links\n", (int)bridges.size());
		fr(i,(int)bridges.size()){
			printf("%d - %d\n", bridges[i].fi, bridges[i].se);
		}
		printf("\n");
	}
	

	return 0;
}
