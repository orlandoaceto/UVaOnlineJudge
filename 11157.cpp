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
	int t, n, d;
	int k, i, j;
	int v[102];	
	char tp[102];
	int dist, maxDist;
	
	sc(t);

	fr1(k,t){
		scanf("%d %d\n", &n, &d);
		
		tp[0] = 'B';
		v[0] = 0;
		fr1(i,n){
			scanf("%c-%d\n", &tp[i], &v[i]);
		}
		tp[i] = 'B';
		v[i] = d;
		n += 2;
		dist = 0;
		maxDist = 0;
		fr(i,n){
			//printf("%c %d %d %d\n", tp[i], i, v[i], n);
			if(tp[i] == 'B'){
				if(i+1 < n){
					maxDist = max(maxDist, v[i+1]-v[i]);
					if(tp[i+1] == 'S'){
						maxDist = max(maxDist, v[i+2]-v[i]);
					}
				}
			}
			if(tp[i] == 'S'){
				if(tp[i+1] == 'S'){
					maxDist = max(maxDist, v[i+2]-v[i]);
				}
				else{
					maxDist = max(maxDist, v[i+1]-v[i]);
				}
			}
		}
		
		printf("Case %d: %d\n", k, maxDist);
		
	}

	return 0;
}
