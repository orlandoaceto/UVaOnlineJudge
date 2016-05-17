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
	long long a, ai,l, n, c = 1;
	
	while(scanf("%lld %lld", &a, &l))
	{
		if(a < 0 && l < 0) break;
		n = 1;
		ai = a;
		
		while(a > 1 && a <= l)
		{
			if(a % 2 == 0)
			{
				a = a/2;
				if(a <= l)
					n++;
			}
			else if(a % 2 == 1)
			{
				 a = a * 3 + 1;
				 if(a <= l)
					 n++;
			}
			
		}
		
		printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n", c++, ai, l, n);
	}
	
	return 0;
}
