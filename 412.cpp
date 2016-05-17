//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish


#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define sc(a) scanf("%d", &a)
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int gcd(int a, int b){
	return b == 0 ? a: gcd(b, a%b);
}

int main(){
	double est;
	int n, i, j;
	int c, total;
	int v[50];
	while(sc(n) > 0){
		if(n == 0) break;
		fr(i,n)sc(v[i]);
		c = 0;
		total = 0;
		fr(i,n)for(j = i+1; j < n; j++){
			if(gcd(v[i],v[j]) == 1)c++;
			total++;
		}
		if(c > 0){
			est = sqrt((6 * total)/(double)c);
			printf("%lf\n", est);
		}
		else
			printf("No estimate for this data set.\n");
		
	}
	return 0;
}
