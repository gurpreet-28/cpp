#include <bits/stdc++.h>
using namespace std;

int maxWeightCell(int n, int edge[])
{
	int wt[n] = {0};
	for (int i = 0; i < n; i++)
	{
		if (edge[i] != -1)
			wt[edge[i]] += i;
	}

	int max_wt = -1, max_wt_idx = -1;
	for (int i = 0; i < n; i++)
	{
		if (wt[i] >= max_wt)
		{
			max_wt = wt[i];
			max_wt_idx = i;
		}
	}

	return max_wt_idx;
}

int main()
{
	int n, t;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		arr[i] = t;
	}

	cout << maxWeightCell(n, arr);
	return 0;
}