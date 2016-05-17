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
	int n;
	vector<pair<pair<int,string>, string> > pilots;
	string name;
	int min, sec, ms;
	int row, i;
	
	while(scanf(" %d", &n) > 0){
		pilots.resize(n);
		fr(i,n){
			cin>>name;
			pilots[i].se = name;
			transform(name.begin(), name.end(), name.begin(), ::tolower);
			pilots[i].fi.se = name;
			scanf(" : %d min %d sec %d ms\n", &min, &sec, &ms);
			pilots[i].fi.fi = ms+sec*1000+min*60*1000;
		}
		stable_sort(pilots.begin(), pilots.end());
		row = 1;
		
		fr(i,n){
			if(i % 2 == 0)printf("Row %d\n", row++);
			cout<<pilots[i].se<<'\n';
		}
		printf("\n");
		
	}	

	return 0;
}

