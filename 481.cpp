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
	vector<int> v;
	
	int n, i, j;
	int size, longest;
		
	while(scanf("%d", &n) > 0) v.push_back(n);
	
	vector< vector<int> > l(v.size());
	
	size = 1;
	longest = 0;
	
	l[0].push_back(v[0]);
	for(i = 1; i < v.size(); i++)
	{
		for(j = 0; j < i; j++)
		{
			if(v[j] < v[i] && l[i].size() < l[j].size()+1) l[i] = l[j];
		}
		l[i].push_back(v[i]);
		
		if(l[i].size() > size)
		{
			size = l[i].size();
			longest = i;
		}
	}
	
	printf("%d\n-\n", size);
	for(vector<int>::iterator it = l[longest].begin(); it != l[longest].end(); it++) cout<<*it<<'\n';
	
	return 0;
}
