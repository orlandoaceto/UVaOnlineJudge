//10616 - Divisible Group Sums
//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

/*
This question can be solved using dynamic programming using memo[i][j][k]
i represents the index of the number being considered, j represent the
total sum mod d and k represent the number of elements included in the subset
being computed. When you reach k == d and j == 0 (so sum is divisible by n),
set that memory position memo[i][j][k] to 1. The solution for a general 
i, j, k is the sum of memo[i+1][j][k] (not picking the number being considered)
plus memo[i+1][(j+num[i])%d][k+1] (picking the number of index i). To find the solution,
for a query you should compute the solution for i == 0, j == 0 and k == 0

HINT: For this problem, doing simply sum % mod won't quite work as intended for negative numbers,
so try doing ((sum%d)+d)%d instead to correct that
*/

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


ll memo[201][20][11];
bool found[201][20][11];
ll num[201];
ll d, m;
ll n, q;

ll go(int i, int j, int k){
	if(found[i][j][k]) return memo[i][j][k];
	
	if(k == m){
		if(j == 0){
			found[i][j][k] = true;
			return memo[i][j][k] = 1LL;
		}
		else{
			found[i][j][k] = true;
			return memo[i][j][k] = 0LL;
		}
	}
	else if(i == n){
		found[i][j][k] = true;
		return memo[i][j][k] = 0LL;
	}
	ll qtd;
	
	qtd = go(i+1, (((j+num[i])%d)+d)%d, k+1);
	qtd += go(i+1, j, k);
	
	found[i][j][k] = 1;
	return memo[i][j][k] = qtd;
}

int main(){
	int i, j;
	int setNo = 1;
	while(1){
		scanf("%lld %lld", &n, &q);
		if(n == 0 && q == 0) break;
		clr(num);
		fr(i,n){
			scanf("%lld\n", &num[i]);
		}
		printf("SET %d:\n", setNo++);
		fr1(i, q){
			scanf("%lld %lld", &d, &m);
			clr(found);
			clr(memo);
			printf("QUERY %d: %lld\n", i, go(0, 0, 0));
		}
	}
	
	return 0;
}
