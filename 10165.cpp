//10165 - Stone Game
//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

/*
Classical Nim game problem. If bitwise xor of all numbers == 0, losing position,
else it's a winning position.
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

const int oo = 0x3f3f3f3f;

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

int main(){
	int n, i;
	int res, aux;
	
	while(scanf("%d", &n) > 0){
		if(n == 0) break;
		
		res = 0;
		fr(i,n){
			sc(aux);
			res = res xor aux;			
		}
		
		if(res == 0) printf("No\n");
		else printf("Yes\n");
		
	}
	
	return 0;
}
