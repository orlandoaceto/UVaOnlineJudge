#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define sc(a) scanf("%d", &a)
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int main()
{
	int r, n, c = 1;
	int ans;
	while(scanf("%d %d", &r, &n) > 0)
	{
		if(r == 0 && n == 0) break;
		printf("Case %d: ", c++);
		
		ans = ((r-1)/n);
		
		if(ans <= 26)printf("%d\n", ans);
		else printf("impossible\n");
	}
	return 0;
}
