#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> djicstra(vector<vector<pair<int, int>>> graph,int start) {
	vector<bool>visited(graph.size(), false);
	vector<int>dist(graph.size(), 99999);
	dist[start] = 0;
	priority_queue<pair<int, int>> qt;
	qt.push({ 0, start });
	while (!qt.empty()) {
		int u = qt.top().second;
		qt.pop();
		if (visited[u]) continue;
		visited[u] = true;
		for (pair<int, int> n : graph[u]) {
			if (dist[n.first] > dist[u] + n.second) {
				dist[n.first] = dist[u] + n.second;
				qt.push({ -(dist[n.first]),n.first});
			}
		}
	}
	return dist;
}


int main() {
	int n, e;
	cin >> n >> e;
	vector<vector<pair<int, int>>> graph(n);
	for (int i = 0; i < e; i++) {
		int node, dst,weight;
		cin >> node >> dst >> weight;
		graph[node].push_back({ dst,weight });
	}
	vector<int> result;
	result = djicstra(graph, 0);
	for (int d : result) {
		cout << d << " ";
	}
}