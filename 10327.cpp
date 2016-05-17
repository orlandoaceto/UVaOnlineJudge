//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish


#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define sc(a) scanf("%d", &a)
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int main()
{
	int n, i, j;
	int count, aux;
	int v[1000];
	
	while(sc(n) > 0)
	{
		count = 0;
		fr(i, n)sc(v[i]);
		
		fr(i,n)for(j = i + 1; j < n; j++) if(v[i] > v[j]) count++;
		
		printf("Minimum exchange operations : %d\n", count);
	} 
	return 0;
}
