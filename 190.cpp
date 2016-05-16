#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define pair<int, int> ii;
#define pair<double, double> dd;
#define a.x a.first();
#define a.y a.second();
int main()
{
	dd p1, p2, p3;
	double a12, a13, l12, l13;
	dd dist12, dist13, mid12, mid13;;
	
	
	a12 = (p1.y - p2.y) / (p1.x - p2.x);
	a13 = (p1.y - p3.y) / (p1.x - p3.x);
	
	dist12.y = p2.y - p1.y;
	dist12.x = p2.x - p1.x;
	dist13.y = p3.y - p1.y;
	dist13.x = p3.x - p1.x;
	
	mid12.x = p1.x + (1.0/2) * dist12.x;
	mid12.y = p1.y + (1.0/2) * dist12.y;
	mid13.x = p1.x + (1.0/2) * dist13.x;
	mid13.y = p1.y + (1.0/2) * dist13.y;
	
	l12 = mid12.y - l12 * mid12.x;
	l13 = mid13.y - l13 * mid13.x;
}
