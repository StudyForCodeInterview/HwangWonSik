#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map<int, vector<int>> g_graph;
vector<bool> visited;
vector<int> maxDepth;
int answer = 0;
void dfs(int curN,int depth)
{
	if (depth == 5 || answer == 1)
	{
		answer = 1;
		return;
	}

	visited[curN] = true;
	for (int neighbor : g_graph[curN])
	{
		if (visited[neighbor] == false&&maxDepth[neighbor]<depth+1)
		{
			
			dfs(neighbor, depth + 1);
			
		}
	}
	visited[curN] = false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	visited = vector<bool>(n, false);
	maxDepth = vector<int>(n, 0);
	for (int i = 0; i < m; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		g_graph[n1].push_back(n2);
		g_graph[n2].push_back(n1);
	}

	for (int i = 0; i < n; i++)
	{
		dfs(i,1);
	}
	cout << answer << '\n';
	return 0;
}
