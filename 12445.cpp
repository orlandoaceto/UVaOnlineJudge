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
	int t;
	int n, p, i, j, sum;
	int v[20];
	
	sc(t);
	while(t--){
		scanf("%d %d", &n, &p);
		fr(i,p) sc(v[i]);
		for(i = 0;i < 1<<p;i++){
			sum = 0;
			fr(j,p){
				if(i & 1<<j) sum += v[j];
			}
			if(sum == n) break;
		}
		if(sum == n) printf("YES\n");
		else printf("NO\n");
		
	}

	return 0;
}
