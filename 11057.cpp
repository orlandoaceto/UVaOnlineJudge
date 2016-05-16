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
	int n, m, i;
	int sol;
	int v[10000];
	while(sc(n) > 0){
		fr(i,n){
			sc(v[i]);
		}
		sort(v,v+n);
		sc(m);
		sol = -1;
		fr(i,n-1){
			if(binary_search(v+i+1, v+n, m - v[i])){
				if(sol == -1 || abs(2*sol - m) > abs(2*v[i] - m)) sol = v[i];
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n", sol, m-sol);
	}
	return 0;
}
