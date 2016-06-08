//11311 - Exclusively Edible
//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

/*The distances from the bad piece to each of the 4 borders can be viewed as
nim heap. So to solve this problem all that needs to be done is to check the
bitwise xor of each of these distances (read about Sprague-Grundy theorem if 
you're confused)
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

const int oo = 0x3f3f3f3f;

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

int main(){
	int t;
	int m, n, r, c, ans;
	
	sc(t);
	
	while(t--){
		scanf("%d %d %d %d", &m, &n, &r, &c);
		m = m-r-1;//Just reutilizing m and n variables
		n = n-c-1;
		ans = m ^ n ^ r ^ c;
		if(ans){
			printf("Gretel\n");
		}
		else{
			printf("Hansel\n");
		}
	}
	
	return 0;
}
