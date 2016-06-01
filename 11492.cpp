//11492 - Babel
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

const int oo = 0x3f3f3f3f;

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

int main(){
	ios_base::sync_with_stdio(false);
	map<string, int> trans;
	int m, n, a, b, st, en, i;
	vector<vector<pair<string, int> > > adjList;
	string w1, w2, c, w;
	priority_queue<pair<int, ii> , vector<pair<int, ii> >, greater<pair<int,ii> > > p;
	int minCost[5001][27];
	
	while(cin>>m){
		if(m == 0) break;
		adjList.assign(5001, vector< pair<string, int> > ());
		memset(minCost, 0x3f, sizeof minCost);
		n = 0;
		trans.clear();
		cin>>w1;
		cin>>w2;
		if(!trans[w1]) trans[w1] = ++n;
		if(!trans[w2]) trans[w2] = ++n;
		st = trans[w1];
		en = trans[w2];
		
		fr(i,m){
			cin>>w1>>w2>>c;
			//cout<<w1+" "+w2+" "+c<<'\n';
			if(!trans[w1]) trans[w1] = ++n;
			if(!trans[w2]) trans[w2] = ++n;
			
			adjList[trans[w1]].pb(p(c, trans[w2]));
			adjList[trans[w2]].pb(p(c, trans[w1]));
		}
		
		minCost[st][26] = 0;
		
		p = priority_queue<pair<int, ii> , vector<pair<int, ii> >, greater<pair<int,ii> > >();
		p.push(p(0, ii(st, 26)));
		
		while(!p.empty()){
			ii vert = p.top().se;
			int cost = p.top().fi;
			p.pop();
			
			
			if(vert.fi == en) break;
			
			if(cost > minCost[vert.fi][vert.se]) continue;
			
			fr(i,adjList[vert.fi].size()){
				w = adjList[vert.fi][i].fi;
				if((int)w[0]-'a' == vert.se) continue;
				int next = adjList[vert.fi][i].se;
				
				if(minCost[next][w[0]-'a'] > cost + (int)w.size()){
					minCost[next][w[0]-'a'] = cost + (int)w.size();
					p.push(p(cost+(int)w.size(), ii(next, w[0]-'a')));
				}
			}
		}
		
		int mini = INT_MAX;
		fr(i,27){
			mini = min(minCost[en][i], mini); 
		}
		
		if(mini == oo) printf("impossivel\n");
		else printf("%d\n", mini);
		
	}
	return 0;
}
