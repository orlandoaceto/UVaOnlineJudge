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

int main(){

	unsigned int n, l, u;
	unsigned int m, bit;
	int i;
	
	while(scanf("%u %u %u", &n, &l, &u) > 0){
		m = 0;
		for(i = 31; i >= 0; i--){
			bit = 1<<i;
			if((n & bit) == 0 && (m | bit) <= u){
				m |= bit;
			}
			else if(m < l && (n & bit) != 0 && (m | (bit-1) ) < l){
				m |= bit;
			}
		}
		
		printf("%u\n", m);
	}
}
