//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish


#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int main()
{
	int n1, n2;
	int a1, a2, a3, a4;
	
	while(cin>>n1)
	{
		a1=a2=a3=a4=0;
		a1 = (n1 & 0x000000ff) << 24;
		a2 = (n1 & 0x0000ff00) << 8;
		a3 = (n1 & 0x00ff0000) >> 8;
		a4 = (n1 & 0xff000000) >> 24;
		n2 = a1 | a2 | a3 | a4;
		cout<<n1<<" converts to "<<n2<<'\n';
	}
}
