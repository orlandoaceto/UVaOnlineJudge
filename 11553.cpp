//11553 - Grid Game
//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

#include <bits/stdc++.h>
using namespace std;

/*
Alice has no control on the outcome of the game. Since all she does is pick which row
the number is going to come from this turn. Ultimately, Bob chooses which number of that
row he is going to take while not being able to take 2 numbers from the same column.
All Bob needs to do is figure out what is the optimal way to get one number from each row
such that the sum is minimized. This can be done by trying all n! possible ways, since n is 8.
*/

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
	int t, k, n, i, j,res, mini;
	int m[8][8];
	vi perm;
	
	sc(t);
	
	fr1(k,t){
		clr(m);
		sc(n);
		fr(i,n){
			fr(j,n){
				sc(m[i][j]);
			}
		}
		perm.clear();
		fr(i,n){
			perm.pb(i);
		}
		mini = 1000000000;
		do{
			res = 0;
			fr(i,n){
				res += m[i][perm[i]];
			}
			mini = min(mini, res);
		}while(next_permutation(perm.begin(), perm.end()));
		
		printf("%d\n", mini);
	}
	return 0;
}
