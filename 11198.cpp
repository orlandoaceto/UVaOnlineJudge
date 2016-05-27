//11198 - Dancing Digits
//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

/*
The solution is a complete search using BFS. For every new vector taken from the queue,
try all valid moves and check if they have already been previously enqued (a set or map
is necessary for that).
*/

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
#define pb push_back
#define clr(a) memset(a, 0, sizeof a);

const int oo = 0x3f3f3f3f;

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

bool cmp(int a, int b){
	return abs(a) < abs(b);
}

int main(){
	bool isP[16] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0};
	vi v(8, 0), sorted, aux;
	int k, i, j, cost;
	queue<pair<vi, int> > q;
	set<vi> s;
		
	k = 1;
	while(k++){
		fr(i,8){
			sc(v[i]);
			if(v[i] == 0) break;
		}
		if(v[0] == 0) break;
		printf("Case %d: ", k-1);
		
		sorted = v;
		sort(sorted.begin(), sorted.end(), cmp);
		
		q = queue<pair<vi, int> >();
		q.push(p(v, 0));
		s.clear();
		s.insert(v);
		
		bool found = 0;
		while(!q.empty()){
			v = q.front().first;
			cost = q.front().second;
			if(v == sorted){
				found = 1;
				break;
			}
			q.pop();
			fr(i,8){
				aux = v;
				for(j = i+1; j < 8; j++){
					swap(aux[j-1],aux[j]);
					if((j > 0 && isP[abs(aux[j]) + abs(aux[j-1])] && (double)aux[j]/aux[j-1] < 0) || (j < 7 && isP[abs(aux[j]) + abs(aux[j+1])] && (double)aux[j]/aux[j+1] < 0)){
						if(s.find(aux) == s.end()){
							s.insert(aux);
							q.push(p(aux, cost+1));
						}
					}
				}
				aux = v;
				for(j = i-1; j >= 0; j--){
					swap(aux[j+1],aux[j]);
					if((j > 0 && isP[abs(aux[j]) + abs(aux[j-1])] && (double)aux[j]/aux[j-1] < 0) || (j < 7 && isP[abs(aux[j]) + abs(aux[j+1])] && (double)aux[j]/aux[j+1] < 0)){
						if(s.find(aux) == s.end()){
							s.insert(aux);
							q.push(p(aux, cost+1));
						}
					}
				}
			}
			
		}
		if(found){
			printf("%d\n", cost);
		}
		else{
			printf("-1\n");
		}
	}
	
	return 0;
}
