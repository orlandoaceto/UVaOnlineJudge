//10801 - Lift Hopping
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
	int n, k, i, j, fl;
	char aux;
	int minCost[100];
	vector<pair<int, vi> > lift;
	vector<vi> list;
	priority_queue<ii, vii, greater<ii> > q;
	
	while(scanf("%d %d\n", &n, &k) > 0){
		memset(minCost, 0x3f, sizeof minCost);
		lift.assign(n, p(0, vi()));
		list.assign(100, vi());
		
		fr(i,n) sc(lift[i].fi);
		fr(i,n){
		}
		
		i = 0;
		while(i < n){
			scanf(" %d%c", &fl, &aux);
			list[fl].pb(i);
			lift[i].se.pb(fl);
			if(aux == '\n') i++;
		}
		
		minCost[0] = 0;
		
		q = priority_queue<ii, vii, greater<ii> > ();
		
		q.push(ii(-60,0));
		
		while(!q.empty()){
			int floor = q.top().se;
			int time = q.top().fi;
			q.pop();
			
			fr(i,list[floor].size()){
				int liftNum = list[floor][i];
				int speed = lift[liftNum].fi;
				fr(j,lift[liftNum].se.size()){
					int newFloor = lift[liftNum].se[j];
					
					if(minCost[newFloor] > time + 60 + abs(floor - newFloor) * speed){
						minCost[newFloor] = time + 60 + abs(floor - newFloor) * speed;
						q.push(ii(time + 60 + abs(floor-newFloor) * speed, newFloor));
					}
				}
			}
		}
		
		if(minCost[k] == oo){
			printf("IMPOSSIBLE\n");
		}
		else{
			if(minCost[k] == -60) printf("0\n");
			else printf("%d\n", minCost[k]);
		}
	}
	
	return 0;
}
