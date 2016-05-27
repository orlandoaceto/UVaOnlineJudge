//11466 - Largest Prime Divisor
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

bool isP[32000001];

int main(){
	ll i, j, n, lim, last;
	int count;
	vector<ll> pri;
	
	memset(isP, 1, sizeof isP);
	
	for(i = 2; i <= 32000000; i++){
		if(isP[i]){
			pri.pb(i);
			for(j = i * i; j <= 32000000; j += i){
				isP[j] = 0;
			}
		}
	}
	
	
	while(scanf("%lld", &n) > 0){
		if(n==0)break;
		
		if(n < 0) n *= -1;
		
		lim = ceil(sqrt(n));
		count = 0;
		for(i = 0; pri[i] <= lim; i++){
			if(n % pri[i] == 0){
				while(n % pri[i] == 0){
					n /= pri[i];
				}
				last = pri[i];
				count++;
			}
		}
		if(count == 0 || (count == 1 && n == 1)){
			printf("-1\n");
		}
		else{
			if(n != 1) last = n;
			printf("%lld\n", last);
		}
	}
	
	return 0;
}
