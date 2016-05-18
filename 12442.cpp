//UVa 12442 - Forwarding Emails
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

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

int edg[50000];
bool vis[50000];
bool inc[50000];

int dfs(int v){
	int ans = 1;
	vis[v] = 1;
	if(vis[edg[v]] == 0){
		ans += dfs(edg[v]);
	}
	vis[v] = 0;
	inc[v] = 1;
	return ans;
}


int main(){
	int t, k, n, i;
	int u, v, ans, mart, maxi;
	
	sc(t);
	fr1(k,t){
		sc(n);
		fr(i,n){
			scanf("%d %d", &u, &v);
			edg[u-1] = v-1;
		}
		memset(vis, 0, sizeof vis);
		memset(inc, 0, sizeof inc);
		maxi = 0;
		fr(i,n){
			if(!inc[i])
				ans = dfs(i);
			else
				ans = 0;
			if(ans > maxi){
				maxi = ans;
				mart = i+1;
			}
				
		}
		printf("Case %d: %d\n", k, mart);
	}

	return 0;
}
