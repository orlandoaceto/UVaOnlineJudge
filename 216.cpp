#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define ii pair<int, int>
#define dd pair<double, double>

int main()
{
	int n;
	double m[8][8];
	double custoMin, custo;
	ii c[8];
	int i,j;
	vector<int> p;
	vector<int> bp;
	int network = 1;
	
	while(scanf("%d", &n) > 0)
	{
		if(n > 0)
		{
			fr(i, n) scanf("%d %d", &c[i].first, &c[i].second);	
			fr(i,n)fr(j,n)m[i][j] = sqrt(pow((c[i].first - c[j].first), 2) + pow(c[i].second - c[j].second, 2));
			
			custoMin = INT_MAX;
			fr(i, n) p.push_back(i);
			//cout<<'a'<<'\n';
			do
			{
				custo = 0;
				fr(i,n-1)custo+= m[p[i]][p[i+1]] + 16;
				if(custo < custoMin)
				{
					custoMin = custo;
					bp = p;
				}
				//cout<<'b'<<'\n';
			}while(next_permutation(p.begin(), p.end()));
			
			printf("**********************************************************\nNetwork #%d\n", network++);
			fr(i,n-1)
			{
				printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", c[bp[i]].first, c[bp[i]].second, c[bp[i+1]].first, c[bp[i+1]].second, m[bp[i]][bp[i+1]]+16);
			}
			printf("Number of feet of cable required is %.2lf.\n", custoMin);
			p.clear();
			bp.clear();
		}
	}
}
