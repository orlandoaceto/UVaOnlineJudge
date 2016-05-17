//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish


#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int main()
{
	int t;
	scanf("%d", &t);
	int n, m, mult1, mult2;
	while(t--)
	{
		scanf("%d %d", &n, &m);
		n-= 2;
		m-= 2;
		mult1 = n/3;
		if(n % 3 > 0)mult1++;
		mult2 = m/3;
		if(m % 3 > 0)mult2++;
		printf("%d\n", mult1 * mult2);
		
	}
}	
