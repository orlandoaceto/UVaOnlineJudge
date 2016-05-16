#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define sc(a) scanf("%d", &a)
#define pr(a) printf("%d\n", a)
typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;

int main(){
	int n, c, f;
	double sq;
	while(cin>>n){
		if(n == 0)break;
		sq = sqrt(n);
		c = ceil(sq);
		f = floor(sq);
		
		if(c == f)
		{
			if(c % 2 == 0)printf("%d 1\n", c);
			else printf("1 %d\n", c);
		}
		else if(abs(n-c*c) > abs(n-f*f))
		{
			if(f % 2 == 0)printf("%d %d\n", f+1, n-f*f);
			else printf("%d %d\n", n - f*f, f+1);
		}else if(abs(n-c*c) < abs(n-f*f))
		{
			if(c % 2 == 0)printf("%d %d\n", c, c*c - n + 1);
			else printf("%d %d\n", c*c - n + 1 , c);
		}
		
	}	
	
	return 0;
}
