//10140 - Prime Distance
//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

/*
This solution is just fast enough to pass the time limit, but it's not very
efficient. I thought it was simpler to code though, so I did.
First, all primes until at least 2^16 must be generated (sqrt of 2^32).
Then simple linear scans can be done from l to u testing if any of the
primes generated divide the number being considered. If none do, then it is a
prime and you can calculate the distance from it to the last prime you found,
updating maxDist and minDist when the current distance is better than the 
previously saved. 
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

vi pri;

inline bool prime(unsigned int n){
	int i;
	
	fr(i,pri.size()){
		if(pri[i] >= n) return 1;
		if(n % pri[i] == 0) return 0;
	}
	return 1;
}

int main(){
	bitset<66000> isP;
	unsigned int i, j;
	unsigned int l, u;
	unsigned int curr, prev, distMin, distMax, close1, close2, far1, far2;
	
	isP.set();
	
	for(ll i = 2; i < 66000; i++){
		if(isP[i]){
			pri.pb(i);
			for(ll j = i * i; j < 66000; j += i){
				isP[j] = 0;
			}
		}
	}
	
	
	
	while(scanf("%d %d", &l, &u) > 0){
		
		if(l == 1) l++;
		
		for(curr = l; !prime(curr); curr++);
		
		prev = curr;
		if(curr == 2) curr++;
		else curr += 2;
		
		distMin = oo;
		distMax = 0;
		while(curr <= u){
			if(prime(curr)){
				if(curr - prev < distMin){
					distMin = curr - prev;
					close1 = prev;
					close2 = curr;
				}
				if(curr - prev > distMax){
					distMax = curr - prev;
					far1 = prev;
					far2 = curr;
				}
				prev = curr;
			}
			curr+= 2;
		}
		
		if(distMax == 0){
			printf("There are no adjacent primes.\n");
		}
		else{
			printf("%u,%u are closest, %u,%u are most distant.\n", close1, close2, far1, far2);
		}
	
	}
	
	return 0;
}
