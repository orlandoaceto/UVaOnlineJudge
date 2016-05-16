#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define sc(a) scanf("%d", &a)
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int main()
{
	int t, i;
	int d, v, u;
	double t1, t2;
	
	sc(t);
	fr(i, t)
	{
		scanf("%d %d %d", &d, &v, &u);
		printf("Case %d: ", i+1);
		if(v == 0 || u == 0 || u <= v) printf("can\'t determine\n");
		else
		{
			t1 = d / (double)(sqrt(u*u - v*v));
			t2 = d / (double)u;
			
			printf("%.3lf\n", abs(t1-t2));
		}
	}
	
	return 0;
}
