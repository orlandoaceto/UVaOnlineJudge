//11709 - Trust groups
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

vi dfs_num, dfs_low, S, visited;
vector<vi> adjList;
int dfsNumCount, numSCC;

void tarjanSCC(int u){
	dfs_low[u] = dfs_num[u] = dfsNumCount++;
	S.pb(u);
	visited[u] = 1;
	for(int j = 0; j < (int)adjList[u].size(); j++){
		int v = adjList[u][j];
		
		if(dfs_num[v] == -1)
			tarjanSCC(v);
		if(visited[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	
	if(dfs_low[u] == dfs_num[u]){
		numSCC++;
		//printf("SCC %d:", ++numSCC);
		while(1){
			int v = S.back(); S.pop_back(); visited[v] = 0;
			//printf(" %d", v);
			if(u == v) break;
		}
		//printf("\n");
	}
}


int main(){
	int p, t, i, j, a, b, count;
	string s, sAux;
	map<string, int> ma;
	
	while(scanf("%d %d", &p, &t) > 0){
		if(p == 0 && t == 0) break;
		
		count = 0;
		ma.clear();
		fr(i,p){
			cin>>s>>sAux;
			s = s+sAux;
			ma[s] = count++;
		}
		
		adjList.assign(p, vi());
		
		fr(i,t){
			cin>>s>>sAux;
			s = s+sAux;
			a = ma[s];
			cin>>s>>sAux;
			s = s+sAux;
			b = ma[s];
			adjList[a].pb(b);
		}
		
		dfs_num.assign(p, -1);
		dfs_low.assign(p, 0);
		visited.assign(p, 0);
		dfsNumCount = numSCC = 0;
		fr(i,p) if(dfs_num[i] == -1) tarjanSCC(i);
		
		printf("%d\n", numSCC);
		
	}
	
	return 0;
}
