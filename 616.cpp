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
	int i, j, k;
	int qtd;
	bool flag;
	int max;
	while(scanf("%d", &i) > 0)
	{
		if(i < 0) break;
		max = 0;
		flag = 0;
		for(j = sqrt(i)+1; j >= 2;j--)
		{
			flag = 1;
			qtd = i;
			for(k = 0; k < j; k++)
			{
				if(qtd % j == 1)
				{
					qtd -= (qtd/j) + 1;
				}
				else
				{
					flag = 0;
					break;
				}
			}
			if(qtd % j != 0) flag = 0;
			if(flag == 1){
				max = j;
				break;
			}
		}
		if(max != 0)printf("%d coconuts, %d people and 1 monkey\n", i, max);
		else printf("%d coconuts, no solution\n", i);
	}
	return 0;
}
