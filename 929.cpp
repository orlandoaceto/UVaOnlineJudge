//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish


#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
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

int main()
{
	priority_queue<pair<int, pair<int, int> >,vector<pair<int, pair<int,int> > >, greater<pair<int, pair<int, int> > > > p;
	int m, n, i, j, t;
	int maze[1010][1010];
	int cost[1010][1010];
	int dr[]={0,0,1,-1};
    	int dc[]={1,-1,0,0};
	pair<int, ii> a;
	pair<int, int> v;
	int custoAnterior;
	
	
	cin>>t;
	while(t--){
		cin>>n>>m;
		fr(i,n)fr(j,m)cost[i][j] = -1;
		fr(i,n)fr(j,m)cin>>maze[i][j];
		
		while(!p.empty())p.pop();
		
		cost[0][0] = maze[0][0];
		p.push(p(cost[0][0],p(0,0)));
		
		
		while(!p.empty()){
			a = p.top();
			p.pop();
			v = a.se;
			custoAnterior = a.fi;
			if(cost[v.fi][v.se] != -1 && custoAnterior > cost[v.fi][v.se])continue;
			
			int r, c;
			
			for(i = 0; i < 4; i++){
				r = v.fi+dr[i];
				c = v.se+dc[i];
			
				if(r>=0 && r<n && c>=0 && c<m && (cost[r][c] == -1 || custoAnterior +maze[r][c] < cost[r][c])){
					cost[r][c] = custoAnterior + maze[r][c];
					p.push(p(cost[r][c],p(r,c)));
				}
			}
			
		}
		
		
		
		
		cout<<cost[n-1][m-1]<<'\n';
	}
	
	return 0;
}
