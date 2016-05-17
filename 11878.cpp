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

int main(){
	string in;
	int a, b, c;
	int i, count = 0;
	bool minus;
	while(getline(cin, in)){
		if(in.size() == 0)break;
		a = 0;
		b = 0;
		c = 0;
		i = 0;
		minus = 0;
		while(in[i] >= '0' && in[i] <= '9'){
			a *= 10;
			a += in[i]-'0';
			i++;
		}
		if(in[i] == '-') minus = 1;
		i++;
		while(in[i] >= '0' && in[i] <= '9'){
			b *= 10;
			b += in[i] - '0';
			i++;
		}
		i++;
		if(in[i] == '?') continue;
		while(i < in.size()){
			c *= 10;
			c += in[i] - '0';
			i++;
		}
		if(minus) b *= -1;
		if(a + b == c){
			//printf("%d%+d=%d\n", a, b, c);
			count++;
		}
	}
	printf("%d\n", count);

	return 0;
}
