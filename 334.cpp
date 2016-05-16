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
	
	int nc, ne, nm, c = 1;
	int i, j, k;
	bool adjMat[1000][1000];
	int diffNames, ant, num;
	map<string, int> m;
	map<string, int>::iterator it; 
	map<string, int>::iterator it2;
	string in, in2;
	
	while(cin>>nc && nc > 0){
		diffNames = 0;
		m.clear();
		memset(adjMat, 0, sizeof adjMat);
		fr(i, nc){
			cin>>ne;
			fr(j,ne){
				cin>>in;
				if(!m[in])m[in] = diffNames++;
				if(j > 0)adjMat[ant][m[in]] = 1;
				ant = m[in];
			}
		}
		cin>>nm;
		fr(i,nm){
			cin>>in>>in2;
			adjMat[m[in]][m[in2]] = 1;
		}
		
		fr(k, diffNames)fr(i, diffNames)fr(j,diffNames)adjMat[i][j] |= (adjMat[i][k] & adjMat[k][j]);
		
		num = 0;
		for(it = m.begin();it != m.end(); it++){
			for(it2 = next(it,1);it2 != m.end(); it2++){
				if(adjMat[it->second][it2->second] == 0 && adjMat[it2->second][it->second] == 0){
					num++;
					if(num == 1)in = "("+it->first+","+it2->first+") ";
					else if(num == 2)in2 = "("+it->first+","+it2->first+") ";
				}
			}
		}
		
		
		printf("Case %d, ", c++);
		if(num > 0)printf("%d concurrent events:\n", num);
		else printf("no concurrent events.");
		
		if(num >= 1)cout<<in;
		if(num >= 2)cout<<in2;
		
		cout<<'\n';
		
	}
	return 0;
}
