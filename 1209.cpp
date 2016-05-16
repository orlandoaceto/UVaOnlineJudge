#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define ii pair<int, int>;
#define dd pair<double, double>;

int main()
{
	string s;
	string best;
	string::iterator it;
	int dist, maxDist;
	int i;
	
	while(cin>>s)
	{
		fr(i,10)prev_permutation(s.begin(), s.end());
		maxDist = 0;
		best = s;
		fr(i,21)
		{
			dist = INT_MAX;
			for(it = s.begin()+1;it != s.end();it++) dist =min(dist, abs(*(it-1) - *it));
			//cout<<"dist: "<<dist<<'\n';
			if(dist > maxDist)
			{
				maxDist = dist;
				best = s;
				//cout<<"Best: "<<best<<'\n';
			}
			next_permutation(s.begin(), s.end());
		}
		cout<<best<<maxDist<<'\n';
	}
	return 0;
}
