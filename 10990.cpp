//10990 - Another New Function
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
#define pb push_back
#define clr(a) memset(a, 0, sizeof a);

const int oo = 0x3f3f3f3f;

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

int numRP[2000001];
ll depthPhi[2000001];

int main(){
	int i, j;
	int t;
	
	for(i = 1; i <= 2000000; i++){//Initializes numRP
		numRP[i] = i;
	}
	
	for(i = 2; i <= 2000000; i++){//numRP[i] now has number of relative primes to i which are <= i
		if(numRP[i] == i){
			for(j = i; j <= 2000000; j += i){
				numRP[j] = (numRP[j]/i) * (i-1);
			}
		} 
	}

	clr(depthPhi);
	depthPhi[1] = 0;
	for(i = 2; i <= 2000000; i++){
		depthPhi[i] = depthPhi[numRP[i]]+1;//depthPhi[i] now has value of depthPhi(i)
	}
	
	for(i = 2; i <= 2000000; i++){
		depthPhi[i] += depthPhi[i-1]; //depthPhi[i] now has accumulated depthPhi from 1 to i
	}
	
	scanf("%d", &t);
	
	while(t--){//Reads and answer each input in O(1)
		int m, n;
		scanf("%d %d", &m, &n);
		printf("%lld\n", depthPhi[n] - depthPhi[m-1]);
	}
	
	return 0;
}
