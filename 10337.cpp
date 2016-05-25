//10337 - Flight Planner
//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

/*
Problem is solvable with dynamic programming (here done iteratively
rather than the usual recursion).
*/

#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define fr1(a, n) for(a = 1; a <= n; a++)
#define frR(a, n) for (a = n; a >= 0; a--)
#define sc(a) scanf("%d", &a)
#define pr(a) printf("%d ", a)
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
	int t, i, j;
	ll mini;
	ll memo[10][1000];
	int x;
	
	sc(t);
	
	while(t--){
		sc(x);
		x /= 100;
		
		for(j = 9; j >= 0; j--){
			fr(i,x){
				scanf("%lld\n", &memo[j][i]);
				memo[j][i] *= -1;
			}
		}
		for(j = 9; j >= 2; j--){
			memo[j][x-1] = 1000000000;
		}
		memo[1][x-1] += 20;
		memo[0][x-1] += 30;
		
		
		for(i = x-2; i >= 0; i--){
			for(j = 9; j >= 0; j--){
				mini = memo[j][i+1] + 30;
				if(j < 9){
					mini = min(mini, memo[j+1][i+1]+60);
				}
				if(j > 0){
					mini = min(mini, memo[j-1][i+1]+20);
				}
				
				memo[j][i] += mini;
			}
		}
		printf("%lld\n\n", memo[0][0]);
	}
	return 0;
}
