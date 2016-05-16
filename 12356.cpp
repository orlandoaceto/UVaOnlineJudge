#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define ii pair<int, int>;
#define dd pair<double, double>;

int main()
{
	int s, b;
	int vl[100002], vr[100002];
	int l, r;
	int i, j;
	
	while(scanf("%d %d", &s, &b) > 0)
	{
		if(s > 0 || b > 0)
		{
			fr(i, s+1)
			{
				vr[i] = i+1;
				vl[i] = i-1;
			}
			vl[1] = 0;
			vr[s] = 0;
			
			fr(i, b)
			{
				scanf("%d %d", &l, &r);	
				if(vl[l] == 0) printf("* ");
				else printf("%d ", vl[l]);
				if(vr[r] == 0) printf("*\n");
				else printf("%d\n", vr[r]);
				
				vl[vr[r]] = vl[l];
				vr[vl[l]] = vr[r];
				
			}
			printf("-\n");
		}
	}
}
