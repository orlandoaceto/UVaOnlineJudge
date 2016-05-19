//10054 - The Necklace
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

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

vector<vector<pair<int,bool> > > adjList;
vi nEdge;
list<int> cyc;

void eulerTour(list<int>::iterator i, int u){
	for(int j = 0; j < (int)adjList[u].size();j++){
		ii v = adjList[u][j];
		if(v.se){
			adjList[u][j].se = 0;
			for(int k = 0; k < (int)adjList[v.fi].size(); k++){
				ii uu  = adjList[v.fi][k];
				if(uu.first == u && uu.se){
					adjList[v.fi][k].se = 0;
					break;
				}
			}
			eulerTour(cyc.insert(i,u), v.first);
		}
	}
}

int main(){
	int t, k, n;
	ii edge;
	int i, first;
	bool odd;
	
	sc(t);
	
	fr1(k,t){
		sc(n);
		adjList.assign(51, vector<pair<int,bool> >());
		nEdge.assign(51, 0);
		fr(i,n){
			scanf("%d %d", &edge.fi, &edge.se);
			adjList[edge.fi].pb(p(edge.se, 1));
			nEdge[edge.fi]++;
			adjList[edge.se].pb(p(edge.fi,1));
			nEdge[edge.se]++;
		}
		
		odd = 0;
		first = 0;
		fr1(i,50){
			if(nEdge[i] > 0) first = i;
			if(nEdge[i] % 2 != 0){
				odd = 1;
				break;
			}
		}
		
		printf("Case #%d\n", k);
		
		if(odd){
			printf("some beads may be lost\n");
		}
		else{
			cyc.clear();
			eulerTour(cyc.begin(), first);
			list<int>::iterator next;
			next = cyc.begin();
			next++;
			list<int>::iterator it;
			for(it = cyc.begin(); next != cyc.end();it++, next++){
				printf("%d %d\n", *it, *next);
			}
			printf("%d %d\n", *it, *cyc.begin());
		}		
		
		if(k < t) printf("\n");
		
	}
	
	return 0;
}

