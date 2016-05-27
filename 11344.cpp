//11344 - The Huge One
//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

/*
This problem can be solved by applying divisibility tests for integers 1 to 12
as necessary (depending on input). This divisibility tests must be based on the
digits of the numbers as you can't read a 100 digit numbers (at least in c++).
Only tests for 7 and 11 are somewhat tricky, others are straightforward.
*/

#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define fr1(a, n) for(a = 1; a <= n; a++)
#define frR(a, n) for (a = n; a >= 0; a--)
#define sc(a) scanf("%d", &a)
#define pr(a) printf("%d\n", a)
#define p(i, j) make_pair(i, j)
#define fi first
#define se second
#define pb push_back
#define clr(a) memset(a, 0, sizeof a);

const int oo = 0x3f3f3f3f;

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

int main(){
	int vec[] = {1,3,2,6,4,5};
	int n, el, qt, i, sum, sumAux;
	bool s[13], div[13];
	string m;
	int lastVal;
	
	scanf("%d", &n);
	
	while(n--){
		cin>>m;
		clr(s); clr(div);
		
		sc(qt);
		
		while(qt--){
			sc(el);
			s[el] = 1;
		}
		lastVal = m[m.size()-1]-'0';
		if(m.size() >= 2) lastVal += (m[m.size()-2] - '0')*10; 
		if(m.size() >= 3) lastVal += (m[m.size()-3] - '0')*100;
		
		sum = 0;
		for(i = 0; i < m.size(); i++){
			sum += m[i] - '0';
		}
		
		
		if((lastVal % 10) % 2 == 0){
			div[2] = 1;
		}
		else if(s[2]){
			cout<<m<<" - "<<"Simple.\n";
			continue;
		}
		
		
		if(sum % 3 == 0){
			div[3] = 1;
		}
		else if(s[3]){
			cout<<m<<" - "<<"Simple.\n";
			continue;
		}
		
		
		if((lastVal % 100) % 4 == 0){
			div[4] = 1;
		}
		else if(s[4]){
			cout<<m<<" - "<<"Simple.\n";
				continue;
		}
		
		if((lastVal % 10) % 5 == 0){
			div[5] = 1;
		}
		else if(s[5]){
			cout<<m<<" - "<<"Simple.\n";
			continue;
		}
		
		if(s[6]){
			if(div[2] && div[3]){
				div[6] = 1;
			}
			else{
				cout<<m<<" - "<<"Simple.\n";
				continue;
			}
		}
		
		if(s[7]){
			sumAux = 0;
			fr1(i,m.size()){
				sumAux += ((m[m.size()-i]-'0') * vec[(i-1)%6]) % 7;
			}
			
			if(sumAux % 7 == 0){
				div[7] = 1;
			}
			else{
				cout<<m<<" - "<<"Simple.\n";
				continue;
			}
			
		}
		
		if(s[8]){
			if(lastVal % 8 == 0){
				div[8] = 1;
			}
			else{
				cout<<m<<" - "<<"Simple.\n";
				continue;
			}
			
		}
		if(s[9]){
			if(sum % 9 == 0){
				div[9] = 1;
			}
			else{
				cout<<m<<" - "<<"Simple.\n";
				continue;
			}
		}
		if(s[10]){
			if(div[2] && div[5]){
				div[10] = 1;
			}
			else{
				cout<<m<<" - "<<"Simple.\n";
				continue;
			}
		}
		if(s[11]){
			sumAux = 0;
			fr(i,m.size()){
				sumAux += m[i]-'0';
				i++;
				if(i < m.size()){
					sumAux -= m[i]-'0';
				}
			}
			if(sumAux % 11 == 0){
				div[11] = 1;
			}
			else{
				cout<<m<<" - "<<"Simple.\n";
				continue;
			}
		}
		
		
		if(s[12]){
			if(div[4] && div[3]){
				div[12] = 1;
			}
			else{
				cout<<m<<" - "<<"Simple.\n";
				continue;
			}
		}
		
		
		cout<<m<<" - "<<"Wonderful.\n";
		
	}
	
	return 0;
}
