//315 - Network
//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

/*
Simple problem involving articulation points. The typical implementation of articulation
points (used here) looks messy at first, but it's quite simple despite the many vectors
used.
*/

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
vector<bool> articulation_vertex;
int dfsRoot, rootChildren;

void dfs(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	
	for(int i = 0; i < adjList[u].size(); i++){
		int v = adjList[u][i];
		
		if(dfs_num[v] == -1){
			dfs_parent[v] = u;
		
			if(u == dfsRoot) rootChildren++;
		
			dfs(v);
		
			if(dfs_low[v] >= dfs_num[u]){
				articulation_vertex[u] = true;
			}
		
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if(v != dfs_parent[u]){
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

int main(){
	int n, a, b, i;
	char r;
	
	while(scanf("%d", &n) > 0){
		if(n == 0) break;
		adjList.assign(n+1, vi());
		
		while(1){
			scanf("%d", &a);
			if(a == 0) break;
			scanf("%c", &r);
			while(1){
				scanf("%d", &b);
				adjList[a].pb(b);
				adjList[b].pb(a);
				scanf("%c", &r);
				if(r == '\n') break;
			}
		}
		
		dfsNumberCounter = 0;
		dfs_num.assign(n+1, -1);
		dfs_low.assign(n+1, 0);
		dfs_parent.assign(n+1, 0);
		articulation_vertex.assign(n+1,0);
		dfsNumberCounter = 0;
		dfsRoot = 1;
		rootChildren = 0;
		
		dfs(1);
		articulation_vertex[1] = (rootChildren > 1);
		
		int cont = 0;
		fr1(i,n){
			if(articulation_vertex[i]) cont++;
		}
		
		
		printf("%d\n", cont);
		
	}
	return 0;
}
