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
	int t, v;
	
	while(scanf("%d %d", &v, &t) > 0)
	{
		if(t >0)
		{
			printf("%d\n", 2 * v * t);
		}
		else printf("0\n");
	}
	return 0;
}
