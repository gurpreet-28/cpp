#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &dist_node, vector<bool> &vis, vector<int> &edge, int distance, int &ans)
{
    if (node != -1)
    {
        if (!vis[node])
        {
            vis[node] = true;
            dist_node[node] = distance;
            dfs(edge[node], dist_node, vis, edge, distance + 1, ans);
        }
        else
            ans = max(ans, distance - dist_node[node]);
    }
}

int largestSumCycle(int n, vector<int> edge)
{
    vector<int> dist_node(n, 0);
    vector<bool> visited(n, false);
    int ans = -1;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(i, dist_node, visited, edge, 0, ans);
    }

    return ans;
}

int main()
{
    int n, t;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        v.push_back(t);
    }

    cout << largestSumCycle(n, v);
    return 0;
}