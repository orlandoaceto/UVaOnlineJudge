//11101 - Mall Mania
//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

/*
This problem is solved with BFS with a slight adaptation. Instead of having just
one source, multiple source vertexes are added with cost 0 to the queue inittially.
The BFS ends when any element from the list of vertexes belonging to the second
mall are taken from the queue.
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
#define setInf(a) memset(a, 0x3f, a);

const int oo = 0x3f3f3f3f;
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, -1, 1};

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;


int main(){
	queue<pair<ii, int> > q;
	ii p, nex;
	bool vis[2001][2001];
	set<ii> f;
	int n, i, cost;
	
	while(scanf("%d", &n) > 0){
		if (n == 0) break;
		f.clear();
		clr(vis);
		
		q = queue<pair<ii, int> >();
		
		fr(i,n){
			scanf("%d %d", &p.fi, &p.se);
			q.push(p(p, 0));
			vis[p.fi][p.se] = 1;
		}
		
		scanf("%d", &n);
		
		fr(i,n){
			scanf("%d %d", &p.fi, &p.se);
			f.insert(p);
		}
		
		while(1){
			ii v = q.front().fi;
			cost = q.front().se;
			q.pop();
			
			if(f.find(v) != f.end()) break;
			
			fr(i,4){
				nex.fi = v.fi+dr[i];
				nex.se = v.se+dc[i];
				if(nex.fi >= 0 && nex.fi <= 2000 && nex.se >= 0 && nex.se <= 2000 && !vis[nex.fi][nex.se]){
					q.push(p(nex, cost+1));
					vis[nex.fi][nex.se] = 1;
				}
			}
			
		}
		
		printf("%d\n", cost);
	}
	
	return 0;
}
