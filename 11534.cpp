//11534 - Say Goodbye to Tic-Tac-Toe
//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

/*
This problem is solved by turning it into the equivalent nim game (using Sprague-Gruny theorem)
and doing the bitwise xor of all stacks. If the number of moves performed is even, then it is 
Alice's turn (thus, first player must win for it to be "possible). If the number of moves performed
is off, then Alice is second player. If she's first, the game must be in a winning state (bitwise xor 
of all 'nimbers' is non-zero), if she's second, the game must be in a losing state (bitwise xor is zero).
*/

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

int pd[101][3][3];

int grundy(int n, int l, int r){
	if(pd[n][l][r] != -1) return pd[n][l][r];
	int i, ans;
	int st, end;
	bool v[101];
	
	clr(v);
	
	ans = 0;
	if(l == 1) st = 2;
	else st = 0;
	if(r == 1) end = n-2;
	else end = n;
	
	ans = 0;
	for(i = st; i < end; i++){
		ans = grundy(i, l, 1) ^ grundy(n-1-i, 1, r); 
		v[ans] = 1;
	}
	
	if(l == 2) st = 2;
	else st = 0;
	if(r == 2) end = n-2;
	else end = n;
	
	for(i = st; i < end; i++){
		ans = grundy(i, l, 2) ^ grundy(n-1-i, 2, r); 
		v[ans] = 1;
	}
	
	for(i = 0; v[i] == 1; i++);
	
	return pd[n][l][r] = i;
}


int main(){
	int t, n, i, l, lv, ans;
	int count, maxi;
	string s;
	memset(pd, -1, sizeof pd);
	
	sc(t);
	
	while(t--){
		cin>>s;
		n = (int)s.size();
		l = -1;
		lv = 0;
		ans = count = maxi = 0;
		for(i = 0; i < n; i++){
			if(s[i] == 'X'){
				count++;
				ans ^= grundy(i-l-1, lv, 1);
				//printf("pd[%d][%d][1] = %d\n", i-l-1, lv, pd[i-l-1][lv][1]);
				//printf("%d\n", ans);
				maxi = max(maxi, pd[i-l-1][lv][1]);
				l = i;
				lv = 1;
			}
			else if(s[i] == 'O'){
				count++;
				ans ^= grundy(i-l-1, lv, 2);
				//printf("pd[%d][%d][2] = %d\n", i-l-1, lv, pd[i-l-1][lv][2]);
				//printf("%d\n", ans);
				maxi = max(maxi, pd[i-l-1][lv][2]);
				l = i;
				lv = 2;
			}
		}
		ans ^= grundy(i-l-1, lv, 0);
		//printf("pd[%d][%d][0] = %d\n", i-l-1, lv, pd[i-l-1][lv][0]);
		//printf("%d\n", ans);
		maxi = max(maxi, pd[i-l-1][lv][0]);
		
		if(count % 2 == 0){
			if(ans != 0) printf("Possible.\n");
			else printf("Impossible.\n");
		}
		else{
			if(ans == 0) printf("Possible.\n");
			else printf("Impossible.\n");
		}
	}
	
	return 0;
}
