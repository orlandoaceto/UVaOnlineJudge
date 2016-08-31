//1172 - The Bridges of Kolsberg
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

vector<string> northOS;
vector<string> southOS;
int nv[1001];
int sv[1001];
int nMax, sMax;
int memo[1000][1000];
int memoNum[1001][1001];

int go(int n, int s){
    if(s == sMax || n == nMax) return 0;
    if(~memo[n][s]) return memo[n][s];
    int ans = go(n+1, s);
    int num = memoNum[n+1][s];
    
    int aux = go(n, s+1);
    if(aux > ans || (aux == ans && memoNum[n][s+1] < num)){
    	ans = aux;
    	num = memoNum[n][s+1];
    }
    
    if(northOS[n] == southOS[s]){
    	aux = nv[n] + sv[s] + go(n+1, s+1);
    	if(aux > ans || (aux == ans && memoNum[n+1][s+1] + 1 < num)){
    		ans = aux;
    		num = 1 + memoNum[n+1][s+1];
    	}
    }
   
    memoNum[n][s] = num;
    return memo[n][s] = ans;
}


int main(){
    int t, k, i, j;
    string a;
   
    sc(t);
   
    while(t--){
        sc(nMax);
        northOS.resize(nMax);
        fr(i,nMax){
            cin>>a;
            cin>>northOS[i];
            sc(nv[i]);
        }
        sc(sMax);
        southOS.resize(sMax);
        fr(i,sMax){
            cin>>a;
            cin>>southOS[i];
            sc(sv[i]);
        }

        memset(memoNum, 0, sizeof memoNum);
        memset(memo, -1, sizeof memo);
        printf("%d ", go(0,0));
        printf("%d\n", memoNum[0][0]);
    }
   
    return 0;
}
