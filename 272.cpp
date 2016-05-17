//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish


#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define ii pair<int, int>;
#define dd pair<double, double>;

int main()
{
	int b = 1;
	char c;
	while(scanf("%c", &c) > 0)
	{
		if(c == '\"')
		{
			if(b)printf("``");
			else printf("''");
			
			b ^= 1;
		}
		else printf("%c", c);
	}
}
