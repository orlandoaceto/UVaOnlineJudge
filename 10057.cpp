//10057 - A mid-summer night's dream.
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
	vi v;
	int n, i;
	
	while(sc(n) > 0){
		v.resize(n);
		fr(i,n) sc(v[i]);
		sort(v.begin(), v.end()	);
		printf("%d %d %d\n", v[(n-1)/2], (int)(upper_bound(v.begin(), v.end(), v[n/2]) - lower_bound(v.begin(), v.end(), v[(n-1)/2])), v[n/2]-v[(n-1)/2]+1);
	}
	
	
	return 0;
}
