//11516 - WiFi
//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define fr1(a, n) for(a = 1; a <= n; a++)
#define sc(a) scanf("%d", &a)
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

int v[100100];
int m, n;
bool test(int rang){
	int covered = v[0] + rang*2;
	int cnt = 1;
	for(int i = 0; i < m; i++){
		if(covered < v[i]){
			cnt++;
			covered = v[i] + rang*2;
		}
	}
	
	return cnt <= n;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t, i;
	
	cin>>t;
	while(t--){
		cin>>n>>m;
		fr(i,m){
			cin>>v[i];
			v[i] *= 10;
		}
		sort(v, v+m);
		int hi = 50000000;
		int lo = 0;
		while(hi - lo > 1){
			int mid = (hi+lo)/2;
			if(test(mid)) hi = mid;
			else lo = mid;			
		}
		if(test(lo)) hi = lo;
		printf("%.1lf\n", (double)hi/10);
	}

	return 0;
}
