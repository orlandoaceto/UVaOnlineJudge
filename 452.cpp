//452 - Project Scheduling
//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

/*
The graph given is a directed acyclic graph. Thus, you can generate a 
toposort of the graph and do the relax operations (subtitute cost if 
new cost is higher than old cost) in the order of the toposort
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

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

int main(){
	int t, n, i, j;
	vector<vi> adjList;
	vi num, cost, toposort, costPath;
	map<char,int> trans;
	char transBack[27];
	queue<int> q;
	char read, read2, pos;
	
	scanf("%d\n\n", &t);
	while(t--){
		pos = 1;
		adjList.assign(27, vi());
		num.assign(27, 0);
		cost.assign(27, 0);
		trans.clear();
		clr(transBack);
		while(1){//Reading input
			if(!(scanf("%c", &read) > 0) || read == '\n') break;
			if(trans.find(read) == trans.end()){
				trans[read] = pos++;
				transBack[pos-1] = read;
			}
			scanf(" %d", &n);
			cost[trans[read]] = n;
			scanf("%c", &read2);
			if(read2 == '\n') continue;
			while(1){
				if(!(scanf("%c", &read2) > 0) || read2 == '\n') break;
				if(trans.find(read2) == trans.end()){
					trans[read2] = pos++;
					transBack[pos-1] = read2;
				}
				adjList[trans[read2]].pb(trans[read]);
				num[trans[read]]++;
			}
		}
		
		
		num.resize(pos);
		cost.resize(pos);
		adjList.resize(pos);
		costPath.assign(pos, 0);
		pos--;
		
		fr1(i,pos) if(num[i] == 0) q.push(i);
		
		toposort.clear();
		while(!q.empty()){//Kahn's Algorithm for toposort
			int front = q.front();
			toposort.pb(front);
			q.pop();
			
			fr(i,adjList[front].size()){
				num[adjList[front][i]]--;
				if(num[adjList[front][i]] == 0){
					q.push(adjList[front][i]);
				}
			}
		}
		
		fr1(i, toposort.size()){
			fr(j,adjList[i].size()){
				if(cost[i] + costPath[i] > costPath[adjList[i][j]]){
					costPath[adjList[i][j]] = cost[i] + costPath[i]; //Relaxing operation in toposort order
				}
			}
		}
		
		int ans = 0;
		fr1(i,pos){
			ans = max(ans, cost[i] + costPath[i]);//Cost to be able to start the project + cost to do the project, get highest sum
		}
		
		printf("%d\n", ans);
		
		if(t > 0)printf("\n");
	}
	
	
	return 0;
}
