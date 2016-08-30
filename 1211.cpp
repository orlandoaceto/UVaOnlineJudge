//1211 - Atomic Car Race
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
	int n, r, i, j;
	double b, v, e, f;
	double cost[10001];
	double memo[101];
	int cpos[101];
	while(sc(n) > 0){
		if(n == 0) break;
		cpos[0] = 0;
		fr1(i,n){
			sc(cpos[i]);
		}
		scanf("%lf", &b);
		scanf("%d %lf %lf %lf", &r, &v, &e, &f);
		
		cost[0] = 0;
		for(i = 0; i < r; i++){
			cost[i+1] = cost[i] + 1.0/(v-f*(r-i));
		}
		for(i = r; i < cpos[n]; i++){
			cost[i+1] = cost[i] + 1.0/(v-e*(i-r));
		}
		
		memo[n] = 0;
		for(i = n-1; i > 0; i--){
			memo[i] = 1e100;
			for(j = i+1; j <= n; j++){
				memo[i] = min(memo[i], b + cost[cpos[j] - cpos[i]] + memo[j]);
			}
		}
		double ans = 1e100;
		for(j = 1; j <= n; j++){
			ans = min(ans, cost[cpos[j]] + memo[j]);
		}
		
		printf("%.4lf\n", ans);
	}

	return 0;
}
