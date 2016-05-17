//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish


#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define ii pair<int, int>;
#define dd pair<double, double>;

int coinValue[5] = {1, 5, 10, 25, 50};

long long int memo[5][30001];
long long int ccv(int t, int v)
{
	if(v == 0) return 1;
	else if(v < 0) return 0;
	else if(t == 5) return 0;
	else if(memo[t][v] != -1) return memo[t][v];
	else
	{
		memo[t][v] = ccv(t+1, v) + ccv(t, v - coinValue[t]);
		return memo[t][v];
	}
}

int main()
{
	long long int v, a, w;
	memset(memo, -1, sizeof(memo));
	
	while(scanf("%lld", &v) > 0)
	{
		//memset(memo, -1, sizeof(memo));
		w = ccv(0, v);
		if(w > 1) printf("There are %lld ways to produce %lld cents change.\n", w, v);
		else printf("There is only %lld way to produce %lld cents change.\n", w, v);
	}
	return 0;
}
