#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(int a = 0; a < n; a++)
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


class UnionFind{
	private: 
	vi p, rank, setSize;
	int numSets;	
	
	public:
	UnionFind(int N){
		numSets = N;
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
			else{ 
				p[x] = y; setSize[y] += setSize[x];
				if(rank[x] == rank[y]) rank[y]++;
			}
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
	
	int n, m, awake;
	char a,b,c;
	int prev;
	vii con;
	map<char,int> Map; 
	int ind, count;
	vi nCon;
	
	while(scanf(" %d\n%d\n", &n, &m) > 0){
		scanf("%c%c%c\n", &a, &b, &c);
		if(n == 3){
			printf("WAKE UP IN, 0, YEARS\n");
			continue;
		}
		Map.clear();
		UnionFind uf(n);
		con.clear();
		ind = 0;
		if(Map.find(a) == Map.end())Map[a] = ind++;
		if(Map.find(b) == Map.end())Map[b] = ind++;
		if(Map.find(c) == Map.end())Map[c] = ind++;
			
		uf.unionSet(Map[a], Map[b]);
		uf.unionSet(Map[b], Map[c]);
		awake = uf.findSet(Map[a]);
		fr(i, m){
			scanf("%c%c\n", &a, &b);
			if(Map.find(a) == Map.end()){
				Map[a] = ind++;
			}
			if(Map.find(b) == Map.end()){
				Map[b] = ind++;
			}
			con.push_back(make_pair(Map[a], Map[b]));
		}
		count = 0;
		while(1){
			nCon.assign(n, 0);
			prev = uf.sizeOfSet(uf.findSet(awake));
			fr(i, m){
				if((uf.findSet(con[i].fi) == uf.findSet(awake)) && (uf.findSet(con[i].se) != uf.findSet(awake))){
					nCon[uf.findSet(con[i].se)]++;
				}
				else if((uf.findSet(con[i].fi) != uf.findSet(awake)) && (uf.findSet(con[i].se) == uf.findSet(awake))){
					nCon[uf.findSet(con[i].fi)]++;
				}
			}
			fr(i,n){
				if(nCon[i] >= 3){
					uf.unionSet(i, uf.findSet(awake));
				}
			}
			count++;
			if(uf.sizeOfSet(uf.findSet(awake)) == prev){
				printf("THIS BRAIN NEVER WAKES UP\n");
				break;
			}
			if(uf.sizeOfSet(uf.findSet(awake)) == n){
				printf("WAKE UP IN, %d, YEARS\n", count);
				break;
			}
		}
	}
	

	return 0;
}
