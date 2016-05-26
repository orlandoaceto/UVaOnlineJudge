//11053 - Flavius Josephus Reloaded
//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

/*
Solution is in c++ 11 (due to unordered_map). To solve this problem, the first number
that is part of the cycle must be determined. The solution is, then, all numbers minus
the ammount of numbers inside the cycle. To do that efficiently, the time of occurrence
of each number can be saved in an unordered map. When a generated number has already 
appeared before, the size of the cycle can be determined by current time - time of
occurrence of this number. All that is left are survivors.
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

ll n, a, b;
inline ll f(ll m){
	return (((a%n * m%n * m%n) % n) + b) %n;
}

int main(){
	unordered_map<ll, int> s;
	ll count, num;
	
	
	while(scanf("%lld %lld %lld", &n, &a, &b) == 3){
		s.clear();
		num = 0;
		count = 0;
		while(s.find(num) == s.end()){
			s[num] = count;
			count++;
			num = f(num);
		}
	
		printf("%lld\n", n - count + s[num]);
	}	

	return 0;
}
