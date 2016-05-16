#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define sc(a) scanf("%d", &a)
typedef pair<int, int> ii;
typedef pair<double, double> dd;


int main()
{
	long long int n;
	while(scanf("%lld", &n) > 0)
	{
		n = (n + 1) / 2;
		n = n * n;
		n = n * 2 - 1;
		printf("%lld\n", n + n - 2 + n - 4);
	}
	return 0;
}
