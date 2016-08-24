//983 - Localized Summing for Blurring
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

const int oo = 0x3f3f3f3f;

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

int acc[1000][1000];

int sub(int i, int j){
	if(i >= 0 && j >= 0) return acc[i][j];
	return 0;
}

int main(){
	int ans[1000][1000];
	int n, m, i, j;
	bool first = 1;
	
	while(scanf("%d %d", &n, &m) > 0){
	
		if(first) first = 0;
		else printf("\n");
	
		fr(i,n)fr(j,n){
			sc(acc[i][j]);
			acc[i][j] = acc[i][j] + sub(i, j-1)+ sub(i-1, j) - sub(i-1, j-1);
		}
		int total = 0;
		for(i = m-1; i < n; i++){
			for(j = m-1; j < n; j++){
				total += ans[i-(m-1)][j-(m-1)] = sub(i,j) - sub(i-m, j) - sub(i, j-m) + sub(i-m, j-m);
				printf("%d\n", ans[i-(m-1)][j-(m-1)]);
			}
		}
		printf("%d\n", total);
		
	}
	
	return 0;
}
