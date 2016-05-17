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

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

int main(){
	int n, a, b;
	int i, c;
	
	while(1){
		sc(n);
		if(n == 0)break;
		a = b = 0;
		i = 1;
		for(i = 1, c = 0; i != 1<<31; i = i << 1){
			if(n & i){
				c++;
				if(c % 2)a += n & i;
				else b += n & i;
			}
		}
		printf("%d %d\n", a, b);
	}

	return 0;
}
