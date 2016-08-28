//12986 - The Battle of Guandu
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

const long long int oo = 0x3f3f3f3f3f3f3f3f;

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

int main(){
	int t, k;
	int n, m, i, j;
	ll a, b, c;
	vector<vii> adjList;
	vi typ;
	ll dist[100000];
	vii vil;
	priority_queue<pair<ll,ll>, vector<pair<ll,ll> >, greater<pair<ll,ll> > > pq;
	
	sc(t);
	
	fr1(k,t){
		scanf("%d %d", &n, &m);
		adjList.assign(m+1, vii());
		typ.resize(m+1);
		vil.resize(n);
		
		fr(i,n) sc(vil[i].se);
		fr(i,n) sc(vil[i].fi);
		fr(i,n){
			int c;
			sc(c);
			adjList[vil[i].fi].pb(ii(vil[i].se, c));
		}
		
		memset(dist, 0x3f, sizeof dist);
		
		fr1(i,m){
			sc(typ[i]);
			if(typ[i] == 0){
				pq.push(pair<ll,ll>(0, i));
				dist[i] = 0;
			}
		}
		
		while(!pq.empty()){
			a = pq.top().se;
			c = pq.top().fi;
			pq.pop();
			if(dist[a] < c) continue;
			
			fr(i,adjList[a].size()){
				b = adjList[a][i].fi;
				if(dist[b] > c + adjList[a][i].se){
					dist[b] = c + adjList[a][i].se;
					pq.push(pair<ll,ll>(dist[b], b));
				}
			}
		}
		
		ll ans = 0;
		fr1(i,m){
			if(typ[i] == 2){
				if(dist[i] < oo){
					ans += dist[i];
				}
				else{
					ans = -1;
					break;
				}
			}
		}
		printf("Case #%d: %lld\n", k, ans);
		
	}
	
	return 0;
}

















