#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define sc(a) scanf("%d", &a)
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int main()
{
	int t, i, n, j;
	int v[11];
	sc(t);
	fr(i,t)
	{
		sc(n);
		fr(j,n)sc(v[j]);
		printf("Case %d: %d\n", i+1, v[j/2]);
	}
	return 0;
}
