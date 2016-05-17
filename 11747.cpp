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
#define fi first
#define se second

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

class UnionFind{
	private: 
	vi p, rank, setSize;
	int numSets;	
	
	public:
	UnionFind(int N){
		numSets = 0;
		setSize.assign(N, 1);
		rank.assign(N, 0);
		p.assign(N, 0);
		for(int i = 0; i < N; i++) p[i] = i;
	}
	int findSet(int i){
		return(p[i] == i)? i: (p[i] = findSet(p[i]));
	}
	bool isSameSet(int i, int j){
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j){
		if (!isSameSet(i, j)){
			numSets--;
			int x = findSet(i), y = findSet(j);
			if(rank[x] > rank[y]){ p[y] = x; setSize[x] += setSize[y]; }
			else { p[x] = y; setSize[y] += setSize[x]; }
			if(rank[x] == rank[y]) rank[y]++;
		}
	}
	int numDisjointSets(){
		return numSets;
	}
	int sizeOfSet(int i){
		return setSize[findSet(i)];
	}
};


int main(){
	int n, m;
	int v1, v2, w;
	vector<pair<int,ii> > edgeList;
	int i, j;
	vi ans;
	
	while(scanf("%d %d", &n, &m) > 0 && (n > 0 || m > 0)){
		edgeList.clear();
		ans.clear();
		fr(i,m){
			scanf("%d %d %d", &v1, &v2, &w);
			edgeList.push_back(make_pair(w, ii(v1, v2)));
		}
		
		sort(edgeList.begin(), edgeList.end());
		UnionFind uf(n);
		fr(i,m){
			pair<int, ii> front = edgeList[i];
			if(!uf.isSameSet(front.second.first, front.second.second)){
				uf.unionSet(front.second.first, front.second.second);
			}
			else ans.push_back(front.first);
		}
		if(ans.empty())printf("forest\n");
		else{
			printf("%d", ans[0]);
			for(i=1; i < ans.size(); i++) printf(" %d", ans[i]);
			printf("\n");
		}
		
	}

}
