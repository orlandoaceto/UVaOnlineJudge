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
	int t, n, s, i, l, bi;
	map<int, int> m;
	
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		i = 0;
		l = 0;
		bi = 0;
		while(n--)
		{
			i++;
			scanf("%d", &s);
			l = max(m[s], l);
			bi = max(bi, i-l);
			m[s] = i;
		}
		m.clear();
		printf("%d\n", bi);
	}
	return 0;
}
