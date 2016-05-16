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

ll fact(ll n){
	ll ans = 1;
	while(n > 1){
		ans *= n;
		n--;
	}
	return ans;
}

int main(){

	int m, j, i;
	string s;
	string s2;
	ll n, max, maxel;
	ll el;
	scanf("%d", &m);
	fr(j,m){
		cin>>s;
		el = (int)s.size();
		
		maxel = el;
		scanf("%lld", &n);
		max = fact(el);
		sort(s.begin(), s.end());
		s2.clear();
		fr(i,maxel){
			sort(s.begin(), s.end());
			max /= el;
			el--;
			s2.push_back(s[n/max]);
			s.erase(s.begin() + n/max);
			n = n % max;
		}
		
		cout<<s2<<'\n';
	}

	return 0;
}
