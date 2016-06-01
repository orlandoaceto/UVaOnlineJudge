//10557 - XYZZY
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

const int oo = 0x3f3f3f3f;

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

int main(){
	int n, i, j, k, num, aux;
	vector<vi> adjList;
	vi energy;
	vi dist;
	vector<bool> possibleInf;
	bool hasCycle;
	
	while(cin>>n){
		if(n == -1) break;
		energy.resize(n+1);
		dist.assign(n+1, 0);
		possibleInf.assign(n+1, 0);
		dist[1] = 100;
		adjList.assign(n+1, vi());
		
		fr1(i,n){
			scanf("%d %d", &energy[i], &num);
			fr(j,num){
				scanf("%d", &aux);
				adjList[i].pb(aux); 
			}
		}
		
		fr(i,n-1){
			fr1(j,n){
				fr(k,adjList[j].size()){
					int src = j;
					int dest = adjList[j][k];
					if(dist[src] > 0 && dist[src] + energy[dest] > dist[dest]){
						dist[dest] = dist[src] + energy[dest];
					}
				}
			}
		}
		if(dist[n] > 0){
			printf("winnable\n");
			continue;
		}
		else{
			fr1(j,n){
				fr(k,adjList[j].size()){
					int src = j;
					int dest = adjList[j][k];
					if(dist[src] > 0 && dist[src] + energy[dest] > dist[dest]){
						possibleInf[src] = 1;
						possibleInf[dest] = 1;
						hasCycle = 1;
					}
				}
			}
			if(!hasCycle){
				printf("hopeless\n");
				continue;
			}
			else{
				fr(i,n-1){
					fr1(j,n){
						fr(k,adjList[j].size()){
							int src = j;
							int dest = adjList[j][k];
							if(possibleInf[src]){
								possibleInf[dest] = 1;;
							}
						}
					}
				}
				
				if(possibleInf[n] == 1) printf("winnable\n");
				else printf("hopeless\n");
			}
		}
	}
	return 0;
}
