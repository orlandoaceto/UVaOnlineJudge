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
	int n, q;
	vector<string> v(101, "");
	int i, j, k, l;
	int a, b;
	scanf("%d\n\n", &n);
	int cha[256];
	bool flag = 0;
	
	for(l = 0; l < n; l++){
		if(l > 0)printf("\n");
		q = 0;
		while(getline(cin, v[q++]) && v[q-1].size() > 0);
		q--;
		sort(v.begin(), v.begin()+q);
		scanf("\n");
		
		fr(i,q)for(j = i+1; j < q; j++){
			memset(cha, 0, sizeof cha);
			for(k = 0; k < v[i].size();k++){
				if(v[i][k] != ' ')
				cha[v[i][k]]++;
			}
			for(k = 0; k < v[j].size();k++){
				if(v[j][k] != ' ')
				cha[v[j][k]]--;
			}
			flag = 1;
			fr(k,256)if(cha[k] != 0) flag = 0;
			if(flag == 1)
			cout<<v[i]<<" = "<<v[j]<<'\n';
		}
	}
	
	return 0;
}
