//10911 - Forming Quiz Teams
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
#define pb push_back
#define clr(a) memset(a, 0, sizeof a);

const int oo = 0x3f3f3f3f;

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

struct pt{
	int x, y;
	
	pt () {}
	pt (int x, int y) : x(x), y(y) {}
	
	double operator %(const pt o) const{
		return sqrt((o.x - x) * (o.x-x) + (o.y - y) * (o.y-y));
	}

};

vector<pt> v;
int n;
double memo[1<<16];
bool setMemo[1<<16];

double go(int bit){
	
	if(setMemo[bit]) return memo[bit];
	
	if(bit == (1<<(2*n))-1) return 0LL;


	double mini = numeric_limits<double>::infinity();
	
	for(int i = 0; i < 2 * n; i++){
		for(int j = i+1; j < 2*n; j++){
			if(!(bit & 1<<i) && !(bit & 1<<j)){
				mini = min(mini, v[i] % v[j] + go((bit | (1<<i))|(1<<j)));
			} 
		}
	}
	
	setMemo[bit] = 1;
	return memo[bit] = mini;

}

int main(){
	ios_base::sync_with_stdio(false);
	int i, cas= 1;
	string s;
	
	while(true){
		cin>>n;
		if(n == 0) break;
		v.resize(2*n);
		memset(setMemo, 0, sizeof setMemo);
		fr(i,2*n){
			cin>>s>>v[i].x>>v[i].y;
		}
		cout<<"Case "<<cas++<<": "<<setprecision(2)<<fixed<<go(0)<<'\n';
		
	}
	return 0;
}
