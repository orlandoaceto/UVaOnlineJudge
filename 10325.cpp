//10325 - The Lottery
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

vector<ll> rem;
vector<ll> add;
ll v[15];
ll m, n;

void gen(ll num, int qtd, int pos){
	if(pos == m){
		if(qtd == 0) return;
		if(qtd % 2 == 0) add.pb(num);
		else rem.pb(num);
	}
	else{
		gen((num*v[pos])/__gcd(num, v[pos]), qtd+1, pos+1);
		gen(num, qtd, pos+1);
	}
}

int main(){
	int i, j;
	
	while(scanf("%lld %lld", &n, &m) > 0){
		add.clear();
		rem.clear();
		
		fr(i,m){
			scanf("%lld", &v[i]);
		}
		
		gen(1, 0, 0);
		ll ans = n;
		
		fr(i,add.size()){
			//printf("add %lld (%lld)\n", add[i], n /add[i]);
			ans += n / add[i];
		}
		fr(i,rem.size()){
			//printf("rem %lld (%lld)\n", rem[i], n/rem[i]);
			ans -= n / rem[i];
		}
		
		printf("%lld\n", ans);
	}
	
	return 0;
}
