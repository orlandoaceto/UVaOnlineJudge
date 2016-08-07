//10539 - Almost Prime Numbers
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
	bool isP[1000001];
	int n;
	ll lo, hi;
	vector<ll> almprimes;
	
	memset(isP, true, sizeof isP);
	for(ll i = 2; i <= 1000000; i++){
		if(isP[i]){
			for(ll j = i*i; j <= 1000000000000LL; j *= i){
				almprimes.pb(j);
			}
			for(ll j = i*i; j <= 1000000; j += i){
				isP[j] = 0;
			}
		}
	}
	
	sort(almprimes.begin(), almprimes.end());
	
	sc(n);
	while(n--){
		scanf("%lld %lld", &lo, &hi);
		printf("%d\n", (int)(upper_bound(almprimes.begin(), almprimes.end(), hi) - lower_bound(almprimes.begin(), almprimes.end(), lo)));
	}
	
	return 0;
}
