//599 - The Forrest for the Trees
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
#define pb push_back
#define clr(a) memset(a, 0, sizeof a);
#define setInf(a) memset(a, 0x3f, a);

const int oo = 0x3f3f3f3f;

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

int main(){
	vector<vi> adjList;
	bool v[26];
	int trees, acorn, t;
	char a, b, f;
	queue<int> q;
	int i, j;
	
	scanf("%d\n", &t);
	
	
	while(t--){
		trees = 0;
		acorn = 0;
		clr(v);
		adjList.assign(26, vi());
		
		while(scanf(" %c", &f)){
			if(f == '*') break;
			scanf("%c,%c)\n", &a, &b);
			adjList[a-'A'].pb(b-'A');
			adjList[b-'A'].pb(a-'A');
			v[a-'A'] = 1;
			v[b-'A'] = 1;
		}
		while(scanf("%c", &f)){
			if(f == '\n') break;
		}
		
		do{
			scanf("%c", &f);
			if(!v[f-'A']) acorn++;
			scanf("%c", &f);
		}while(f == ',');
		
		fr(i,26){
			if(v[i]){
				trees++;
				q.push(i);
				while(!q.empty()){
					int vert = q.front();
					v[vert] = 0;
					q.pop();
					fr(j, (int)adjList[vert].size()){
						if(v[adjList[vert][j]]){
							q.push(adjList[vert][j]);
						}
					}
				}
			}
		}
		
		printf("There are %d tree(s) and %d acorn(s).\n", trees, acorn);
		
	}
	
	return 0;
}
