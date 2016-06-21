//11504 - Dominos
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
vector<vi> adjSCC;
vi incomingSCC, numSCCVert;

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
		if(visited[v]) //Inútil?
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	
	if(dfs_low[u] == dfs_num[u]){
		incomingSCC.pb(0);
		while(1){
			int v = S.back(); S.pop_back(); visited[v] = 0;
			numSCCVert[v] = numSCC;
			if(u == v) break;
		}
		numSCC++;
	}
}


int main(){

	int n, i, j, t, m;
	int x, y;
	scanf("%d", &t);

	while(t--){
		scanf("%d %d", &n, &m);
		
		adjList.assign(n,vi());
		fr(i,m){
			scanf("%d %d", &x, &y);
			adjList[x-1].pb(y-1);
		}
		
		dfs_num.assign(n, -1);
		dfs_low.assign(n, 0);
		visited.assign(n, 0);
		dfsNumCount = numSCC = 0;
		incomingSCC.clear();
		numSCCVert.assign(n, 0);
		
		fr(i,n) if(dfs_num[i] == -1) tarjanSCC(i);
		
		fr(i,n){
			fr(j,adjList[i].size()){
				if(numSCCVert[i] != numSCCVert[adjList[i][j]])
					incomingSCC[numSCCVert[adjList[i][j]]]++;
			}
		}
		int ans = 0;
		fr(i,numSCC){
			if(incomingSCC[i] == 0) ans++;
		}
		printf("%d\n", ans);
		
	}

	return 0;
}
