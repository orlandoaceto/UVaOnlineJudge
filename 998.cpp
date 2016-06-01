//988 - Many Paths, One Destination
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
	ios_base::sync_with_stdio(false);
	int e, n, i, j, nex;
	int total;
	vi ways;
	bool first = 1;
	
	while(cin>>e){
		if(first) first = 0;
		else cout<<'\n';
		total = 0;
		ways.assign(e, 0);
		ways[0] = 1;
		fr(i,e){
			cin>>n;
			fr(j,n){
				cin>>nex;
				ways[nex] += ways[i];
			}
			if(n == 0){
				total += ways[i];
			}
		}
		
		cout<<total<<'\n';
		
	}
	return 0;
}
