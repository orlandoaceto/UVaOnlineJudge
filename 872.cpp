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

int n;
bool used[26];
bool letter[26];
vi adjList[26];
bool ans;
void rec(string a){
	int i, j;
	if(a.size() == n){
		ans = 1;
		fr(i,n){
			cout<<a[i];
			if(i < n-1)cout<<' ';
		}
		cout<<'\n';
	}
	fr(i,26){
		if(!used[i] && letter[i]){
			fr(j,adjList[i].size()){
				if(used[adjList[i][j]]) break;
			}
			if(j == adjList[i].size()){
				used[i] = 1;
				a += (char)(i+'A');
				rec(a);
				used[i] = 0;
				if(a.size() > 0)
					a.resize(a.size()-1);
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	int t, k;
	string var;
	string con;
	int i, j;
	
	cin>>t;
	cin.ignore(1, '\n');
	fr(k,t){
		cin.ignore(1, '\n');
		getline(cin, var);
		getline(cin, con);
		
		n = 0;
		memset(letter, 0, sizeof letter);
		memset(used, 0, sizeof used);
		fr(i, var.size()){
			if(var[i] >= 'A' && var[i] <= 'Z'){
				letter[var[i]-'A'] = 1;
				n++;
			}
		}
		
		fr(i,26)adjList[i].clear();
		
		fr(i,con.size()){
			if(con[i] >= 'A' && con[i] <= 'Z'){
				adjList[con[i]-'A'].push_back(con[i+2]-'A');
				i += 3;
			}
		}
		ans = 0;
		rec("");
		if(!ans)cout<<"NO\n";
		if(k < t-1) cout<<"\n";
	}
	
	return 0;
}
