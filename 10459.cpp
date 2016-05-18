//UVa 10459 - The Tree Root
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

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

vector<vi> adjList;
vi dist;
int maxi;
set<int> worst;
set<int> best;

void calc(int a){
	int i;
	if(dist[a] > maxi){
		maxi = dist[a];
	}
	fr(i, adjList[a].size()){
		if(dist[adjList[a][i]] == -1){
			dist[adjList[a][i]] = dist[a] + 1;
			calc(adjList[a][i]);
		}
	}
}

bool path(int a, int b){
	int i;
	bool f = 0;
	dist[a] = 0;
	if(a == b){
		f = 1;
		dist[a] = 0;
	}
	else{
		fr(i,adjList[a].size()){
			if(dist[adjList[a][i]] == -1){
				f = path(adjList[a][i], b);
				if(f == 1) break;
			}
		}
		if(f == 1){
			dist[a] = 1 + dist[adjList[a][i]];
			if(dist[a] == maxi/2 || (maxi % 2 == 1 && dist[a] == maxi/2 + 1)){
				best.insert(a);
			}
		}
	}
	
	return f;
}

int main(){
	int n, i, q, j, v;
	int worstVertex1, worstVertex2;
	
	while(scanf("%d", &n) > 0){
		adjList.assign(n+1, vi());
		fr1(i,n){
			scanf("%d", &q);
			fr(j,q){
				scanf("%d", &v);
				adjList[i].pb(v);
			}
		}
		worst.clear();
		best.clear();
		
		dist.assign(n+1, -1);
		dist[1] = 0;
		maxi = 0;
		calc(1); //Furthest distance from any node (finds one or more nodes belonging to set of worst roots)
		fr1(i,n){
			if(dist[i] == maxi) worst.insert(i);
		}
		maxi = 0;
		dist.assign(n+1, -1);
		worstVertex1 = *worst.begin(); //Keeps track of the vertex used as reference for finding longest path
		dist[*worst.begin()] = 0;
		calc(*worst.begin());//Furthest distance from one of the worst roots(finds the rest of the worst roots)
		
		fr1(i,n){
			if(dist[i] == maxi){
				worst.insert(i);
				worstVertex2 = i;
			}
		}
		
		dist.assign(n+1, -1);
		dist[worstVertex1] = 0;
		path(worstVertex1, worstVertex2);//Adds to set<int> best the nodes in the middle of the path from wv1 to wv2
		
		printf("Best Roots  :"); 
		for(int pr: best) printf(" %d", pr);
		printf("\n");
		printf("Worst Roots :");
		for(int pr: worst) printf(" %d", pr);
		printf("\n");
	}
}
