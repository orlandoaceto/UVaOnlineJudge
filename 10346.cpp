#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int main()
{
	int n, k, ans;
	while(scanf("%d %d", &n, &k) > 0)
	{
		ans = n;
		while(n >= k)
		{
			ans += n/k;
			n = n/k + n%k;
		}
		printf("%d\n", ans);
	}
}
