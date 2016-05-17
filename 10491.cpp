//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish


#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define sc(a) scanf("%d", &a)
#define pr(a) printf("%d\n", a)
typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;

int main()
{
	int cows, cars, show;
	double p, doors;
	while(scanf("%d %d %d", &cows, &cars, &show) > 0){
		doors = cows + cars;
		p = (cows/doors) * ((cars)/(doors-1-show)) + (cars/doors) * ((cars-1)/(doors-1-show));
		printf("%.5lf\n", p);
	}
	
	return 0;
}
