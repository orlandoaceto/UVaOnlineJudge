//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish


#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
typedef pair<int, int> ii;
typedef pair<double, double> dd;

bool compare(const pair<int ,int>& p1, const pair<int, int>& p2)
{
	if(p1.second < p2.second) return true;
	else if(p1.second == p2.second && abs(p1.first % 2) == 1 && abs(p2.first % 2) == 0) return true;
	else if(p1.second == p2.second && abs(p1.first % 2) == 1 && abs(p2.first % 2) == 1) return p1.first > p2.first;
	else if(p1.second == p2.second && abs(p1.first % 2) == 0 && abs(p2.first % 2) == 0) return p1.first < p2.first;
	else return false;
}

int main()
{
	int a = 20;
	int n, m, i, r;
	vector<ii> v;
	vector<ii>::iterator it;
	
	while(a--)
	{
		scanf("%d %d", &n, &m);
		if(m == 0 && n == 0) break;
		v.clear();
		fr(i, n)
		{
			scanf("%d", &r);
			v.push_back(make_pair(r, r % m));
		}
		sort(v.begin(), v.end(), compare);
		cout<<n<<" "<<m<<'\n';
		for(it = v.begin(); it != v.end(); it++) cout<<(*it).first<<'\n';
	}
	cout<<"0 0\n";
	return 0;
}
