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
	int v[10000];
	vector<vi> s;
	int tam, count;
	int i, j, n, maxi;
	bool first = 1;
	
	while(1){
		sc(n);
		if(n == 0) break;
		fr(i,n) sc(v[i]);
		if(!first) printf("\n");
		else first = 0;
		
		sort(v, v+n);
				
		count = 1;
		maxi = 1;
		for(i = 0; i < n; i++){
			if(i > 0 && v[i] == v[i-1]){
				count++;
				maxi = max(maxi, count);
			}
			else count = 1;
		}
		swap(maxi, count);
		
		if(n % count == 0){
			maxi = n / count;
		}
		else maxi = (n / count)+1;
		
		
		s.assign(count, vi());
		
		for(i = 0; i < n; i++){
			s[i%count].push_back(v[i]);
		}
		printf("%d\n", count);
		vi::iterator it;
		fr(i,count){
			for(it = s[i].begin(); it != s[i].end(); it++){
				printf("%d", *it);
				if(it+1 != s[i].end())printf(" ");
			}
			printf("\n");
		}
		
	}
	
	return 0;
}
