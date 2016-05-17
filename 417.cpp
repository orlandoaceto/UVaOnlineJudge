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
	map<string, int> mapp;
	int i, j, k, l,m, p = 1;
	string r;
	char str[6];
	str[0] = 0;
	str[1] = 0;
	str[2] = 0;
	str[3] = 0;
	str[4] = 0;
	str[5] = 0;
	
	fr(i,26)
	{
		str[0] = 'a'+ i;
		mapp[str] = p++;
	}
	fr(i,26)
	{
		str[0] = 'a'+ i;
		for(j = i + 1; j < 26; j++)
		{
			str[1] = 'a'+ j;
			string cppstr = str;
			mapp[cppstr] = p++;
		}
		
	}
	
	fr(i,26)
	{
		str[0] = 'a'+ i;
		
		for(j = i+1; j < 26; j++)
		{
			str[1] = 'a'+ j;
			for(k = j + 1; k < 26; k++)
			{
				str[2] = 'a' + k;
				string cppstr = str;
				mapp[cppstr] = p++;
			}
		}
	}
	
	fr(i,26)
	{
		str[0] = 'a'+ i;
		
		for(j = i+1; j < 26; j++)
		{
			str[1] = 'a'+ j;
			for(k = j + 1; k < 26; k++)
			{
				str[2] = 'a' + k;
				for(l = k + 1; l < 26; l++)
				{
					str[3] = 'a' + l;
					string cppstr = str;
					mapp[cppstr] = p++;
				}
			}
		}
	}
	
	fr(i,26)
	{
		str[0] = 'a'+ i;
		
		for(j = i+1; j < 26;j++)
		{
			str[1] = 'a'+ j;
			for(k = j + 1; k < 26; k++)
			{
				str[2] = 'a' + k;
				for(l = k + 1; l < 26; l++)
				{
					str[3] = 'a' + l;
					for(m = l+1; m < 26; m++)
					{
						str[4] = 'a' + m;
						string cppstr = str;
						mapp[cppstr] = p++;
					}
				}
			}
		}
	}
	
	while(getline(cin, r))
	{
		if(!r.empty())
			cout<<mapp[r]<<'\n';
			
		r.clear();
	}
}
