//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish


#include <bits/stdc++.h>
using namespace std;

#define fr(i, n) for(i = 0; i < n; i++)
#define ii pair<int, int>;
#define dd pair<double, double>;

int main()
{
	int val[256];
	int n, m, k;
	unsigned char str[10010];
	string::iterator it;
	int i, j, v;
	unsigned char c;
	long long pr;
	
	scanf("%d\n", &n);
	int l;
	fr(l, n)
	{
		for(i = 0; i <= 256; i++)val[i] = 0;
		
		scanf("%d\n", &k);
		fr(i, k)
		{
			scanf("%c %d\n", &c, &v);
			val[c] = v;
		}
		
		pr = 0;
		scanf("%d\n", &m);
		fr(i, m)
		{
			fgets((char*)str,10000, stdin);
			for(int j = 0; str[j] != 0; j++)
			{
				pr += val[str[j]];
			}
		}
		
		printf("%.2lf$\n", (double)pr / 100);
	}
	
	return 0;
}
