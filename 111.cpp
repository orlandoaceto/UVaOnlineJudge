//111 - History Grading
//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

/*
The problem is simply to find length of LIS - Longest Increasing Sequence (classical dynamic program problem)
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
	int n;
	vi sv;//sv[i] stores smallest final value of all LIS of length i+1
	int aux, size, i, maxLen;
	int rank[21];//Stores the rank of each event
	int v[21];//Stores input
	
	sc(n);
	fr1(i,n){
		sc(aux);
		rank[i] = aux;
	}
	
	while(sc(aux) > 0){
		v[aux] = rank[1];
		sv.clear();
		for(i = 2; i <= n; i++){
			sc(aux);
			v[aux] = rank[i];
		}
		
		maxLen = 0;
		vi::iterator it;
		for(i = 1; i <= n; i++){
			it = lower_bound(sv.begin(), sv.end(), v[i]);
			if(it == sv.end()){
				sv.pb(v[i]);
				maxLen++;
			}
			else{
				*it = v[i];
			}
		}
	
		printf("%d\n", maxLen);
	}
	
	return 0;
}
