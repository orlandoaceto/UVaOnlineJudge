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

int dr[] = {1,-1, 0, 0};
int dl[] = {0, 0, 1,-1};
int n, m;
char ma[100][100];

int floodFill(int i, int j, char c1, char c2){
	int k;
	
	if(i < 0 || i >= m || j < 0 || j >= n) return 0;
	if(ma[i][j] != c1) return 0;
	
	int ans = 1;
	ma[i][j] = c2;
	fr(k,4){
		ans += floodFill(i+dr[k], (j+dl[k]+n)%n, c1, c2);
	}
	
	return ans;
}


int main(){
	int i, j;
	int maxi;
	int x, y;
	char land, water;
	
	
	while(scanf("%d %d\n", &m, &n) > 0){
		fr(i,m){
			fr(j,n){
				scanf("%c", &ma[i][j]);
			}
			scanf("\n");
		}
		
		scanf("%d %d", &x, &y);
		land = ma[x][y];
		water = land-1;
		fr(i,n)fr(j,n)if(ma[i][j] != land){
			water = ma[i][j];
			break;
		}
		
		floodFill(x, y, land, water);
		maxi = 0;
		fr(i,m){
			fr(j,n){
				//printf("%c", ma[i][j]);
				maxi = max(maxi, floodFill(i, j, land, water));
			}
			//printf("\n");
		}
		printf("%d\n", maxi);
	}
	

	return 0;
}
