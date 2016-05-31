//1112 - Mice and Maze
//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

/*
By reversing every edge and running dijkstra starting from the exit cell, it's possible to find
the shortest distance from every cell to the exit cell. For every cell, if the shortest distance
is <= the maximum allowed, then add one more to the answer. After checking every cell, output result.
*/

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
	int t, i, n, a, b, c, e, lim, m;
	vector<vii> adjList;
	int minCost[101];
	priority_queue<ii, vii, greater<ii> > q;
	
	sc(t);
	while(t--){
		memset(minCost, 0x3f, sizeof minCost);
		scanf("%d %d %d %d", &n, &e, &lim, &m);
		adjList.assign(n+1, vii());
		fr(i,m){
			scanf("%d %d %d", &a, &b, &c);
			adjList[b].pb(ii(c, a));
		}
		
		q = priority_queue<ii, vii, greater<ii> > ();
		q.push(ii(0,e));
		minCost[e] = 0;
		
		while(!q.empty()){
			int v = q.top().se;
			int cost = q.top().fi;
			q.pop();
			
			if(cost > lim) break;
			
			fr(i,adjList[v].size()){
				if(cost + adjList[v][i].fi < minCost[adjList[v][i].se]){
					minCost[adjList[v][i].se] = cost + adjList[v][i].fi;
					q.push(ii(cost+adjList[v][i].fi, adjList[v][i].se));
				}
			}
		}
		
		int cont = 0;
		fr1(i,n){
			if(minCost[i] <= lim) cont++;
		}
		
		printf("%d\n", cont);
		if(t > 0) printf("\n");
		
	}
	
	return 0;
}
