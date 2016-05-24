//11242 - Tour de France
//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

/*
Simple complete search problem. Generate all ratios, sort them
and then get the lowest quotient between 2 adjacent ratios.
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

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

int main(){
	int nf, nr;
	int f[10], r[10];
	vector<double> rat;
	int i, j; 
	double maxi;
	
	while(scanf("%d %d", &nf, &nr) == 2){
		fr(i,nf){
			sc(f[i]);
		}
		fr(i,nr){
			sc(r[i]);
		}
		
		fr(i,nf){
			fr(j,nr){
				rat.pb((double)r[j]/f[i]);
			}
		}
		sort(rat.begin(), rat.end());
		maxi = 0;
		fr(i,rat.size()-1){
			if(rat[i+1]/rat[i] > maxi) maxi = rat[i+1]/rat[i];
		}
		printf("%.2lf\n", maxi);
		rat.clear();
	}
	
	return 0;
}
