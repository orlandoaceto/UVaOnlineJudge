//10233 - Dermuba Triangle
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

const double angle = acos(-1)/3.0;//60 degree angle in radians

double vert(int n){
	double y;
	int row;
	row = sqrt(n);
	y = row * sin(angle);

	if((n - row*row) % 2 == 0){
		y += (2.0/3) * sin(angle);
	}
	else{
		y += (1.0/3) * sin(angle);
	}
	
	return y;
}

double horiz(int n){
	double x = 0;
	int row;
	
	row = sqrt(n);
	
	x -= row*0.5;
	x += (n-row*row) * 0.5;
	
	return x;
}

int main(){
	
	int n1, n2;
	double x1, y1, x2, y2;
		
	while(scanf("%d %d", &n1, &n2) > 0){
		y1 = vert(n1);
		y2 = vert(n2);
		x1 = horiz(n1);
		x2 = horiz(n2);
		
		
		printf("%.3lf\n", sqrt((y1-y2)*(y1-y2) + (x1-x2)*(x1-x2)));
	}

	return 0;
}
