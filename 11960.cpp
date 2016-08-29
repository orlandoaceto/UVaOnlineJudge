//11960 - Divisor Game
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
	int i, j;
	int isP[1000];
	vi pri;
	memset(isP, 1, sizeof isP);
	
	for(i = 2; i < 1000; i++){
		if(isP[i]){
			pri.pb(i);
			for(j = i*i; j < 1000; j += i){
				isP[j] = 0;
			}
		}
	}

	int ans[1000000];
	int maxi = 0, numDivMax = 0, numDiv, x, exp;
	
	for(i = 1; i <= 1000000; i++){
		x = i;
		numDiv = 1;
		for(j = 0; j < pri.size() && pri[j]*pri[j] <= x; j++){
			if(x % pri[j] == 0){
				exp = 1;
				while(x % pri[j] == 0){
					exp++;
					x /= pri[j];
				}
				numDiv *= exp;
			}
		}
		if(x > 1) numDiv *= 2;

		if(numDiv >= numDivMax){
			maxi = i;
			numDivMax = numDiv;
		}
		ans[i] = maxi;
	}


	int k, t, n;
	
	sc(t);
	
	fr1(k,t){
		sc(n);
		printf("%d\n", ans[n]);
	}
	
	return 0;
}
