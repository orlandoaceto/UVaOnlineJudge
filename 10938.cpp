//10938 - Flea circus
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

int p[5001][21];
int l[5001];
vector<vi> adjList;

void bfs(int n, int lev, int parent){
	l[n] = lev;
	p[n][0] = parent;
	int i;
	fr(i,adjList[n].size()){
		if(adjList[n][i] != parent)
			bfs(adjList[n][i], lev+1, n);
	}
}

int lca(int a, int b){
	if(l[a] > l[b]) swap(a,b);
	
	int i, d = l[b] - l[a];

	fr(i,20){
		if((d>>i)&1) b = p[b][i];
	}
	
	if(a == b) return a;
	
	for(int i = 20; i >= 0; i--){
		if(p[a][i] != p[b][i]){
			a = p[a][i];
			b = p[b][i];
		}
	}
	return p[a][0];
}

ii calc(int a, int b){
	if(l[a] > l[b]) swap(a,b);
	
	int c = lca(a,b);
	int d = l[a] - l[c], i;
	
	a = c;
	fr(i,20){
		if((d>>i)&1) b = p[b][i];
	}
	d = l[b] - l[a];
	
	ii ret;
	ret.se = d&1;
	
	d >>= 1;
	fr(i,20){
		if((d>>i)&1) b = p[b][i];
	}
	ret.fi = b;
	
	if(ret.se){
		ret.se = max(ret.fi, p[ret.fi][0]);
		ret.fi = min(ret.fi, p[ret.fi][0]);
	}
	
	return ret;
}

int main(){
	int n, m, i, j;
	int u, v, w;
	
	while(1){
		sc(n);
		if(n == 0) break;
		adjList.assign(n+1, vi());
		clr(p);
		fr(i,n-1){
			scanf("%d %d", &u, &v);
			adjList[u].pb(v);
			adjList[v].pb(u);
		}
		
		bfs(1,0,0);
		fr1(j,20){
			fr1(i,n){
				p[i][j] = p[p[i][j-1]][j-1];
			}
		}
		
		sc(m);
		
		fr(i,m){
			scanf("%d %d", &u, &v);
			ii ans = calc(u,v);
			
			if(!ans.se){
				printf("The fleas meet at %d.\n", ans.fi); 
			}
			else{
				printf("The fleas jump forever between %d and %d.\n", ans.fi, ans.se);
			}
		}
		
	}
	
	return 0;
}
