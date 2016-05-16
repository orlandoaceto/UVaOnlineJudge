#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define ii pair<int, int>;
#define dd pair<double, double>;

int main()
{
	bool v[3001];
	int ant, at, n, i;
	bool f;
	
	while(scanf("%d", &n) > 0)
	{
		scanf("%d", &ant);
		fr(i, 3001) v[i] = 0;
		
		fr(i,n-1)
		{
			scanf("%d", &at);
			//printf("%d ", ant);
			
			v[abs(at-ant)] = 1;
			
			ant = at;
		}
		f = 1;
		//fr(i, n-1) printf("%d ", v[i+1]);
		//printf("\n");
		
		for(i = 1; i <= n-1; i++) if(v[i] == 0)f = 0;
		
		if(!f) printf("Not jolly\n");
		else printf("Jolly\n");
	}
	return 0;
}
