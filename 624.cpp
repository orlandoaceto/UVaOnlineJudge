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

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

int v[20];
int m, n, maxSum, maxSet, maxN;

void rec(int pos, int sum, int set){
	//printf("%d %d %d\n", pos, sum, set);
	if(pos == m && sum > maxSum && sum <= n){
		maxSet = set;
		maxSum = sum;
	}
	
	if(sum <= n && pos < m){
		rec(pos+1, sum+v[pos], set | (1<<pos));
		rec(pos+1, sum, set);
	}
}

int main(){
	int i;
	while(scanf("%d %d", &n, &m) > 0){
		fr(i,m) sc(v[i]);
		maxSum = 0;
		maxSet = 0;
		rec(0, 0, 0);
		
		fr(i,m) if(maxSet & 1<<i)printf("%d ", v[i]);
		printf("sum:%d\n", maxSum);
	}

	return 0;
}
