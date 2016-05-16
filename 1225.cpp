#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define sc(a) scanf("%d", &a)
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int main()
{
	int t, k;
	int n, i, c;
	int oc[10];
	sc(t);
	fr(k,t)
	{
		sc(n);
		memset(oc, 0, sizeof oc);
		for(i = 1; i <= n; i++)
		{
			c = i;
			while(c>0)
			{
				oc[c%10]++;
				c /= 10;
			}
		}
		printf("%d", oc[0]);
		fr(i,9)printf(" %d", oc[i+1]);
		printf("\n");
		
	}
	return 0;
}
