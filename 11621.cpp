//11621 - Small Factors
//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

/*
This problem can be solved by adding all possible answer to a vector
Possible answers are of the form 2^i * 3^j and, on this problem,
can only be equal or smaller to 2^31. Using binary search, the first possible
answer equal to or larger than m can be quickly found.
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

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

int main(){
	ll power2, el, lim;
	vector<ll> v;
	int i, j;
	
	power2 = 1;
	lim = (ll)1<<32;
	
	for(i = 0; i < 32; i++){
		el = power2;
		while(el <= lim){
			v.pb(el);
			el *= 3;
		}
		power2 <<= 1;
	}
	
	sort(v.begin(), v.end());
	
	ll m;
	
	while(scanf("%lld", &m) > 0){
		if(m == 0) break;
		printf("%lld\n", *lower_bound(v.begin(), v.end(), m));
	}
	
	return 0;
}
