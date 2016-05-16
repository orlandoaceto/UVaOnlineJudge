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
	map<string, int> m;
	int p, r;
	int adjMat[60][60];
	string s1, s2;
	int n1, n2, n;
	int i, j, k, c = 1;
	
	while(cin>>p>>r && p > 0 && r > 0){
		n = 1;
		fr(i,p)fr(j,p)adjMat[i+1][j+1] = 100;
		m.clear();
		
		fr(i,r){
		
			cin>>s1>>s2;
			
			n1 = m[s1];
			if(!n1){
				m[s1] = n++;
				n1 = n-1;
			}
			n2 = m[s2];
			if(!n2){
				m[s2] = n++;
				n2 = n-1;
			}
			
			adjMat[n1][n2] = 1;
			adjMat[n2][n1] = 1;
		}
		
		fr(i,n)adjMat[i+1][i+1] = 0;
		
		fr(k,p)fr(i,p)fr(j,p)adjMat[i+1][j+1] = min(adjMat[i+1][j+1], adjMat[i+1][k+1] + adjMat[k+1][j+1]);
		
		int maxi = 0;
		fr(i,p)fr(j,p)maxi = max(maxi, adjMat[i+1][j+1]);
		
		/*fr(i,p){
			fr(j,p)printf("%3d ", adjMat[i+1][j+1]);
			cout<<'\n';
		}*/
		
		printf("Network %d: ", c++);
		if(maxi >= 100)printf("DISCONNECTED\n\n");
		else printf("%d\n\n", maxi);
		
	}
	
	return 0;
}
