//10717 - Mint
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
#define clr(a, b) memset(a, b, sizeof a);

const int oo = 0x3f3f3f3f;

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int lcm(int a, int b){
	return (a * b) / gcd(a,b);
}

int main(){
	int n, t;
	int i, j, k, l;
	int lc, rem;
	int co[50];
	int tb[10];
	int low, up;
	int ans[10][2];
	
	while(scanf("%d %d", &n, &t) > 0){
		if(n == 0 && t == 0) break;
		
		clr(ans, -1);
		
		fr(i,n) sc(co[i]);
		fr(i,t) sc(tb[i]);
		
		for(i = 0; i < n; i++){
			for(j = i+1; j < n; j++){
				for(k = j+1; k < n; k++){
					for(l = k+1; l < n; l++){
						lc = lcm(co[i], lcm(co[j], lcm(co[k], co[l])));
						for(int i = 0; i < t; i++){
							rem = tb[i] % lc;
							low = up = tb[i];
							if(rem != 0){
								low = (tb[i]/lc) * lc;
								up = low + lc;
							}
							
							if(ans[i][0] == -1 || low > ans[i][0]){
								ans[i][0] = low;
							}
							if(ans[i][1] == -1 || up < ans[i][1]){
								ans[i][1] = up;
							}
						}
					}
				}
			}
		}
		
		fr(i,t){
			printf("%d %d\n", ans[i][0], ans[i][1]);
		}
	}
	
	return 0;
}
