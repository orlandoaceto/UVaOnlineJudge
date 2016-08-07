//1121 - Subsequence
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
	int n, s, curr, i, j, ans;
	int v[100000];
	
	while(scanf("%d %d", &n, &s) > 0){
		fr(i,n) sc(v[i]);
		i = 0; j = 0; curr = 0;
		ans = n+1;
		while(1){
			if(curr < s){
				if(j == n) break;
				curr += v[j];
				j++;
			}
			else{
				ans = min(ans, j-i);
				curr -= v[i];
				i++;
			}
		}
		if(ans == n+1) ans = 0;
		printf("%d\n", ans);
	}
	
	return 0;
}
