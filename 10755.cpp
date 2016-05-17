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
	ll h[20][20][20];
	ll a, b, c, i, j, k, l, m;
	ll t, maxi;
	ll sum;
	
	scanf("%lld", &t);
	
	while(t--){
		maxi = 0;
		scanf("%lld %lld %lld", &a, &b, &c);
		fr(i,a)fr(j,b)fr(k,c){
			scanf("%lld", &h[i][j][k]);
			maxi += h[i][j][k];
		}
		
		for(k = 0; k < c; k++){
			for(i = 0; i < a; i++){
				for(j = 0; j < b; j++){
					if(i > 0)
					h[i][j][k] += h[i-1][j][k];
					if(j > 0)
					h[i][j][k] += h[i][j-1][k];
					if(i > 0 && j > 0)
					h[i][j][k] -= h[i-1][j-1][k];
				}
			}
		}
		
		fr(i,a)fr(j,b){
			for(l = i; l < a; l++){
				for(m = j; m < b; m++){
					sum = 0;
					fr(k,c){
						sum += h[l][m][k];
						if(i > 0) sum -= h[i-1][m][k];
						if(j > 0) sum -= h[l][j-1][k];
						if(i > 0 && j > 0) sum += h[i-1][j-1][k];
						maxi = max(sum, maxi);
						if(sum < 0) sum = 0;
					}
				}
			}
		}
		
		printf("%lld\n", maxi);
		if(t != 0)printf("\n");
	}

	return 0;
}
