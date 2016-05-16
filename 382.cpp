#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define sc(a) scanf("%d", &a)
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int main()
{
	int n, i, sum;
	
	
	printf("PERFECTION OUTPUT\n");
	while(cin >> n)
	{
		if(n == 0) break;
		sum = 1;
		if(n == 1)sum = 0;
		
		for(i = 2; i <= n/2; i++)if(n % i == 0) sum += n / i;
		
		printf("%5d  ", n);
		if(sum == n)printf("PERFECT\n");
		else if(sum < n)printf("DEFICIENT\n");
		else if(sum > n)printf("ABUNDANT\n");
		
	}
	printf("END OF OUTPUT\n");
	return 0;
}
