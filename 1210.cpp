//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish


#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define sc(a) scanf("%d", &a)
#define pr(a) printf("%d\n", a)
typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;

int main()
{
	bool isP[10001];
	int i, j, sum, n, count;
	vi pri;
	
	memset(isP, 1, sizeof isP);
	for(i = 2; i <= 10000; i++){
		if(isP[i] == 1)for(j = i *2; j <= 10000; j += i) isP[j] = 0;
	}
	for(i = 2; i <= 10000; i++) if(isP[i] == 1)pri.push_back(i);
	
	while(sc(n) > 0){
		if(n == 0) break;
		i = j = count = 0;
		sum = pri[0];
		while(j < pri.size() && pri[j] <= n){
			if(sum > n){
				i++;
				sum -= pri[i-1];
			}
			else if(sum < n){
				j++;
				if(j == pri.size()) break;
				sum += pri[j];
			}
			else{
				count++;
				i++;
				j++;
				sum -= pri[i-1];
				sum += pri[j];
			}
		}
		pr(count);
	}
	
	return 0;
}
