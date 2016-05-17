//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish


#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int main()
{
	int n, pos;
	string st;
	string sub;
	string pas;
	int highestFreq;
	map<string, int> fr;
	while(scanf("%d ", &n) > 0)
	{
		fr.clear();
		getline(cin, st);
		pos = 0;
		highestFreq = 0;
		sub = st.substr(pos++, n);
		while(sub.size() == n)
		{
			if(++fr[sub] > highestFreq)
			{ 	
				highestFreq = fr[sub];
				pas = sub;
			}
			sub = st.substr(pos++, n);
		}
		cout<<pas<<'\n';
	}
		
}
