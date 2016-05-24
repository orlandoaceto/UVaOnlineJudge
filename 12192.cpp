//12192 - Grapevine
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

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

int main(){
	int n, m, i, j, k, q, l, u, indLow;
	vector<vi> prop;
	vi::iterator it;
	
	while(1){
		scanf("%d %d", &n, &m);
		if(n == 0 && m == 0) break;
		prop.assign(n, vi(m, 0));
		fr(i,n){
			fr(j,m){
				scanf("%d", &prop[i][j]);
			}
		}
		scanf("%d", &q);
		fr(k,q){
			scanf("%d %d", &l, &u);
			j = 0;
			for(i = 0; i < n; i++){
				it = lower_bound(prop[i].begin(), prop[i].end(), l);
				indLow = it - prop[i].begin();
				while(1){
					if(i+j >= n  || indLow + j >= m || prop[i+j][indLow+j] > u) break;
					else j++;
				}
			}
			printf("%d\n", j);
		}
		printf("-\n");
	}
	
	return 0;
}
