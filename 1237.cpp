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

	int t, d, q, p, pos;
	vector<string> vs;
	vii vr;
	int i, j;
	
	sc(t);
	while(t--){
		scanf("%d\n", &d);
		vr.resize(d);
		vs.resize(d);
		fr(i,d){
			cin>>vs[i];
			scanf("%d %d\n", &vr[i].fi, &vr[i].se);
		}
		sc(q);
		fr(i,q){
			sc(p);
			pos = -1;
			fr(j,d){
				if(vr[j].fi <= p && vr[j].se >= p){
					if(pos == -1)pos = j;
					else{
						pos = -1;
						break;
					}
				}
			}
			if(pos != -1){
				cout<<vs[pos]<<'\n';
			}
			else printf("UNDETERMINED\n");
		}
		if(t>0)printf("\n");
	}

	return 0;
}
