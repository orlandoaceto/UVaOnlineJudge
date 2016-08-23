//12324 - Philip J. Fry Problem
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

int n;
int sp[1000];
int dur[1000];
int memo[1000][1000];

int go(int trip, int spheres){
	if(trip == n) return 0;
	if(~memo[trip][spheres]) return memo[trip][spheres];
	
	int ans = dur[trip] + go(trip+1, spheres + sp[trip]);
	if(spheres > 0){
		ans = min(ans, dur[trip]/2 + go(trip+1, spheres-1+sp[trip]));
	}
	
	return memo[trip][spheres] = ans;
}

int main(){
	int i;
	
	while(scanf("%d", &n) > 0){
		if(!n) break;
		
		fr(i,n){
			scanf("%d %d", &dur[i], &sp[i]);
		}
		memset(memo, -1, sizeof memo);
		printf("%d\n", go(0, 0));
		
	}
	
	return 0;
}
