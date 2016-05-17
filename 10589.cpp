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

double dist(dd a, dd b){
	return (a.fi-b.fi) * (a.fi - b.fi) + (a.se-b.se) * (a.se - b.se);
}

int main(){
	
	dd sq[4];
	dd p;
	double d, a;
	double n, m; 
	int i, j;
	int count;
	
	while(1){
		scanf("%lf %lf", &n, &a); if(n == 0) break;
		m = 0;
		sq[0] = p(0, 0);
		sq[1] = p(0, a);
		sq[2] = p(a, a);
		sq[3] = p(a, 0);
		
		fr(i,n){
			scanf("%lf %lf", &p.fi, &p.se);
			count = 0;
			fr(j,4){
				if(dist(p, sq[j]) <= a*a){
					count++;
				}
			}
			if(count == 4)m++;
		}
		double area = (m * a * a)/n;
		printf("%0.5lf\n", area);
		
	}

	return 0;
}
