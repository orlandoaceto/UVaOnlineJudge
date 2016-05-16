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
	ll v[1000];
	ll sum;
	int count;
	int n, t, i, au;
	
	sc(t);
	
	while(t--){
		sc(n);
		fr(i,n){
			scanf("%lld", &v[i]);
		}
		count = 1;
		sum = v[0];
		for(i = 1;i < n-1; i++){
			if(sum + v[i] < v[i+1]){
				sum += v[i];
				count++;
			}
		}
		if(n > 1) count++;
		printf("%d\n", count);
	}
	return 0;
}
