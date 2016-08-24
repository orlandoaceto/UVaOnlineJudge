//12210 - A Match Making Problem
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

int main(){
	int n, m, k = 1, i;
	vi v;
	int aux;
	
	while(scanf("%d %d", &n, &m) > 0){
		if(n == 0 && m == 0) break;
		v.resize(n);
		int youngest = 300;
		fr(i,n){
			sc(v[i]);
			youngest = min(youngest, v[i]);
		}
		fr(i,m) sc(aux);
		if(n > m){
			printf("Case %d: %d %d\n", k++, n-m, youngest);
		}
		else{
			printf("Case %d: 0\n", k++);
		}
	}
	
	
	return 0;
}
