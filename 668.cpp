//10602 - Editor Nottoobad
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
	bool used[1000];
	int n,m, i;
	vi ans;

	sc(m);

	while(m--){
		ans.clear();
		sc(n);
		for(i = 2; n >= i; i++){
			ans.pb(i);
			n -= i;
		} 
		
		while(n > 0){
			for(i = ans.size()-1; i >= 0 && n > 0; i--){
				ans[i]++;
				n--;
			}
		}
		
		fr(i,ans.size()){
			printf("%d", ans[i]);
			if(i < ans.size()-1) printf(" ");
			else printf("\n");
		}
		
		if(m > 0) printf("\n");
	}
	
	return 0;
}
