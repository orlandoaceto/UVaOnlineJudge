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
	vector<string> v;
	vector<vi> adjList;
	vi num, list;
	map<string, int> um;
	int n, m, i, cas = 1;
	priority_queue<int, vector<int>, greater<int> > q;
	string s1, s2;
	
	while(cin>>n){
		cin.ignore(1, '\n');
		
		v.resize(n);
		num.assign(n, 0);
		fr(i,n){
			cin>>v[i];
			um[v[i]] = i;
		}	
	
		cin>>m;
		cin.ignore(1, '\n');
		
		adjList.assign(n, vi());
		fr(i,m){
			cin>>s1;
			cin>>s2;
			adjList[um[s1]].push_back(um[s2]);
			num[um[s2]]++;
		}
		
		fr(i,n){
			if(num[i] == 0){
				q.push(i);
			}
		}
	
		list.clear();
		while(!q.empty()){
			int u = q.top();
			q.pop();
			list.push_back(u);
			fr(i,adjList[u].size()){
				num[adjList[u][i]]--;
				if(num[adjList[u][i]] == 0) q.push(adjList[u][i]);
			}
		}
		cout<<"Case #"<<cas++<<": Dilbert should drink beverages in this order:";
		fr(i,n){
			cout<<' '<<v[list[i]];
		}
		cout<<".\n\n";
	}
	return 0;
}
