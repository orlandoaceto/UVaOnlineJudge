//12533 - Joining Couples
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

int vis[100001];
int par[100001];
int loop[100001];
int loopOrd[100001];
int hiParent[100001];
int level[100001];
int p[100001][21];
vi loopSize;
stack<int> st;
int step, loopNum;

void findLoop(int n){
	if(vis[n] == step){
		int count = 1;
		loop[n] = loopNum;
		loopOrd[n] = 0;
		while(st.top() != n){
			loop[st.top()] = loopNum;
			loopOrd[st.top()] = count++;
			st.pop();
		}
		loopSize.pb(count);
		loopNum++;
	}
	else if(!vis[n]){
		vis[n] = step;
		st.push(n);
		findLoop(par[n]);
	}
}

int findHiParent(int n){
	if(vis[n]) return hiParent[n];
	vis[n] = 1;
	if(loop[n] != -1){
		level[n] = 0;
		hiParent[n] = n;
		return n;
	}
	else{
		hiParent[n] = findHiParent(par[n]);
		level[n] = level[par[n]]+1;
		return hiParent[n];
	}
}

int minDistLoop(int u, int v){
	return min(abs(loopOrd[u] - loopOrd[v]), loopSize[loop[u]] - abs(loopOrd[u] - loopOrd[v]));
}

int lca(int a, int b){
	if(level[a] > level[b]) swap(a,b);
	
	int i, d = level[b] - level[a];

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

int main(){
	int n, i, j, q, u, v;
	
	while(scanf("%d", &n) > 0){
		
		fr1(i,n){
			sc(par[i]);
			p[i][0] = par[i];
		}
		
		clr(vis, 0);
		clr(loop, -1);
		loopSize.clear();
		step = loopNum = 0;
		fr1(i,n) if(!vis[i]){
			step++;
			st = stack<int>();
			findLoop(i);
		}
		
		clr(vis,0);
		fr1(i,n){
			if(!vis[i] && loop[i] == -1){
				hiParent[i] = findHiParent(i);
			}
		}
		
		fr1(j,20){
			fr1(i,n){
				p[i][j] = p[p[i][j-1]][j-1];
			}
		}
		
		sc(q);
		
		fr(i,q){
			scanf("%d %d", &u, &v);
			if(loop[u] != -1 && loop[v] != -1){
				if(loop[u] != loop[v]){
					printf("-1\n");
				}
				else{
					printf("%d\n", minDistLoop(u,v));
				}
			}
			else if(loop[u] == -1 && loop[v] == -1){
				if(loop[hiParent[u]] != loop[hiParent[v]]){
					printf("-1\n");
				}
				else if(hiParent[u] != hiParent[v]){
					printf("%d\n", level[u] + level[v] + minDistLoop(hiParent[u] , hiParent[v]));
				}
				else{
					int c = lca(u,v);
					printf("%d\n", level[u] + level[v] - 2*level[c]);
				}
			}
			else{
				if(loop[v] == -1) swap(u,v);
				if(loop[hiParent[u]] != loop[v]){
					printf("-1\n");
				}
				else{
					printf("%d\n", level[u] + minDistLoop(hiParent[u], v));
				}
			}
		}
		
	}
	
	return 0;
}
