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
typedef long long int ll;
typedef unsigned long long int ull;

ull gcd(ull a, ull b){
	return b == 0 ? a: gcd(b, a%b);
}

int main(){
	ull m[25][151];
	ull t[25];
	int i, j, k;
	ull cd;
	int n, x;
	
	memset(m, 0, sizeof m);
	
	m[0][0] = 1;
	t[0] = 1;
	for(i = 1; i <= 24; i++){
		for(j = i; j <= i * 6; j++){
			for(k = 1; k <= 6; k++){
				m[i][j] += m[i-1][j-k];	
			}
		}
		t[i] = t[i-1] * 6;
	}
	for(i = 1; i <= 24; i++){
		for(j = 6*i; j >= 0; j--){
			m[i][j] += m[i][j+1];
		}
	}
	
	while(scanf("%d %d", &n, &x) > 0)
	{
		if(n == 0 && x == 0)break;
		
		cd = gcd(m[n][x], t[n]);
		if(m[n][x] != 0 && m[n][x] != t[n])printf("%llu/%llu\n", m[n][x]/cd, t[n]/cd);
		else if(m[n][x] == 0)printf("0\n");
		else printf("1\n");
	}
	return 0;
}
