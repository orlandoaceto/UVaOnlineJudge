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

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

ll memo[101][101];
int n, k;

ll solve(int i, int lef){
	if(lef < 0) return 0LL;
	if(i == k && lef == 0)return 1LL;
	if(i == k && lef != 0) return 0LL;
	if(memo[i][lef] != -1)return memo[i][lef];
	
	ll ans = 0;
	for(int j = 0; j <= n; j++) ans = (ans + solve(i+1, lef-j)) % 1000000LL;
	
	return memo[i][lef] = ans;
}

int main(){
	ll res;
	int i, j;
	
	while(scanf("%d %d", &n, &k) > 0){
		if(!n && !k) break;
		fr(i,101)fr(j,101)memo[i][j] = -1LL;
		res = solve(0, n);
		printf("%lld\n", res);
	}
	return 0;
}
