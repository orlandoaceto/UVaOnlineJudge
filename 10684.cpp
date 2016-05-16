#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define ii pair<int, int>;
#define dd pair<double, double>;

int main()
{
	int n, i;
	int v;
	int sum, ma;
	while(scanf("%d", &n) > 0)
	{
		if( n > 0)
		{
			sum = 0;
			ma = 0;
			fr(i, n) 
			{
				scanf("%d", &v);
			
				sum += v;
				ma = max(ma, sum);
				if(sum < 0) sum = 0;
			}
		
			if(ma > 0)printf("The maximum winning streak is %d.\n", ma);
			else printf("Losing streak.\n");
		}
	}
}
