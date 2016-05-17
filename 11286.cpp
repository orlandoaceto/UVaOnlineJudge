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
	int n, i, j, r, maxi, num;
	map<vector<int>, int> m;
	map<vector<int>, int>::iterator it;
	vector<int>::iterator itAux;
	vector<int> v[10000];
	while(scanf("%d", &n) > 0)
	{
		if(n > 0)
		{
			fr(i,n)
			{
				fr(j,5)
				{
					scanf("%d", &r);
					v[i].push_back(r);
				}
				sort(v[i].begin(), v[i].end());
				//for(itAux = v[i].begin(); itAux != v[i].end(); it++) cout<<*itAux<<' ';
				//cout<< '\n';
				m[v[i]]++;
				v[i].clear();
			}
			num = 0;
			maxi = 0;
			for(it = m.begin(); it != m.end(); it++) maxi = max(maxi, it->second);
			for(it = m.begin(); it != m.end(); it++)
			{ 
				//cout<<"frequency: "<<it->second<<'\n';
				if(it->second == maxi) num+= maxi;
			}
			cout<<num<<'\n'; 
			m.clear();
		}
	}
	return 0;
}
