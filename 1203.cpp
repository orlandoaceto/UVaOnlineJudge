#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)

int main()
{
	char st[20];
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	pair<int,int> p;
	long long int time;
	int k;
	int inc[3001];
	do
	{
		scanf("%s", st);
		if(strcmp(st, "Register") == 0)
		{
			scanf(" %d %d\n", &p.second, &p.first);
			q.push(p);
			inc[p.second] = p.first;
		}
		else
		{
			scanf("%d", &k);
			while(k--)
			{
				p = q.top();
				q.pop();
				printf("%d\n", p.second);
				p.first += inc[p.second];
				q.push(p);
			}
			
		}
	}while(strcmp(st, "Register") == 0);
}
