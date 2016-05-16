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

int main(){
	int n, aux, k;
	multiset<int> m;
	multiset<int>::iterator it;
	ll ans;
	int i, j;
	
	while(1){
		sc(n);
		if(n == 0) break;
		m.clear();
		ans = 0;
		fr(i,n){
			sc(k);
			fr(j,k){
				sc(aux);
				m.insert(aux);
			}
			it = m.end();
			it--;
			ans += *it - *m.begin();
			m.erase(m.begin());
			it = m.end();
			it--;
			m.erase(it);
		}
		printf("%lld\n", ans);
	}

	return 0;
}
