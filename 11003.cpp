//11003 - Boxes
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
	int l[1001], w[1001];
	int cap[1001];
	int n, i, j, maxi, newCap;
	
	while(sc(n)){
		if(n == 0) break;
		fr(i,n){
			sc(w[i]);
			sc(l[i]);
		}
		clr(cap);
		cap[0] = 1000000000;
		maxi = 0;
		fr(i,n){
			for(j = maxi; j >= 0; j--){
				if(cap[j] >= w[i]){
					maxi = max(maxi, j+1);
					newCap = min(cap[j]-w[i], l[i]);
					cap[j+1] = max(cap[j+1], newCap);
				}
			}
		}
		printf("%d\n", maxi);
	}
	
	
	
	return 0;
}
