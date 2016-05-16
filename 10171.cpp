#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
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
	int n, i, j, k, e;
	int n1, n2;
	char a, b, x, y;
	int Y[26][26], M[26][26];
	int **po;
	int ene, s1, s2;
	vector<char> meet;
	
	while(scanf("%d\n", &n) > 0  && n > 0){
		
		fr(i,26)fr(j,26){
			Y[i][j] = 26 * 500 + 1;
			M[i][j] = 26 * 500 + 1;
		}
		
		fr(i,26){
			Y[i][i] = 0;
			M[i][i] = 0;
		}
		fr(i,n){
			scanf("%c %c %c %c %d\n", &a, &b, &x, &y, &e);
			n1 = x - 'A';
			n2 = y - 'A';
			if(a == 'Y')po =(int**) Y;
			else po = (int**)M;
			
			if(a == 'Y'){
				Y[n1][n2] = min(Y[n1][n2], e);
				if(b == 'B') Y[n2][n1] = min(Y[n2][n1], e);
			}
			else if(a == 'M'){
				M[n1][n2] = min(M[n1][n2], e);
				if(b == 'B') M[n2][n1] = min(M[n2][n1], e);
			}
		}
		
		fr(i,26)fr(j,26)fr(k,26){
			M[i][j] = min(M[i][j], M[i][k] + M[k][j]);
			Y[i][j] = min(Y[i][j], Y[i][k] + Y[k][j]);
		}
		
		
		scanf("%c %c\n", &x, &y);
		s1 = x-'A';
		s2 = y-'A';
		ene = 26 * 500 + 1;
		for(i = 0; i < 26; i++){
			if(Y[s1][i] + M[s2][i] < ene){
				meet.clear();
				ene = Y[s1][i] + M[s2][i];
				meet.push_back(i + 'A');
			}
			else if(Y[s1][i] + M[s2][i] == ene){
				meet.push_back(i + 'A');
			}
		}
		
		if(ene < 26 * 500 + 1){
			cout<<ene;
			fr(i,meet.size()){
				cout<<' '<<meet[i];
			}
			cout<<'\n';
		}
		else cout<<"You will never meet.\n";
	}
	return 0;
}
