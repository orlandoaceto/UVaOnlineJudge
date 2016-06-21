//11518 - Dominos 2
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
vector<bool> vis;
int counter;

void dfs(int v){
	
	if(vis[v]) return;	

	vis[v] = 1;
	counter++;

	int i;
	fr(i,adjList[v].size()){
		dfs(adjList[v][i]);
	}
}

int main(){
	int n, m, l, t;
	int i, x, y;
	
	sc(t);
	
	while(t--){
		scanf("%d %d %d", &n, &m, &l);
		
		adjList.assign(n+1, vi());
		vis.assign(n+1, 0);
		
		fr(i,m){
			scanf("%d %d", &x, &y);
			adjList[x].pb(y);
		}
		
		counter = 0;
		fr(i,l){
			sc(x);
			dfs(x);
		}
		
		printf("%d\n", counter);
	}
	
	return 0;
}
