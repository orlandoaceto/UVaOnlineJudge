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
	int n, i, w;
	double l;
	while(sc(n) > 0)
	{
		if(n == 0)break;
		w = 4 * pow(2, (n-1960)/10);
		
		
		l = 0;
		for(i = 1; l <= w; i++, l+= log2(i));
		i--;
		
		cout<<i<<'\n';
		
	}
	return 0;
}
