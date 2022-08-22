#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

int main()
{
	int t = 7;
	while(t--){
	string size, mark;
	cin >> size >> mark;
	int n, k;
	n = stoi(size);
	k = stoi(mark);

	vector<int> given(n);
	vector<int> k_indices;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		given[i] = stoi(input);

		if (given[i] == k)
			k_indices.push_back(i);
	}

	int ans = 0;
	for (auto &&i : k_indices)
	{
		bool flag = 1;
		for (int j = 1; j < k; j++)
		{
			if (given[i + j] == (k - ( (2*j) + 1) ) ){
				if( (k - ( (2*j) + 1) ) == 1 ) break;
				continue;
			}else
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			ans++;
	}
	cout << ans <<  "\n";
	}
	return 0;
}
