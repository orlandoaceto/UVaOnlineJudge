//12004 - Bubble Sort
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


int main(){
	int t;
	ll num, den, n;
	int k;
	sc(t);
	
	fr1(k,t){
		scanf("%lld", &n);
		
		num = (n * (n-1));//Explanation: A single number can be at most n-1 places away from its
							//intended position. Since the chance of each distance is the same, the
							//average for a single number is n-1/2. There are n numbers so this is
							//multiplied by n. Now we have the sum of all distances.
							//The result is, again, divided by 2, because counting the distance of
							//the actual position and the intended position of each n and then dividing
							//everything by 2 is how the number of inversions is counted
		printf("Case %d: ", k);
		if(num % 4 == 0){
			printf("%lld\n", num / 4);
		}
		else{
			printf("%lld/2\n", num/2);//n*(n-1) is always divisible by 2
		}
		
	}
	
	return 0;
}
