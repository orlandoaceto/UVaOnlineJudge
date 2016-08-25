//
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

int main(){
	int st, ttl;
	int n, i, a, b, cnt;
	int k = 1;
	vii con;
	map<int, int> ind;
	vector<vi> adjList;
	queue<ii> q;
	bool vis[200];
	
	while(sc(n) > 0){
		if(n == 0) break;
		con.clear();
		ind.clear();
		cnt = 0;
		fr(i,n){
			scanf("%d %d", &a, &b);
			if(ind.find(a) == ind.end()) ind[a] = cnt++;
			if(ind.find(b) == ind.end()) ind[b] = cnt++;
			con.pb(ii(a,b));
		}
		adjList.assign(cnt+1, vi());
		
		fr(i,n){
			a = con[i].fi;
			b = con[i].se;
			adjList[ind[a]].pb(ind[b]);
			adjList[ind[b]].pb(ind[a]);
		}
		
		while(1){
			scanf("%d %d", &st, &ttl);
			if(st == 0 && ttl == 0) break;
			if(ind.find(st) == ind.end()){
				ind[st] = cnt;
			}
			q.push(ii(ind[st],ttl));
			memset(vis, 0, sizeof vis);
			vis[ind[st]] = 1;
			while(!q.empty()){
				a = q.front().fi;
				b = q.front().se;
				q.pop();
				
				if(b == 0) continue;
				
				fr(i,adjList[a].size()){
					int next = adjList[a][i];
					if(!vis[next]){
						vis[next] = 1;
						q.push(ii(next, b-1));
					}
				}
			}
			
			int ans = 0;
			fr(i,cnt){
				if(!vis[i]) ans++;
			}
			
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", k++, ans, st, ttl);
		}
		
	}
	
	return 0;
}
