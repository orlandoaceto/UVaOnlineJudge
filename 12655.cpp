//12655 - Trucks
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
#define clr(a, b) memset(a, b, sizeof a);

const int oo = 0x3f3f3f3f;

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

vector<vii> adjList;
vector<vii> auxList;
vi taken;
priority_queue<pair<ii, int> > pq;

int p[20001][21];
int l[20001];
int minEdge[20001][21];

void bfs(int n, int lev, int parent, int weight){
	l[n] = lev;
	p[n][0] = parent;
	minEdge[n][0] = weight;
	int i;
	fr(i,adjList[n].size()){
		if(adjList[n][i].fi != parent)
			bfs(adjList[n][i].fi, lev+1, n, adjList[n][i].se);
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

int query(int a, int b){
	int c = lca(a,b);
	int da = l[a]-l[c], db = l[b] - l[c], i;
	
	int mini = oo;
	fr(i,20){
		if((da>>i)&1){
			mini = min(mini, minEdge[a][i]);
			a = p[a][i];
		}
		if((db>>i)&1){
			mini = min(mini, minEdge[b][i]);
			b = p[b][i];
		}
	}
	
	return mini;
}

void process(int vtx){ 
  taken[vtx] = 1;
  for (int j = 0; j < (int)auxList[vtx].size(); j++){
	  	ii v = auxList[vtx][j];
	  	if(!taken[v.first]) pq.push(make_pair(ii(v.second, v.first), vtx));
	}
}


int main(){
	int n, m, s;
	int i, j, k;
	int u, v, w;
	
	
	
	while(scanf("%d %d %d", &n, &m, &s) > 0){
		auxList.assign(n+1, vii());
		adjList.assign(n+1, vii());
		
		fr(i,m){
			scanf("%d %d %d", &u, &v, &w);
			auxList[u].pb(ii(v,w));
			auxList[v].pb(ii(u,w));
		}
	
	
		taken.assign(n+1, 0);
		process(1);
		while (!pq.empty()){
			pair<ii, int> front = pq.top();
			pq.pop();
			u = front.fi.se, w = front.fi.fi, v = front.se;
	  		if (!taken[u]) adjList[u].pb(ii(v,w)), adjList[v].pb(ii(u, w)), process(u);
		}
		
		clr(p, 0);
		clr(minEdge, 0x3f);
		bfs(1,0,0,0);
		
		fr1(j,20){
			fr1(i,n){
				p[i][j] = p[p[i][j-1]][j-1];
				minEdge[i][j] = min(minEdge[i][j-1], minEdge[p[i][j-1]][j-1]);
			}
		}
		
		fr(i,s){
			scanf("%d %d", &u, &v);
			printf("%d\n", query(u, v));
		}
	}
	
	return 0;
}
