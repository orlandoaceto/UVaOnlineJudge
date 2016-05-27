//11889 - Benefit
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

bool isP[1000010];

int main(){
	int i, j, lim, a, c, t;
	int expA, expC;
	ll b;
	vi pri;
	
	memset(isP, 1, sizeof isP);
	
	for(ll i = 2; i <= 1000000; i++){
		if(isP[i]){
			pri.pb(i);
			for(ll j = i * i; j <= 1000000; j += i){
				isP[j] = 0;
			}
		}
	}
	
	
	sc(t);
	
	while(t--){
		scanf("%d %d", &a, &c);
		b = 1;
		lim = ceil(sqrt(a));
		bool sol = 1;
		if(c % a != 0) sol = 0;
		
		if(sol == 1){
			i = 0;
			int tmp = c;
			while(pri[i] * pri[i] <= tmp){
				
				expA = 0;
				expC = 0;
				while(a % pri[i] == 0){
					a /= pri[i];
					expA++;
				}
				while(c % pri[i] == 0){
					c /= pri[i];
					expC++;
				}
				if(expA < expC){
					while(expC--){
						b *= pri[i];
					}
				}
				
				i++;
			}
						
			if(a == 1 && c > 1){
				b *= c;
			}
		
			printf("%lld\n", b);
			
		}
		else{
			printf("NO SOLUTION\n");		
		}
	}
	
	return 0;	
}
	
