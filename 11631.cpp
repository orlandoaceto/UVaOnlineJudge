#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define fr1(a, n) for(a = 1; a <= n; a++)
#define frR(a, n) for (a = n; a >= 0; a--)
#define sc(a) scanf("%d", &a)
#define pr(a) printf("%d\n", a)
#define fi first
#define se second

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

vector<vii> adjList;
vi taken;
priority_queue<ii> pq;

void process(int vtx){
	taken[vtx] = 1;
	int j;
	fr(j, (int)adjList[vtx].size()){
		ii v = adjList[vtx][j];
		if(!taken[v.first]) pq.push(ii(-v.second, -v.first));
	}
}


int main(){

	int m, n;
	int i, j;
	int v1, v2, c;
	int total;
	
	while(scanf("%d %d", &m, &n) > 0 && m > 0 && n > 0){
		adjList.resize(m);
		fr(i,m)adjList[i].clear();
		total = 0;
		fr(i,n){
			scanf("%d %d %d", &v1, &v2, &c);
			total += c;
			adjList[v1].push_back(ii(v2, c));
			adjList[v2].push_back(ii(v1, c));
		}
		c = 0;
		taken.assign(m, 0);
		process(0);
		
		while(!pq.empty()){
			ii front = pq.top();
			pq.pop();
			int u = - front.second, w = -front.first;
			if(!taken[u]) c += w, process(u);
		}
		
		printf("%d\n", total - c);
	}
	
	

	return 0;
}
