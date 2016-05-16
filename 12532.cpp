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
		int n;
		
		int left(int p){ return p << 1; }
		int right(int p){ return (p << 1) + 1; }
		
		void build(int p, int L, int R){
			if(L == R) st[p] = A[L];
			else{
				build(left(p), L, (L+R)/ 2);
				build(right(p), (L+R)/2 + 1, R);
				int p1 = st[left(p)], p2 = st[right(p)];
				st[p] = p1 * p2;
			}
			
		}
		
		int rmq(int p, int L, int R, int i, int j){
			if(i > R || j < L) return -2;
			if(L >= i && R <= j) return st[p];
			
			int p1 = rmq(left(p), L, (L+R)/2, i, j);
			int p2 = rmq(right(p), (L+R)/2 +1, R, i, j);
			
			if(p1 == -2) return p2;
			if(p2 == -2) return p1;
			return p1 * p2;
		}

		int update_point(int p, int L, int R, int idx, int new_value){
			int i = idx, j = idx;
			
			if(i > R || j < L)
				return st[p];
				
			if(L == i && R == j){
				A[i] = new_value;
				return st[p] = A[i];
			}
			
			int p1, p2;
			p1 = update_point(left(p), L, (L+R)/2, idx, new_value);
			p2 = update_point(right(p), (L+R)/2 +1, R, idx, new_value);
			
			return st[p] = p1 * p2;	
		}
		
	public:
		SegmentTree(const vector<int> &_A){
			A = _A; n = (int)A.size();
			st.assign(4 * n, 0);
			build(1, 0, n-1);
		}
		
		int rmq(int i, int j){
			return rmq(1, 0, n-1, i, j);
		}
		
		int update_point(int idx, int new_value){
			return update_point(1, 0 , n-1, idx, new_value);
		}
};


int main(){
	vi v;
	int n, k;
	int i, j, l;
	char cm;
	int val;
	while(scanf("%d %d", &n, &k) > 0){
		v.resize(n);
		fr(i, n){
			sc(v[i]);
			if(v[i] < 0) v[i] = -1;
			else if(v[i] > 0) v[i] = 1;
		}
		
		/*fr(i,n){
			printf("%d ", v[i]);
		}
		printf("\n");*/
		
		scanf("\n");
		SegmentTree st(v);
		
		fr(l, k){
			scanf("%c ", &cm);
			if(cm == 'C'){
				scanf("%d %d\n", &i, &val);
				if(val < 0) val = -1;
				else if(val > 0) val = 1;
				
				st.update_point(i-1, val);
				
			}
			else{
				scanf("%d %d\n", &i, &j);
				
				int res = st.rmq(i-1, j-1);
				if(res == -1) printf("-");
				else if(res == 0)printf("0");
				else if(res == 1) printf("+");
				else {
					printf("Error %d\n", res);
					return -1;
				}
			}
		}
		printf("\n");
			
	}
	return 0;
}
