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

int gcd(int a, int b){
	return b == 0 ? a: gcd(b, a%b);
}

int main(){

	int i, j, n, sum;
	int m[501][501];
	
	memset(m, 0, sizeof m);
	
	for(i = 1; i < 500; i++) for(j = i+1; j <= 500; j++) m[i][j] = gcd(i, j);
			
	
	while(sc(n) > 0)
	{
		if(!n) break;
		
		sum = 0;
		for(i = 1; i < n; i++) for(j = i+1; j <= n; j++)sum += m[i][j];
		
		pr(sum);
	}
	return 0;
}
