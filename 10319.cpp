//10319 - Manhattan
//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

//2-sat problem, solved with implication graph and then finding SCC

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
vi sccNum;

vi dfs_num, dfs_low, S, visited;
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
		while(1){
			int v = S.back(); S.pop_back(); visited[v] = 0;
			sccNum[v] = numSCC;
			if(u == v) break;
		}
		numSCC++;
	}
}


inline int streetNum(int s){
	return 2 * (	s-1);
}
inline int avenueNum(int n, int a){
	return 2* n + 2*(a-1);
}

int main(){
	int n, m, r, t, i;
	int s1, a1, s2, a2;
	
	sc(t);
	
	while(t--){
		scanf("%d %d %d", &n, &m, &r);
		adjList.assign(2*n + 2*m, vi()); //2 for each avenue and street (variable and its negation)
		fr(i,r){
			scanf("%d %d %d %d", &s1, &a1, &s2, &a2);
			s1 = streetNum(s1);
			s2 = streetNum(s2);
			a1 = avenueNum(n, a1);
			a2 = avenueNum(n, a2);
			
			if(s2 < s1){
				a1++;
				a2++;
			}
			if(a2 < a1){
				s1++;
				s2++;
			}
			
			if(s1 != s2 && a1 != a2){
				adjList[s1^1].pb(a1);
				adjList[a1^1].pb(s1);
				adjList[s1^1].pb(s2);
				adjList[s2^1].pb(s1);
				adjList[a2^1].pb(a1);
				adjList[a1^1].pb(a2);
				adjList[a2^1].pb(s2);
				adjList[s2^1].pb(a2);
			}
			else if(s1 == s2){
				adjList[s1^1].pb(a1);
				adjList[a1^1].pb(s1);
				adjList[s1^1].pb(a1^1);
				adjList[a1].pb(s1);
			}
			else if(a1 == a2){
				adjList[a1^1].pb(s1);
				adjList[a1^1].pb(s1^1);
				adjList[s1].pb(a1);
				adjList[s1^1].pb(a1);
			}
			
		}
		bool ans = 1;
		sccNum.assign(2*n+2*m, 0);
		dfs_num.assign(2*n+2*m, -1);
		dfs_low.assign(2*n+2*m, 0);
		visited.assign(2*n+2*m, 0);
		dfsNumCount = numSCC = 0;
		fr(i,2*(n+m)) if(dfs_num[i] == -1) tarjanSCC(i);
		for(i = 0; i < 2*(n+m); i+= 2){
			if(sccNum[i] == sccNum[i+1]){
				ans = 0;
				break;
			}
		}
		
		if(ans) printf("Yes\n");
		else printf("No\n");
		
	}
	
	return 0;
}
