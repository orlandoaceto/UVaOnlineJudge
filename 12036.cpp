//12036 - Stable Grid
//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

/*
This problem can be solved using simply the pigeon hole principle.
If, for any given number, its frequency is more than the number of
columns, it's clear that it's impossible to assign each one to a 
different collumn
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

int main(){
	int t, k, aux, n, i, j;
	bool ans;
	int freq[101];
	
	sc(t);
	
	fr1(k,t){
		sc(n);
		
		clr(freq);
		fr(i,n){
			fr(j,n){
				sc(aux);
				freq[aux]++;
			}
		}
		
		ans = 1;
		fr(i, 101){
			if(freq[i] > n){
				ans = 0;
				break;
			}
		}
		
		printf("Case %d: ", k);
		if(ans) printf("yes\n");
		else printf("no\n");
	}
	
	return 0;
}
