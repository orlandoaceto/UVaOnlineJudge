#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
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
	int n;
	int up, lo;
	int lim;
	
	while(1){
		sc(n);
		if(n == -1) break;
		
		lim = sqrt(n * 2);
		
		for(int k = sqrt(n*2); k > 0; k--){
			lo = n/k - (k-1)/2;
			up = lo + k - 1;
			if((lo + up) * k == n * 2) break;
		}
		
		printf("%d = %d + ... + %d\n", n, lo, up);
	}

	return 0;
}

