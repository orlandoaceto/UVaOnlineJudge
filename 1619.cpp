//1619 - Feel Good
//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

/*
Hint: To get AC on this problem, I had to put some additional constraints found in other people's
codes online. The problem statement says you can output any valid answer, however, all solutions I
found compared the size of the newly found solution with the size of the previous found answer if the 
result was the same. I'm not sure it was necessary, it could be just some stupid mistake I made and didn't
find, but it was the only way I seemed to be able to get AC. So keep that in mind.
This paragraph refer to lines 81 until 84 of this solution
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
	int n, i;
	ll v[100010], sum[100010];
	int l[100010], r[100010];
	ll val, maxi;
	
	bool linebreak = 0;
	
	while(scanf("%d", &n) > 0){
		if(!linebreak) linebreak = 1;
		else printf("\n");
		
		clr(l);
		clr(r);
		clr(sum);//Only the sum array actually needs to be cleared
		clr(v);
		
		for(i = 1; i <= n; i++){//Reads input and sets every sum[i] to the sum from 1 to i
			scanf("%lld", &v[i]);
			sum[i] = sum[i-1]+v[i];
			l[i]=r[i]=i;
		}
		for(i = 1; i <= n; i++){         //Sets value of each l[i] as left boundary for subarray containing v[i]
			if(v[i]){				 	 //that doesn't have any value lower than v[i] using Dynamic Programming
				while(l[i]-1 >= 1 && v[l[i]-1] >= v[i]){
					l[i] = l[l[i]-1];
				}
			} 
		}
		for(i = n; i >= 1; i--){         //Same as above for right boundary
			if(v[i]){
				while(r[i]+1 <= n && v[r[i]+1] >= v[i]){
					r[i] = r[r[i]+1];
				}
			}
		}
		val = 0;
		maxi = 0;
		int ind;
		for(i = 1; i <= n; i++){
			if(v[i]){
				val = v[i] * (sum[r[i]] - sum[l[i]-1]); //v[i] is the smallest element in subarray l[i]...r[i]
				if(val > maxi){
					maxi = val;
					ind = i;
				}
				else if(val == maxi){
					int dif = r[ind]-l[ind] - r[i] + l[i];
					if(dif > 0 || (dif == 0 && l[i] < l[ind])){
						ind = i;
					}
				}
			}
		}
		
		printf("%lld\n%d %d\n", maxi, l[ind], r[ind]);
	}
}
