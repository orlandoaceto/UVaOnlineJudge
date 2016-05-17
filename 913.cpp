//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish


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
