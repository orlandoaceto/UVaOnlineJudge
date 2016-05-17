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
	int n, m, s;
	int i, j, k;
	char map[100][100];
	bool taken[100][100];
	ii pos;
	char lado, com;
	int facing;


	while(scanf("%d %d %d\n", &n, &m, &s) > 0){
		if(n == 0 && m == 0 && s == 0) break;
		fr(i,n){
			fr(j,m){
				scanf("%c", &map[i][j]);
				if(map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'L' || map[i][j] == 'O'){
					pos = p(i, j);
					lado = map[i][j];
				}
			}
			scanf("\n");
		}
		memset(taken, 0, sizeof taken);
		
		
		if(lado == 'N') facing = 0;
		else if(lado == 'S') facing = 2;
		else if(lado == 'L') facing = 1;
		else if(lado == 'O') facing = 3;
		
		int qtd = 0;
		fr(k,s){
			scanf("%c", &com);
			if(com == 'D'){
				facing = (facing + 1)%4;
			}
			if(com == 'E'){
				facing = (facing + 3)%4;
			}
			if(com == 'F'){
				if(facing == 0){
					if(pos.fi > 0 && map[pos.fi-1][pos.se] != '#') pos.fi--;
				}
				else if(facing == 1){
					if(pos.se < m-1 && map[pos.fi][pos.se+1] != '#') pos.se++;
				}
				else if(facing == 2){
					if(pos.fi < n-1 && map[pos.fi+1][pos.se] != '#') pos.fi++;
				}
				else if(facing == 3){
					if(pos.se > 0 && map[pos.fi][pos.se-1] != '#') pos.se--;
				}
			}
			if(map[pos.fi][pos.se] == '*' && !taken[pos.fi][pos.se]){
				taken[pos.fi][pos.se] = 1;
				qtd++;
			}
		}
		scanf("\n");
		printf("%d\n", qtd);
		
	}

	return 0;
}
