//10650 - Determinate Prime
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

int main(){
	bool isP[35000];
	int start[32001];
	vii sets;
	vi pri;
	memset(isP, 1, sizeof isP);
	
	for(int i = 2; i < 35000; i++){
		if(isP[i]) pri.pb(i);
		for(int j = i*i; j < 35000; j += i){
			isP[j] = 0;
		}
	}
	
	int first = 0, dist = 1;
	for(int i = 2; i < pri.size(); i++){
		if(pri[i] - pri[i-1] != dist){
			if(i - first > 2){
				sets.pb(ii(first, i-1));
			}
			first = i-1;
			dist = pri[i]-pri[i-1];
		}
	}

	for(int i = 0, j = 0; i <= 32000; i++){
		while(j < sets.size() && pri[sets[j].fi] < i) j++;
		if(j == sets.size()){
			while(i <= 32000){
				start[i] = j-1;
				i++;
			}
			break;
		}
		start[i] = j;
	}
	
	int x, y;
	
	while(scanf("%d %d", &x, &y) > 0){
		if(y < x) swap(x,y);
		if(x == 0 && y == 0) break;
		int i = start[x];
		while(pri[sets[i].se] <= y){
			for(int j = sets[i].fi; j <= sets[i].se; j++){
				printf("%d", pri[j]);
				if(j != sets[i].se){
					printf(" ");
				}
				else printf("\n");
			}
			i++;
		}
	}
	
	return 0;
}
