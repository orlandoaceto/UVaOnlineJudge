//11130 - Billiard bounces
//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

/*
This problem can be solved in O(1). It is given that the speed decreases linearly in a time equal to s.
So the average speed is v/2. The distance is v/2 * s. From the angle and distance, horizontal distance and
vertical distance can be calculated.
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
	double a, b, v, ang, s;
	double distA, distB, dist;
	
	while(scanf("%lf %lf %lf %lf %lf", &a, &b, &v, &ang, &s) > 0){
		if(!(a > 0 || b > 0 || v > 0 || ang > 0 || s > 0)) break;
		ang = (ang/360.0) * 2 * acos(-1);
		dist = (v/2) * s;
		distA = dist * cos(ang);
		distB = dist * sin(ang);
		
		printf("%d %d\n", (int)((abs(distA) + a/2) / a), (int)((abs(distB) + b/2) / b));
	}
	
	return 0;
}
