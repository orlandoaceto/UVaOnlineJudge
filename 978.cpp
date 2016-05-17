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
	multiset<int, greater<int> > ga;
	multiset<int, greater<int> > ba;
	multiset<int>::iterator it;
	ii v[100000];
	int n, k, aux;
	int b, sg, sb;
	int i, j;
	
	sc(n);
	fr(k,n){
		ga.clear();
		ba.clear();
		scanf("%d %d %d", &b, &sg, &sb);
		fr(i,sg){
			sc(aux);
			ga.insert(aux);
		}
		fr(i,sb){
			sc(aux);
			ba.insert(aux);
		}
		
		while(1){
			fr(i,b){
				if(!ba.empty() && !ga.empty()){
					v[i].fi = *ga.begin();
					ga.erase(ga.begin());
					v[i].se = *ba.begin();
					ba.erase(ba.begin());
				}
				else break;
			}
			fr(j,i){
				if(v[j].fi > v[j].se) ga.insert(v[j].fi - v[j].se);
				else if(v[j].fi < v[j].se) ba.insert(v[j].se - v[j].fi);
			}
			
			//printf("green size = %d blue size = %d\n", (int)ga.size(), (int)ba.size());
			if(ga.empty() && !ba.empty()){
				printf("blue wins\n");
				for(it = ba.begin();it != ba.end(); it++){
					printf("%d\n", *it);
				}
				if(k+1 != n)printf("\n");
				break;
			}
			else if(ba.empty() && !ga.empty()){
				printf("green wins\n");
				for(it = ga.begin();it != ga.end(); it++){
					printf("%d\n", *it);
				}
				if(k+1 != n)printf("\n");
				break;
			}
			else if(ba.empty() && ga.empty()){
				printf("green and blue died\n");
				if(k+1 != n)printf("\n");
				break;
			}
		}
	}
	return 0;
}
