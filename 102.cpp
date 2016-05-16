#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int main()
{
	string perm;
	string best = "BGC";
	int v[3][3];
	int m, b, i, j;
	
	while(scanf("%d %d %d %d %d %d %d %d %d", &v[0][0], &v[0][1], &v[0][2],&v[1][0], &v[1][1], &v[1][2], &v[2][0], &v[2][1], &v[2][2]) > 0)
	{
		b = INT_MAX;
		perm.clear();
		perm.push_back('B');
		perm.push_back('C');
		perm.push_back('G');
		
		do
		{
			//cout<<"Tentando: "<<perm<<'\n';
			m = 0;
			fr(j, 3)
			{
				fr(i, 3) m += v[j][i];
				if(perm[j] == 'B') m -= v[j][0];
				else if(perm[j] == 'G') m -= v[j][1];
				else if(perm[j] == 'C') m -=v[j][2];
			}
			if(m < b)
			{
				//cout<<"Parcial melhor: "<<perm<<m<<" (Anterior era "<<b<<")\n";
				b = m;
				best = perm;
			}
		}while(next_permutation(perm.begin(), perm.end()));
		cout<<best<<' '<<b<<'\n';
	}
	
	return 0;
}
