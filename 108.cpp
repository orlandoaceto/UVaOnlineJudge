//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish


#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define ii pair<int, int>;
#define dd pair<double, double>;

int main()
{
	int n, i, j, k, l;
	int v[101][101];
	
	while(scanf("%d", &n) > 0)
	{
		fr(i,n) fr(j,n) scanf("%d", &v[i+1][j+1]);
		//fr(i,n) fr(j,n) printf("%d ", v[i][j]);
		fr(i,n) v[i][0] = 0;
		fr(i,n) v[0][i] = 0;
		int maxi = -INT_MAX;
		for(i = 1; i <= n; i++) for(j = 1; j <= n; j++)
		{
			v[i][j] += v[i-1][j] + v[i][j-1] - v[i-1][j-1];
			//printf("%d %d: %d\n", i, j, v[i][j]);
			maxi = max(maxi, v[i][j]);
		}
	
		for(i = 1; i <= n;i++)for(j = 1; j <= n;j++)
		{
			for(k = 1; k <= i; k++)for(l = 1; l <= j; l++)
			{
				maxi = max(maxi, v[i][j] - v[i][l-1] - v[k-1][j] + v[k-1][l-1]);
			}
		}
	
		printf("%d\n", maxi);
	}
	return 0;
}
