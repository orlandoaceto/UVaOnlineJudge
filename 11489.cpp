//UVa 11489 - Integer Game
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
	ios_base::sync_with_stdio(false);
	int freq[10];
	string s;
	int t, k, i;
	int moves, total;
	char winner;
	
	cin>>t;
	
	fr1(k,t){
		cin>>s;
		memset(freq, 0, sizeof freq);
		total = 0;
		fr(i,s.size()){
			freq[s[i]-'0']++;
		}
		fr(i,10) total += freq[i]*i;
		
		moves = freq[3] + freq[6] + freq[9];
		
		if(total % 3 == 1){
			if(freq[1] > 0 || freq[4] > 0 || freq[7] > 0) moves++;
			else moves = 0;
		}
		else if(total % 3 == 2){
			if(freq[2] > 0 || freq[5] > 0 || freq[8] > 0) moves++;
			else moves = 0;
		}
		
		if(moves % 2 == 1){
			winner = 'S';
		}
		else{
			winner = 'T';
		}
		
		cout<<"Case "<<k<<": "<<winner<<'\n';
	}
	
	return 0;
}
