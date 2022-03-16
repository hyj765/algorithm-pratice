#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool check[100] = { false };

void bfs(vector<vector<int>> graph,int start) {
	check[start] = true;
	queue<int>g;
	g.push(start);
	while (!g.empty()) {
		int cur = g.front();
		cout << cur << " ";
		g.pop();
		for (int n : graph[cur]) {
			if (!check[n]) {
				g.push(n);
				check[n] = true;
			}
		}
	}

}


int main() {
	int n, m;
	cin >> n >> m ;
	vector<vector<int>> graph(m+1);
	for (int i = 0; i < m; i++) {
		int src, dst;
		cin >> src >> dst;
		graph[src].push_back(dst);
		graph[dst].push_back(src);
	}
	bfs(graph, 1); 
}
