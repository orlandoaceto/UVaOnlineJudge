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

class SegmentTree{
	private: 
		vi st, A;
		vector<char> lp;
		int n;
		
		inline int left(int p){ return p << 1; }
		inline int right(int p){ return (p << 1) | 1; }
		
		void build(int p, int L, int R){
			if(L == R) st[p] = A[L];
			else{
				build(left(p), L, (L+R)/ 2);
				build(right(p), (L+R)/2 + 1, R);
				int p1 = st[left(p)], p2 = st[right(p)];
				st[p] = p1 + p2;
			}
			
		}
		
		int rmq(int p, int L, int R, int i, int j){
			if(i > R || j < L) return -1;
			
			if(lp[p] != 'N'){
				if(lp[p] == 'S')
					st[p] = R-L+1;
				else if(lp[p] == 'C')
					st[p] = 0;
				else if(lp[p] == 'R')
					st[p] = (R-L+1) - st[p];
					
				if(L != R){
					if(lp[p] == 'S' || lp[p] == 'C'){
						lp[right(p)] = lp[p];
						lp[left(p)] = lp[p];
					}
					else if(lp[p] == 'R'){
						int rig = right(p);
						int lef = left(p);
						if(lp[rig] == 'N') lp[rig] = 'R';
						else if(lp[rig] == 'R') lp[rig] = 'N';
						else if(lp[rig] == 'S') lp[rig] = 'C';
						else if(lp[rig] == 'C') lp[rig] = 'S';
						
						if(lp[lef] == 'N') lp[lef] = 'R';
						else if(lp[lef] == 'R') lp[lef] = 'N';
						else if(lp[lef] == 'S') lp[lef] = 'C';
						else if(lp[lef] == 'C') lp[lef] = 'S';
					}
				}
				lp[p] = 'N';
					
			}
			if(L == R) return st[p];
			if(L >= i && R <= j) return st[p];
			
			int p1 = rmq(left(p), L, (L+R)>>1, i, j);
			int p2 = rmq(right(p), ((L+R)>>1) +1, R, i, j);
			
			if(p1 == -1) return p2;
			if(p2 == -1) return p1;
			return p1 + p2;
		}
		
		int update(int p, int L, int R, int i, int j, int code){
			//printf("%d %d - %d %d\n", L, R, i, j);
			
			if(L >= i && R <= j){
				if(code == -1){
					if(lp[p] ==	 'R') lp[p] = 'N';
					else if(lp[p] == 'S') lp[p] = 'C';
					else if(lp[p] == 'C') lp[p] = 'S';
					else if(lp[p] == 'N') lp[p] = 'R';
				}
				else if(code == 1) lp[p] = 'S';
				else if(code == 0) lp[p] = 'C';
			}
			
			if(lp[p] != 'N'){
				if(lp[p] == 'S') st[p] = R-L+1;
				else if(lp[p] == 'C') st[p] = 0;
				else if(lp[p] == 'R') st[p] = (R-L+1) - st[p];
				
				if(L != R){
					if(lp[p] == 'S' || lp[p] == 'C'){
						lp[right(p)] = lp[p];
						lp[left(p)] = lp[p];
					}
					else if(lp[p] == 'R'){
						int rig = right(p);
						int lef = left(p);
						if(lp[rig] == 'N') lp[rig] = 'R';
						else if(lp[rig] == 'R') lp[rig] = 'N';
						else if(lp[rig] == 'S') lp[rig] = 'C';
						else if(lp[rig] == 'C') lp[rig] = 'S';
						
						if(lp[lef] == 'N') lp[lef] = 'R';
						else if(lp[lef] == 'R') lp[lef] = 'N';
						else if(lp[lef] == 'S') lp[lef] = 'C';
						else if(lp[lef] == 'C') lp[lef] = 'S';
					}
				}
				lp[p] = 'N';
			}
			if(i > R || j < L) return st[p];
			if(L >= i && R <= j) return st[p];
			if(L == R){
				return st[p];
			}
			
			int p1 = update(left(p), L, (L+R)/2, i, j, code);
			int p2 = update(right(p), ((L+R)/2)+1, R, i, j, code);
			if(p1 == -1) return p2;
			if(p2 == -1) return p1;
			return st[p] = p1 + p2;
		}
		
		
	public:
		SegmentTree(const vector<int> &_A){
			A = _A; n = (int)A.size();
			st.assign(4 * n, 0);
			lp.assign(4 * n, 'N');
			build(1, 0, n-1);
		}
		
		int rsq(int i, int j){
			return rmq(1, 0, n-1, i, j);
		}
		
		int update(int i, int j, int val){
			return update(1, 0, n-1, i, j, val);
		}
};



int main(){
	vi v;
	int t, n, m, size, times;
	int i, j, k;
	string s;
	char cm;
	int a, b, qn, cn = 1;
	
	sc(t);
	fr1(k,t){
		v.clear();
		sc(m);
		fr(i,m){
			sc(n);
			cin>>s;
			size = s.size();
			times = size * n;
			for(j= 0; j < times; j++){
				v.push_back(s[j % size]-'0');
			}
		}
		//for(int a : v) cout<<a<<' ';
		//cout<<'\n';
		
		SegmentTree sg(v);
		printf("Case %d:\n", cn++);
		scanf("%d\n", &n);
		qn = 1;
		fr(i,n){
			scanf("%c %d %d\n", &cm, &a, &b);
			//printf("%c %d %d\n", cm, a, b);
			if(cm == 'F') sg.update(a, b, 1);
			else if(cm == 'E') sg.update(a, b, 0);
			else if(cm == 'I') sg.update(a, b, -1);
			else if(cm == 'S') printf("Q%d: %d\n", qn++, sg.rsq(a, b));
			else{
				printf("Error\n");
				return 0;
			}
		}
	}
	
	
}
