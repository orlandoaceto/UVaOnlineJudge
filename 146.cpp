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
	string str;
	string cmp = "#";
	do
	{
		getline(cin, str);
		
		if(str != cmp)
		{
			if(next_permutation(str.begin(), str.end())) cout<<str<<'\n';
			else cout<<"No Successor"<<'\n';
		}
	}while(str != cmp);
	
	return 0;
}
