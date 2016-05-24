//1047 - Zones
//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

#include <bits/stdc++.h>
using namespace std;

/*
This problem is solved with a complete search. prev_permutation can be used
to generate all combination of size n, provided it is used in a vector with
the correct number of 1's and 0's and starting from all 1's to the left of
all 0's.
*/

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
	int n, m, i, j, maxi, num, com, size, aux, no, qtd, cas = 1;
	vector<bool> incl, ans;
	vi v, vo;
	vector<vi> o;
	
	while(scanf("%d %d", &n, &m) > 0){
		if(n == 0 && m == 0) break;
		incl.assign(n, 0);
		v.resize(n);
		fr(i,m){
			incl[i] = 1;
		}
		fr(i,n){
			sc(v[i]);
		}
		sc(no);
		o.assign(no, vi());
		vo.resize(no);
		fr(i,no){
			sc(size);
			o[i].resize(size);
			fr(j,size){
				sc(aux);
				o[i][j] = aux-1;
			}
			sc(aux);
			vo[i] = aux;
		}
		
		maxi = 0;
		do{
			num = 0;
			fr(i,n){
				if(incl[i]) num += v[i];
			}
			fr(i, no){
				qtd = 0;
				fr(j, o[i].size()){
					if(incl[o[i][j]]) qtd++;
				}
				if(qtd > 0)
					num -= vo[i]* (qtd-1);
			}
			if(num > maxi){
				maxi = num;
				ans = incl;
			}
			
		}while(prev_permutation(incl.begin(), incl.end()));
		printf("Case Number  %d\nNumber of Customers: %d\nLocations recommended:", cas++, maxi);
		fr(i,n){
			if(ans[i])printf(" %d", i+1);
		}
		printf("\n\n");
	}
	
	return 0;
}
