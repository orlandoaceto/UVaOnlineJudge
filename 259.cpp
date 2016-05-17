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
#define INF 1000000000

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

int res[38][38], mf, f, s, t; // global variables
vi p;

void augment(int v, int minEdge) {
  	if (v == s){ 
  		f = minEdge;
  		return; 
  	}
	else if (p[v] != -1){ 
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f; res[v][p[v]] += f;
	}
}

int main(){
	char ap, c;
	int n, i, j;
	int V, k, vertex, weight;
	int num;
	bool last = 0;
	vector<bool> vis;
	
	while(1){
		memset(res, 0, sizeof res);
		s = 0; t = 37;
		num = 0;
		
		while(1){
			if(!(scanf("%c", &ap) > 0)){
				last = 1;
				break;
			}
			if(ap == '\n')break;
			scanf("%d ", &n);
			num += n;
			res[0][ap-'A'+1] = n;
			do{
				scanf("%c", &c);
				if(c == ';')break;
				res[c-'0'+27][37] = 1;
				res[ap-'A'+1][c-'0'+27] = INF;
			}while(c != ';');
			scanf("%c", &ap);
		}
		mf = 0;
		while(1){
			f = 0;
			p.assign(40, -1);
			vis.assign(40, false);
			vis[s] = true;
			queue<int> q;
			q.push(s);
			while(!q.empty()){
				int u = q.front(); q.pop();
				if(u == t) break;
				for(int v = 0; v < 38;v++){
					if(res[u][v] > 0 && !vis[v]){
						vis[v] = true;
						q.push(v);
						p[v] = u;
					}
				}
			}
			augment(t, INF);
			if(f == 0) break;
			mf += f;
		}
		
		if(num == 0)break;
		if(num != mf)printf("!\n");
		else{
			for(i = 27; i <= 36; i++){
				bool flag = 0;
				for(j = 1; j <= 26; j++){
					if(res[i][j]){
						printf("%c", (char)j+'A'-1);
						flag = 1;
					}
				}
				if(!flag) printf("_");
			} 
			printf("\n");
		}
		if(last) break;
	}

	return 0;
}
