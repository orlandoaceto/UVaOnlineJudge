//12951 - Stock Market
//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(int a = 0; a < n; a++)
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

int memo[200000][2];
int val[200000];
int c, n;

int go(int pos, int has){
	if(pos == n) return 0;
	if(~memo[pos][has]) return memo[pos][has];
	if(has){
		return memo[pos][has] = max(val[pos] + go(pos+1, 0), go(pos+1, 1));
	}
	else{
		return memo[pos][has] = max(go(pos+1, 1) - val[pos] - c, go(pos+1, 0));
	}
}

int main(){
	while(scanf("%d %d", &n, &c) > 0){
		memset(memo, -1, sizeof memo);
		fr(i,n) sc(val[i]);
		printf("%d\n", go(0,0));
	}	
	
	return 0;
}
