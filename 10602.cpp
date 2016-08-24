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
	int t, n, cost;
	int i, j, k;
	string dele;
	string::iterator it;
	vector<string> v, ans;
	vi deleted;
	sc(t);
	
	while(t--){
		sc(n);
		v.resize(n);
		deleted.assign(n, 0);
		ans.clear();
		
		fr(i,n){
			cin>>v[i];
		}
		
		dele = v[0];
		cost = v[0].size();
		while(1){
			fr(i,n){
				if(deleted[i] < v[i].size()){
					j = 0, k = 0;
					while(j < dele.size() && k < v[i].size() && dele[j] == v[i][k]){
						j++;
						k++;
					}
					deleted[i] = max(deleted[i], k);
					if(deleted[i] == v[i].size()){
						ans.pb(v[i]);
					}
				}
			}
			
			int maxDele = -1;
			fr(i,n){
				if(deleted[i] < v[i].size() && deleted[i] > maxDele){
					dele = v[i];
					maxDele = deleted[i];
				}
			}
			if(maxDele == -1) break;
			else{
				cost += dele.size() - maxDele;
			}
		}
		
		printf("%d\n", cost);
		fr(i,ans.size()){
			cout<<ans[i]<<'\n';
		}
		
	}
	return 0;
}
