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
	vector<long long int> v;
	int n, i;
	
	i = 0;
	while(scanf("%d", &n) > 0)
	{
		i++;
		v.push_back(n);
		if(i % 2 == 1) 
		{
			nth_element(v.begin(), v.begin()+i/2, v.end());
			cout<<*(v.begin()+i/2)<<'\n';
		}
		else
		{
			nth_element(v.begin(), v.begin()+i/2, v.end());
			nth_element(v.begin(), v.begin()+(i/2-1), v.end());
			cout<<(*(v.begin()+i/2) + *(v.begin()+((i/2)-1)))/2<<'\n';
		}
		
	}	
}
