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
	queue<ii> l, r;
	int ans[10000];
	int c, n, t, m;
	int at, pos, i, read, qtd;
	string in;
	ii el;
	bool flag;
	
	sc(c);
	
	while(c--){
		scanf("%d %d %d", &n, &t, &m);
		fr(i,m){
			scanf("%d", &read);
			cin>>in;
			if(in == "right") r.push(ii(read,i));
			else if(in == "left") l.push(ii(read, i));
			else return -1;
		}
		at = 0;
		pos = 1;		
		while(!r.empty() || !l.empty()){
			if(pos == 1){
				flag = 0;
				qtd = 0;
				while(!l.empty() && l.front().fi <= at && qtd < n){
					flag = 1;
					el = l.front();
					l.pop();
					ans[el.se] = at + t;
					qtd++;
				}
				if(flag || (!r.empty() && r.front().fi <= at)){
					pos = 2;
					at += t;
				}
				else{
					int rf = INT_MAX;
					if(!r.empty()) rf = r.front().fi;
					int lf = INT_MAX;
					if(!l.empty()) lf = l.front().fi;
					at = min(rf, lf);
				}
			}
			else{
				flag = 0;
				qtd = 0;
				while(!r.empty() && r.front().fi <= at && qtd < n){
					flag = 1;
					el = r.front();
					r.pop();
					ans[el.se] = at + t;
					qtd++;
				}
				if(flag || (!l.empty() && l.front().fi <= at)){
					pos = 1;
					at += t;
				}
				else{
					int rf = INT_MAX;
					if(!r.empty()) rf = r.front().fi;
					int lf = INT_MAX;
					if(!l.empty()) lf = l.front().fi;
					at = min(rf, lf);
				}
				
			}
		}
		fr(i,m) pr(ans[i]);
		
		if(c > 0)printf("\n");
		
	}		

	return 0;
}
