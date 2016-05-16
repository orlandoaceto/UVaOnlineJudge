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

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

int main(){
	int t;
	int v, e, i;
	int v1, v2, c1, c2, pin;
	vii distr;
	queue<int> q;
	vi color;
	vector<vi> AdjList;
	
	
	sc(t);
	
	while(t--){
		scanf("%d %d", &v, &e);
		color.assign(v, 2);
		AdjList.assign(v, vi());
		
		fr(i, e){
			scanf("%d %d", &v1, &v2);
			AdjList[v1].pb(v2);
			AdjList[v2].pb(v1);
		}
		distr.clear();
		pin = 0;
		bool possible = 1;
		
		
		while(!q.empty()) q.pop();
		
		while(pin < v && possible){
			c1 = 0;
			c2 = 0;
			for(i = 0; color[i] != 2; i++);
			color[i] = 0;
			c1 = 1;
			pin++;
			q.push(i);
			while(!q.empty() && possible){
				int u = q.front(); q.pop();
				fr(i,AdjList[u].size()){
					int v = AdjList[u][i];
					if(color[v] == 2){
						if(color[u] == 1){
							color[v] = 0;
							q.push(v);
							c1++;
							pin++;
						}
						else if(color[u] == 0){
							color[v] = 1;
							q.push(v);
							c2++;
							pin++;
						}
					}
					else if(color[v] == color[u]){
						possible = 0;
						break;
					}
				}
			}
			distr.pb(ii(c1,c2));
		}
		
		if(possible){
			int mini = 0;
			fr(i,distr.size()){
				if(min(distr[i].fi, distr[i].se) > 0){
					mini += min(distr[i].fi, distr[i].se);
				}
				else{
					mini += max(distr[i].fi, distr[i].se);
				}
			}
			printf("%d\n", mini);
		}
		else printf("-1\n");
		
	}

	return 0;
}
