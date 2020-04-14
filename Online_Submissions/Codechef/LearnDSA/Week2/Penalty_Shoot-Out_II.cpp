#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<math.h>
#include<algorithm>
#include<string.h>
#include<assert.h>
using namespace std;

#define INF 1234567890
#define ll long long

int T, N;
string s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> s;
		int ty = 0, a = 0, b = 0, ac = N, bc = N, chk = s.size();
		for (int i = 0; i < s.size(); i++)
		{
			if (ty == 0)
			{
				if (s[i] == '1') a++;
				ac--;
			}
			else
			{
				if (s[i] == '1') b++;
				bc--;
			}
			if (a + 0 > b + bc || a + ac < b + 0)
			{
				chk = i + 1;
				break;
			}

			ty = 1 - ty;
		}
		cout << chk << "\n";
	}
	return 0;
}