#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define sc(a) scanf("%d", &a)
typedef pair<int, int> ii;
typedef pair<double, double> dd;

bool comp(const ii a, const ii b)
{
	return (double)a.first/a.second < (double)b.first/b.second;
}

int gcd(int a, int b)
{
	return a == 0 ? b : gcd(b%a, a);
}

int main()
{
	vector<ii> v;
	int n, k, i, j;
	while(scanf("%d %d", &n, &k) > 0)
	{
		for(i = 2; i <= n; i++)for(j = 1; j < i; j++)if(gcd(i,j) == 1)v.push_back(make_pair(j, i));
		
		sort(v.begin(), v.end(), comp);
		
		
		
		if(k <= v.size())printf("%d/%d\n", v[k-1].first, v[k-1].second);
		else printf("1/1\n");
		
		v.clear();
	}
	
	
	return 0;
}
