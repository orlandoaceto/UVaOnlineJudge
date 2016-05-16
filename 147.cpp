#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define ii pair<int, int>;
#define dd pair<double, double>;

int coinValue[11] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

long long int memo[11][30001];
long long int ccv(int t, int v)
{
	if(v == 0) return 1;
	else if(v < 0) return 0;
	else if(t == 11) return 0;
	else if(memo[t][v] != -1) return memo[t][v];
	else
	{
		memo[t][v] = ccv(t+1, v) + ccv(t, v - coinValue[t]);
		//printf("%d %d, %lld\n", t, v,memo[t][v]);
		return memo[t][v];
	}
}

int main()
{
	double r;
	long long int v, a, w;
	int i, j;
	fr(i,11)fr(j,30001)memo[i][j] = -1;
	
	while(scanf("%lf", &r) > 0)
	{
		if(r == 0) break;
		v = r * 100;
		if((v+1) % 5 == 0)v = v+1;
		else if((v-1) % 5 == 0)v = v-1; 
		//printf("v = %lld\n", v);
		w = ccv(0, v);
		printf("%6.2lf%17lld\n", r, w);
	}
	return 0;
}
