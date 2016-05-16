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

#define MAX_V 100
#define INF 1000000000

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

int res[MAX_V][MAX_V], mf, f, s, t; // global variables
vi p;
vector<vi> AdjList;

void augment(int v, int minEdge){
	if(v == s){
		f = minEdge;
		return;
	}
	else if(p[v] != -1){
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f; res[v][p[v]] += f;
	}
}


int main(){

	int n, c;
	int i, j;
	int v1, v2, w;
	int N = 0;
	
	while(sc(n) > 0){
		if(n == 0) return 0;
		AdjList.assign(n, vi());
		memset(res, 0, sizeof res);
		
		scanf("%d %d %d", &s, &t, &c);
		s--;
		t--;
		fr(i,c){
			scanf("%d %d %d", &v1, &v2, &w);
			if(res[v1-1][v2-1] == 0) AdjList[v1-1].push_back(v2-1);
			if(res[v2-1][v1-1] == 0) AdjList[v2-1].push_back(v1-1);
			res[v1-1][v2-1] += w;
			res[v2-1][v1-1] += w;
		}
		mf = 0;
		while(1){
			f = 0;
			bitset<MAX_V> vis; vis[s] = true;
			queue<int> q; q.push(s);
			p.assign(MAX_V, -1);
			while(!q.empty()){
				int u = q.front();
				q.pop();
				if(u == t) break;
				for(int j = 0; j < (int)AdjList[u].size(); j++){
					int v = AdjList[u][j];
					if(res[u][v] > 0 && !vis[v])
						vis[v] = true, q.push(v), p[v] = u;
				}
			}
			augment(t, INF);
			if(f == 0)break;
			mf += f;
		}
			
		printf("Network %d\n", ++N);
		printf("The bandwidth is %d.\n\n", mf);
		
	}

	return 0;
}
