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
	int n, l, i, j;
	int v[1<<15];
	int pot[1<<15];
	int bitm;
	int sum, maxSum;
	
	while(cin>>n){
		l = 1<<n;
		
		fr(i,l)sc(v[i]);
		
		fr(i,l){
			bitm = 1;
			sum = 0;
			fr(j,n){
				sum += v[i^bitm];
				bitm <<= 1;
			}
			pot[i] = sum;
		}
		maxSum = 0;
		fr(i,l){
			bitm = 1;
			fr(j,n){
				maxSum = max(maxSum, pot[i] + pot[i^bitm]);
				bitm<<=1;
			}
		}
		
		cout<<maxSum<<endl;
	}
	
	return 0;
}
