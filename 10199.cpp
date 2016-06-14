//10199 - Tourist Guide
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
	int n, m, i;
	string name;
	string a, b;
	char r;
	map<string, int> ma;
	int ind1, ind2;
	vector<string> names;
	vector<string> toPrint;
	int cas = 1;
	bool first = 1;
	
	while(scanf("%d", &n) > 0){
		if(n == 0) break;
		if(first) first = 0;
		else printf("\n");
		
		adjList.assign(n, vi());
		ma.clear();
		names.clear();
		fr(i,n){
			cin>>name;
			ma[name] = i;
			names.pb(name);
		}
		
		scanf("%d", &m);
		
		fr(i,m){
			cin>>a>>b;
			ind1 = ma[a];
			ind2 = ma[b];
			adjList[ind1].pb(ind2);
			adjList[ind2].pb(ind1);
		}
		
		dfsNumberCounter = 0;
		dfs_num.assign(n, -1);
		dfs_low.assign(n, 0);
		dfs_parent.assign(n, 0);
		articulation_vertex.assign(n,0);
		dfsNumberCounter = 0;
		
		fr(i,n){
			if(dfs_num[i] == -1){
				dfsRoot = i;
				rootChildren = 0;	
				dfs(i);
				articulation_vertex[i] = (rootChildren > 1);
			}
		}
		int cont = 0;
		toPrint.clear();
		fr(i,n){
			if(articulation_vertex[i]){
				cont++;
				toPrint.pb(names[i]);
			}
		}
		
		
		printf("City map #%d: %d camera(s) found\n", cas++, cont);
		sort(toPrint.begin(), toPrint.end());
		
		fr(i, (int)toPrint.size()){
			cout<<toPrint[i]<<'\n';
		}
		
	}
	return 0;
}
