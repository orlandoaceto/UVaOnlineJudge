//Problem at UVa Online Judge
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish


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

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

int main(){
	int n, q, i, j, k, l;
	int count;
	bool found;
	vector<string> dic;
	string word;
	
	sc(n);
	dic.resize(n);
	fr(i,n){
		cin>>dic[i];
	}
	sc(q);
	fr(l,q){
		cin>>word;
		found = 0;
		fr(i,n){
			if(word == dic[i]){
				cout<<word<<" is correct\n";
				found = 1;
				break;
			}
		}
		if(found == 0) fr(i,n){
			if(word.size() == dic[i].size()){
				count = 0;
				for(j = 0; j < (int)word.size() && count <= 2; j++){
					if(word[j] != dic[i][j])count++;
				}
				if(count == 1){
					cout<<word<<" is a misspelling of "<<dic[i]<<'\n';
					found = 1;
					break;
				}
				if(count == 2){
					count = 0;
					for(j = 0; j < (int)word.size()-1 && count < 2; j++){
						if(word[j] != dic[i][j] && word[j+1] != dic[i][j+1] && word[j] == dic[i][j+1] && word[j+1] == dic[i][j])count++;
					}
					if(count == 1){
						cout<<word<<" is a misspelling of "<<dic[i]<<'\n';
						found = 1;
						break;
					}
				}
			}
			else if((int)word.size() -(int)dic[i].size() == 1){
				count = 0;
				j = 0; k = 0;
				while(j < word.size() && k < dic[i].size()){
					if(word[j] != dic[i][k])j++, count++;
					else j++,k++;
				}
				if(count == 0 || (count == 1 && j == word.size() && k == dic[i].size())){
					cout<<word<<" is a misspelling of "<<dic[i]<<'\n';
					found = 1;
					break;
				}
			}
			else if((int)word.size() - (int)dic[i].size() == -1){
				count = 0;
				j = 0; k = 0;
				while(j < word.size() && k < dic[i].size()){
					if(word[j] != dic[i][k])k++, count++;
					else j++,k++;
				}
				if(count == 0 || (count == 1 && j == word.size() && k == dic[i].size())){
					cout<<word<<" is a misspelling of "<<dic[i]<<'\n';
					found = 1;
					break;
				}
			}
			
		}
		if(found == 0)cout<<word<<" is unknown\n";
	
	}
	

	return 0;
}
