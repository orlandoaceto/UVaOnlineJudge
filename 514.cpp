#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int main()
{
	int n, r;
	vector<int> perm;
	stack<int> st;
	int i, p;
	
	while(true)
	{
		scanf("%d", &n);
		if(n == 0) break;
		
		do
		{
			scanf("%d", &r);
			if(r > 0)
			{
				perm.clear();
				perm.push_back(r);
				while(perm.size() < n)
				{
					scanf("%d", &r);
					perm.push_back(r);
				}
				
				while(!st.empty()) st.pop();
				p = 0;
				for(i = 1; i <= n; i++)
				{
					st.push(i);
					while(!st.empty() && st.top() == perm[p])
					{
						p++;
						st.pop();
					}
				}
				if(p == n) printf("Yes\n");
				else printf("No\n");
			}
		}while(r > 0);
		printf("\n");
	}
}
