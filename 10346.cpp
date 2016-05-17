//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish


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
