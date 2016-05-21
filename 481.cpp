//481 - What Goes Up
//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

/*
The problem is simply to find LIS (classical dynamic program problem)
(I tried to make this solution as concise as possible. This might make it
easier to understand for some, but harder to understand for others, I hope
it's useful to you!)
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
	vi v;//Stores input
	vi sv;//sv[i] stores smallest last value of each LIS of length i+1
	vi index;//Since sv stores values(due to binary searches), it's necessary to have another vector for indexes
	vi parent;//parent[i] stores value of parent of v[i] if it has one
	
	int aux;
	while(sc(aux) > 0) v.pb(aux);//Reads input until EOF and puts in vector v
	
	parent.resize(v.size());//Prepares parent vector
	
	vi::iterator it;
	for(int i = 0; i < v.size(); i++){
		it = lower_bound(sv.begin(), sv.end(), v[i]);
		if(it == sv.end()){
			if(!sv.empty()) parent[i] = *index.rbegin();//v[i] is larger than every value before it so the parent
			sv.pb(v[i]);								//is the last element of the largest LIS so far
			index.pb(i);
		}
		else{
			if(it != sv.begin()) parent[i] = index[it-sv.begin()-1];
			*it = v[i];
			index[it-sv.begin()] = i;
		}
	}
	
	int curr = *index.rbegin();//Index of current element being added to LIS (starts with rbegin since it's the last
	stack<int> LIS;            //value of the largest LIS)
	int len = sv.size();       //Used to tell when to stop trying to stack elements(only needed if you can't represent a
	while(len){                //null parent, for example, using value 0 and not having any elements with index 0)
		LIS.push(v[curr]);//Stores LIS in stack
		curr = parent[curr];
		len--;
	}
	
	printf("%d\n-\n", (int)sv.size());
	while(!LIS.empty())printf("%d\n", LIS.top()),LIS.pop();//Prints stack from top
	
}
