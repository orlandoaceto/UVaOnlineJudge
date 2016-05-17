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
	set<int> s;
	int m, r, n1, n2, i;
	
	while(scanf("%d %d", &n1, &n2) > 0)
	{
		if(n1 > 0 || n2 > 0)
		{
				fr(i, n1)
				{
					scanf("%d", &r);
					s.insert(r);
				}
				m = 0;
				fr(i, n2)
				{
					scanf("%d", &r);
					if(s.find(r) != s.end()) m++;
				}
				cout<<m<<'\n';
				s.clear();
		}
	}
}
