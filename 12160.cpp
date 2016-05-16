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

int main(){
	int l, u, r;
	vi but, dist;
	queue<int> q;
	int i, c = 1;
	
	while(1){
		scanf("%d %d %d", &l, &u, &r);
		if(l == 0 && r == 0 && u == 0) break;
		dist.assign(10000, -1);
		but.resize(r);
		dist[l] = 0;
		fr(i, r) scanf("%d", &but[i]);
		
		q.push(l);
		while(!q.empty()){
			int at = q.front();
			q.pop();
			if(at == u) break;
			fr(i,r) if(dist[(at+but[i])%10000] == -1){
				dist[(at+but[i])%10000] = dist[at]+1;
				q.push((at+but[i])%10000);
			}
		}
		
		while(!q.empty())q.pop();
		
		
		printf("Case %d: ", c++);
		if(dist[u] == -1) printf("Permanently Locked\n");
		else printf("%d\n", dist[u]);
		
	}
	
	return 0;
}
