#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define sc(a) scanf("%d", &a)
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int main()
{
	int n;
	while(sc(n) > 0)
	{
		if(n == 0)break;
		printf("%d\n", (int)log2(n));
	}
	return 0;
}
