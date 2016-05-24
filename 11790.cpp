//11790 - Murcia's Skyline
//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

/*
This problem can be easier with the easier to adapt O(n^2) version of
the classical Longest Increasing Subsequence DP solution. Starting from
the first building ondwards, the program checks among those that come before the
building being considered which one has the highest previously computed
sum and has a height smaller than the current one. Then it saves for this bulding's
sum this highest previous sum with the current building's width.
Later, the same is done with the order of the building inversed and the sum vector
reset.
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
	vii v;
	vi sum;
	int n, t, k, i, l, j, maxi;
	int len[2];
	
	sc(t);
	
	map<int,int>::iterator it;
	fr1(k,t){
		sc(n);
		v.resize(n);
		sum.resize(n);
		fr(i,n){
			sc(v[i].fi);
		}
		fr(i,n){
			sc(v[i].se);
			sum[i] = v[i].se;
		}
		
		len[0] = len[1] = 0;
		
		fr(l, 2){
			fr(i,n){
				maxi = 0;
				fr(j, i){
					if(v[i].fi > v[j].fi) maxi = max(maxi, sum[j]);
				}
				sum[i] += maxi;
			}
			fr(i,n){
				len[l] = max(len[l], sum[i]);
			}
			reverse(v.begin(), v.end());
			fr(i,n) sum[i] = v[i].se;
		}
		
		printf("Case %d. ", k);
		if(len[0] >= len[1]){
			printf("Increasing (%d). Decreasing (%d).\n", len[0], len[1]);
		}
		else{
			printf("Decreasing (%d). Increasing (%d).\n", len[1], len[0]);
		}
	}
	
	return 0;
}
