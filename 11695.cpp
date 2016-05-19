//UVa 11695 - Flight Planning
//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish


/*
In summary, this problems asks you to, starting from a tree, delete one of the edges and then connect the 2 resulting trees
in a way that minimizes the diameter of the new tree. The edge to be deleted will be along the longest path of the original
tree (diameter). Once you've deleted a tree, it's easy to see the new connections will be made on the mid point of the diameter
of the 2 resulting trees, but it's much harder to see which edge will be removed from the original tree. Thus, since the problem
has a high time limit, you can try to remove every edge along the diameter of the original tree and then calculate the diameter
of the resulting tree if you connect the 2 midpoints of the diameter of each tree.
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

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

vector<vi> adjList;
vi diam;
vi dist;
int maxDist, maxV;

void findDist(int a){
	if(dist[a] > maxDist){
		maxDist = dist[a];
		maxV = a;
	}
	int i;
	fr(i, adjList[a].size()){
		if(dist[adjList[a][i]] == -1){
			dist[adjList[a][i]] = dist[a] + 1;
			findDist(adjList[a][i]);
		}
	}
}

bool findDiam(int v1, int v2){
	dist[v1] = 1;
	bool f = 0;
	int i;
	
	if(v1 == v2){
		diam.pb(v1);
		return 1;
	}
	
	fr(i, adjList[v1].size()){
		if(dist[adjList[v1][i]] == -1)
			f = findDiam(adjList[v1][i], v2);
		if(f == 1){
			diam.pb(v1);
			break;
		}
	}
	
	return f;
}


int main(){
	int t, n, i;
	int v1, v2;
	int c1, c2, n1, n2;
	int ansBest;
	int ansC1, ansC2, ansN1, ansN2;
	int depth1, depth2, ext11, ext12, ext21, ext22;
	int diamLen1, diamLen2;
	vi diam1, diam2;
	vi treeDiam;
		
	scanf("%d\n", &t);
	
	while(t--){
		scanf("%d", &n);
		adjList.assign(n+1, vi());
		fr(i, n-1){
			scanf("%d %d", &v1, &v2);
			adjList[v1].pb(v2);
			adjList[v2].pb(v1);
		}
		dist.assign(n+1, -1);
		dist[1] = 0;
		maxDist = -1;
		findDist(1);
		v1 = maxV;
		dist.assign(n+1, -1);
		dist[v1] = 0;
		maxDist = -1;
		findDist(v1);
		v2 = maxV;
		
		//v1 and v2 now hold 2 extreme points of the tree diameter		
		dist.assign(n+1, -1);
		diam.clear();
		findDiam(v1, v2);//Finds diameter of the original tree
		treeDiam = diam;
		ansBest = 1000000;
		
		
		fr(i,treeDiam.size()-1){
			dist.assign(n+1, -1);//Marks 2 of the vertices as visited and gets furthest vertices from each of them
			c1 = treeDiam[i];    //The dge doesn't really have to be phisically removed, since you can block 
			c2 = treeDiam[i+1];  //Functions from computing information on both trees at once by marking the first
			dist[c1] = 0;        //node of the tree you don't want to visit as visited
			dist[c2] = 0;
			maxDist = -1;
			findDist(c1);
			ext12 = maxV;
			maxDist = -1;
			findDist(c2);
			ext22 = maxV;
			
			dist.assign(n+1, -1);
			dist[c2] = 0;
			dist[ext12] = 0;
			maxDist = -1;
			findDist(ext12);
			ext11 = maxV;
			
			dist.assign(n+1, -1);
			dist[c1] = 0;
			dist[ext22] = 0;
			maxDist = -1;
			findDist(ext22);
			ext21 = maxV;
			
			diam.clear();
			dist.assign(n+1, -1);
			findDiam(ext11, ext12);
			diam1 = diam;
			
			diam.clear();
			dist.assign(n+1, -1);
			findDiam(ext21, ext22);
			diam2 = diam;
			
			dist.assign(n+1, -1);
			dist[c2] = 0; //Effectivelly stops the tree connected to c2 from being processed in getDist
			maxDist = -1;
			n1 = diam1[diam1.size()/2];
			dist[n1] = 0;
			findDist(n1);
			depth1 = maxDist;
			
			dist.assign(n+1, -1);
			dist[c1] = 0;
			maxDist = -1;
			n2 = diam2[diam2.size()/2];
			dist[n2] = 0;
			findDist(n2);
			depth2 = maxDist;
			
			/*printf("(%d %d) (%d %d)\n", c1, c2, n1, n2);
			printf("(%d+%d+1) %d %d\n", depth1,depth2, (int)diam1.size()-1, (int)diam2.size()-1);
			*/
			maxDist = max(depth1+depth2+1, max((int)diam1.size()-1, (int)diam2.size()-1));
			//printf("%d\n", maxDist);
			if(maxDist < ansBest){
				ansBest = maxDist;
				ansC1 = c1;
				ansC2 = c2;
				ansN1 = n1;
				ansN2 = n2;
			}
		}
		
		
		printf("%d\n%d %d\n%d %d\n", ansBest, ansC1, ansC2, ansN1, ansN2);		
		
	}
	
	return 0;
}
