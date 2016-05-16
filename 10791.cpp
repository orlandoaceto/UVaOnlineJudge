#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define sc(a) scanf("%d", &a)
typedef pair<int, int> ii;
typedef pair<double, double> dd;


int main()
{
	long long toPrint;
	int n, i, j, limit, c = 1;
	bool isP[65600];
	vector<int> primes;
	vector<int> factors;
	
	
	memset(isP, 1, sizeof(isP));
	for(i = 2; i < 65600; i++)
	{
		if(isP[i] = 1)
		{
			primes.push_back(i);
			for(j = i + 2; j < 65600; j+= i)
			{
				isP[j] = 0;
			}
		}
	}
	
	while(scanf("%d", &n) > 0)
	{
		if(n == 0) break;
		factors.clear();
		limit = sqrt(n) + 1;
		for(i = 0; i < primes.size(); i++){
			if(primes[i] > limit)break;
			if(n % primes[i] == 0)
			{
				factors.push_back(primes[i]);
				n /= primes[i];
				while(n % primes[i] == 0){
					(*(factors.end() - 1))*= primes[i];
					n /= primes[i];
				}
			}
		}
		if(n > 1)factors.push_back(n);
		
		//for(i = 0; i < factors.size(); i++) printf("%d ", factors[i]);
		//printf("\n");
		
		toPrint = 0;
		for(i = 0; i < factors.size(); i++) toPrint += factors[i];
		
		if(factors.size() == 1) toPrint += 1;
		else if(factors.size() == 0) toPrint = 2;
		
		printf("Case %d: %lld\n", c++, toPrint);
	}
	
	
	return 0;
}
