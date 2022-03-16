#include<iostream>
#include<vector>
using namespace std;

bool check[100] = { false };

void dfs(vector<vector<int>> graph,int start) {
	check[start] = true;
	cout << start << " ";
	for (int node : graph[start]) {
		if (!check[node]) {
			dfs(graph, node);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(m+1);
	for (int i = 0; i < m; i++) {
		int src, dst;
		cin >> src >> dst;
		graph[src].push_back(dst);
		graph[dst].push_back(src);
	}
	dfs(graph, 1);
}
