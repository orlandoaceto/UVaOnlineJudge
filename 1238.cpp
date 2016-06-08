//1238 - Free Parentheses
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

vi v;
vector<bool> ne;
bool p[6002];
bool pd[6002][30][30];
int n;

void go(int sum, int pos, int paren){
	if(pos == n){
		p[3000+sum] = 1;
		return;
	}
	if(pd[3000+sum][pos][paren]) return;
	
	
	go(sum + (paren%2? -v[pos]: v[pos]), pos+1, paren);//Don't add any parentheses
	
	if(paren > 0){
		go(sum + ((paren-1)%2? -v[pos]: v[pos]), pos+1, paren-1);//Remove a parentheses
		if(ne[pos]){
			go(sum + ((paren-1)%2? -v[pos]: v[pos]), pos+1, paren);//Remove and then add a new parentheses
		}
	}
	
	if(ne[pos]){		
		go(sum + ((paren)%2? -v[pos]: v[pos]), pos+1, paren+1);//Add parentheses
		//Note that parentheses are only added after minus signs
	}
	
	pd[3000+sum][pos][paren] = 1;
	return;
}

int main(){
	int num, i;
	bool neg;
	char r;
	
	while(scanf("%d", &num) > 0){
		clr(p);
		clr(pd);
		v.clear();
		ne.clear();
	
		v.pb(num);
		ne.pb(0);
		while(scanf("%c", &r) > 0){
			if(r == ' '){
				scanf("%c", &r);
				if(r == '\n') break;
				if(r == '+') neg = 0;
				else if(r == '-') neg = 1;
				scanf(" %d", &num);
				
				if(neg) num *= -1;
				ne.pb(neg);
				v.pb(num);
			}
			else if(r == '\n'){
				break;
			}
		}
		n = (int)v.size();
		go(0,0,0);
		int qtd = 0;
		for(i = 0; i <= 6000; i++){
			if(p[i]) qtd++;
		}
		printf("%d\n", qtd);
	}
	
	return 0;
}
