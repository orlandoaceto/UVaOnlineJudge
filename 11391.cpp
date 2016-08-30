//11391 - Blobs in the Board
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

int memo[32][32][32][32];
int r, c;
ll go(int st[4]){
	int i, j;
	ll num = 0;
	fr(i,r) num += __builtin_popcount(st[i]);
	if(num == 1) return 1;
	if(~memo[st[0]][st[1]][st[2]][st[3]]) return memo[st[0]][st[1]][st[2]][st[3]];
	num = 0;
	fr(i,r){
		fr(j,c){
			if(st[i] & (1<<j)){
				if(j + 2 < c && (st[i]&(1<<(j+1))) && !(st[i]&(1<<(j+2)))){
					st[i] ^= (1<<j);
					st[i] ^= (1<<(j+1));
					st[i] ^= (1<<(j+2));
					num += go(st);
					st[i] ^= (1<<j);
					st[i] ^= (1<<(j+1));
					st[i] ^= (1<<(j+2));
				}
				if(j - 2 >= 0 && (st[i]&(1<<(j-1))) && !(st[i]&(1<<(j-2)))){
					st[i] ^= (1<<j);
					st[i] ^= (1<<(j-1));
					st[i] ^= (1<<(j-2));
					num += go(st);
					st[i] ^= (1<<j);
					st[i] ^= (1<<(j-1));
					st[i] ^= (1<<(j-2));
				}
				if(i + 2 < r && (st[i+1]&(1<<j)) && !(st[i+2]&(1<<j))){
					st[i] ^= (1<<j);
					st[i+1] ^= (1<<j);
					st[i+2] ^= (1<<j);
					num += go(st);
					st[i] ^= (1<<j);
					st[i+1] ^= (1<<j);
					st[i+2] ^= (1<<j);
				}
				if(i - 2 >= 0 && (st[i-1]&(1<<j)) && !(st[i-2]&(1<<j))){
					st[i] ^= (1<<j);
					st[i-1] ^= (1<<j);
					st[i-2] ^= (1<<j);
					num += go(st);
					st[i] ^= (1<<j);
					st[i-1] ^= (1<<j);
					st[i-2] ^= (1<<j);
				}
				if(j + 2 < c && i + 2 < r && (st[i+1]&(1<<(j+1))) && !(st[i+2]&(1<<(j+2)))){
					st[i] ^= (1<<j);
					st[i+1] ^= (1<<(j+1));
					st[i+2] ^= (1<<(j+2));
					num += go(st);
					st[i] ^= (1<<j);
					st[i+1] ^= (1<<(j+1));
					st[i+2] ^= (1<<(j+2));
				}
				if(j - 2 >= 0 && i + 2 < r && (st[i+1]&(1<<(j-1))) && !(st[i+2]&(1<<(j-2)))){
					st[i] ^= (1<<j);
					st[i+1] ^= (1<<(j-1));
					st[i+2] ^= (1<<(j-2));
					num += go(st);
					st[i] ^= (1<<j);
					st[i+1] ^= (1<<(j-1));
					st[i+2] ^= (1<<(j-2));
				}
				if(j + 2 < c && i - 2 >= 0 && (st[i-1]&(1<<(j+1))) && !(st[i-2]&(1<<(j+2)))){
					st[i] ^= (1<<j);
					st[i-1] ^= (1<<(j+1));
					st[i-2] ^= (1<<(j+2));
					num += go(st);
					st[i] ^= (1<<j);
					st[i-1] ^= (1<<(j+1));
					st[i-2] ^= (1<<(j+2));
				}
				if(j - 2 >= 0 && i - 2 >= 0 && (st[i-1]&(1<<(j-1))) && !(st[i-2]&(1<<(j-2)))){
					st[i] ^= (1<<j);
					st[i-1] ^= (1<<(j-1));
					st[i-2] ^= (1<<(j-2));
					num += go(st);
					st[i] ^= (1<<j);
					st[i-1] ^= (1<<(j-1));
					st[i-2] ^= (1<<(j-2));
				}
			}
		}
	}
	
	return memo[st[0]][st[1]][st[2]][st[3]] = num;
}

int main(){
	int i, j, k, t, n;
	int st[4];
	
	sc(t);
	
	fr1(k,t){
		memset(memo, -1, sizeof memo);
		memset(st, 0, sizeof st);
		scanf("%d %d %d", &r, &c, &n);
		while(n--){
			scanf("%d %d", &i, &j);
			i--;
			j--;
			st[i] |= (1<<j);
		}
		printf("Case %d: %lld\n", k, go(st));
	}
	
	return 0;
}
