//12854 - Automated Checking Machine
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
	int i, j;
	int a[5], b[5];
	
	while(sc(a[0]) > 0){
		fr1(i,4) sc(a[i]);
		fr(i,5) sc(b[i]);
		
		bool ans = 1;
		fr(i,5){
			if(a[i] == b[i]){
				ans = 0;
				break;
			}
		}
		
		if(ans) printf("Y\n");
		else printf("N\n");
	}
	
	return 0;
}
