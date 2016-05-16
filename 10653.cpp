#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define sc(a) scanf("%d", &a)
#define pr(a) printf("%d\n", a)
typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

int main()
{
	int r, c, br, bc, rm, cm;
	int m[1000][1000];
	bool v[1000][1000];
	ii s, e, a;
	int i, j;
	queue<ii> q;
	while(cin>>rm>>cm && cm != 0 && rm != 0)
	{
		memset(m, 0, sizeof m);
		memset(v, 0, sizeof v);
		cin>>br;
		fr(i,br){
			cin>>r>>bc;
			fr(j,bc){
				cin>>c;

				v[r][c] = 1;
			}
		}
		
		/*fr(i,rm){
			fr(j,cm)printf("%d ", v[i][j]);
			printf("\n");
		}*/
		
		cin>>r>>c;
		s = make_pair(r, c);
		cin>>r>>c;
		e = make_pair(r,c);
		
		while(!q.empty())q.pop();
		
		q.push(s);
		v[s.first][s.second] = 1;
		while(v[e.first][e.second] == 0){
			a = q.front();
			q.pop();
			if(a.first > 0 && v[a.first-1][a.second] == 0){
				m[a.first-1][a.second] = m[a.first][a.second] + 1;
				v[a.first-1][a.second] = 1;
				q.push(make_pair(a.first-1, a.second));
			}
			if(a.first < rm-1 && v[a.first+1][a.second] == 0) {
				m[a.first+1][a.second] = m[a.first][a.second] + 1;
				v[a.first+1][a.second] = 1;
				q.push(make_pair(a.first+1, a.second));
			}
			if(a.second > 0 && v[a.first][a.second-1] == 0){
				m[a.first][a.second-1] = m[a.first][a.second] + 1;
				v[a.first][a.second-1] = 1;
				q.push(make_pair(a.first, a.second-1));
			}
			if(a.second < cm-1 && v[a.first][a.second+1] == 0){
				 m[a.first][a.second+1] = m[a.first][a.second] + 1;
				 v[a.first][a.second+1] = 1;
				 q.push(make_pair(a.first, a.second+1));
			}
		}
		cout<<m[e.first][e.second]<<'\n';
	}
	return 0;
}
