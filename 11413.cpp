//11413 - Fill the Containers
//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

/*
This problem can be solved with binary search and a linear simulation within.
You start with the highest possible anser (1000 vessels * 1000000 capacity = 1000000000
divided by 1 container only) and lowest possible value = 1. For each step of the binary
search, the simulations is as follows: Try to transfer every vessel of milk to m containers
of capacity (highest value + lowest value)/2. If there aren't enough containers, then new
lowest value is the middle value. If there are still containers available to fill, new highest
value is the middle. Keep doing that until highest value equals lowest value. This is the answer.
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
	int n, m, i, j;
	int hi, lo, mid, aux;
	bool found;
	int v[1010];
	
	while(scanf("%d %d", &n, &m) > 0){
		fr(i,n){
			scanf("%d", &v[i]);
		}
		lo = 1;
		hi = 1000000000;
		while(lo != hi){
			mid = (hi + lo)/2;
			aux = mid;
			j = 0;
			for(i = 0; i < n && j < m;){
				if(v[i] <= aux){
					aux -= v[i];
					i++;
				}
				else{
					j++;
					aux = mid;
				}
			}
			if(i == n){
				hi = mid;
			}
			else if(j == m){
				if(mid == lo)lo++;
				else lo = mid;
			}
		}
		printf("%d\n", lo);
	}
	
	return 0;
}
