//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish


#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define fr1(a, n) for(a = 1; a <= n; a++)
#define frR(a, n) for (a = n; a >= 0; a--)
#define sc(a) scanf("%d", &a)
#define pr(a) printf("%d\n", a)
#define p(i, j) make_pair(i, j)
#define fi first
#define se second

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

int main(){
	vector< stack<char> > vs;
	int i, j;
	string in;
	int c = 1;
	
	while(cin >> in){
		if(in == "end") break;
		vs.assign(26, stack<char>());
		for(i = 0; i < in.size();i++){
			for(j = 0;;j++){
				if(vs[j].empty() || vs[j].top() >= in[i]){
					vs[j].push(in[i]);
					break;
				}
			}
		}
		for(j = 0; j < 26;j++)if(vs[j].empty())break;
		printf("Case %d: %d\n", c++, j);
	}
		

	return 0;
}
