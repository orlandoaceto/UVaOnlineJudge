//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish


#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 1; a <= n; a++)
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

int main(){
	int v[2000010];
	int n, i;
	int f[101];
	
	while(scanf("%d", &n) > 0 && n > 0){
		memset(v, 0, sizeof f);
		
		fr(i,n)sc(v[i]);
		
		fr(i,n)f[v[i]]++;
		
		fr(i,100)if(f[i]){
			printf("%d", i);
			f[i]--;
			break;
		}

		fr(i,100)while(f[i]){
			printf(" %d", i);
			f[i]--;
		}
		printf("\n");
	}
	return 0;
}
