#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define ii pair<int, int>;
#define dd pair<double, double>;

int main()
{
	stack<int> st;
	priority_queue<int> pq;
	queue<int> q;
	int n, c, x;
	int pqf, qf, stf;
	int i;
	
	while(scanf("%d", &n) > 0)
	{
		pqf = qf = stf = 1;
		fr(i, n)
		{
			scanf("%d", &c);
			if(c== 1)
			{
				scanf("%d", &x);
				st.push(x);
				q.push(x);
				pq.push(x);
			}
			else
			{
				scanf("%d", &x);
				if(!st.empty() && st.top() != x) stf = 0;
				if(!q.empty() && q.front() != x) qf = 0;
				if(!pq.empty() && pq.top() != x) pqf = 0;
				
				if(!st.empty()) st.pop();
				else stf = 0;
				if(!q.empty()) q.pop();
				else qf = 0;
				if(!pq.empty()) pq.pop();
				else pqf = 0;
			}
		}
		if(stf == 1 && qf == 0 && pqf == 0) printf("stack\n");
		else if(stf == 0 && qf == 1 && pqf == 0) printf("queue\n");
		else if(stf == 0 && qf == 0 && pqf == 1) printf("priority queue\n");
		else if(stf == 0 && qf == 0 && pqf == 0) printf("impossible\n");
		else printf("not sure\n");
		while(!st.empty()) st.pop();
		while(!q.empty()) q.pop();
		while(!pq.empty()) pq.pop();
	}
}
