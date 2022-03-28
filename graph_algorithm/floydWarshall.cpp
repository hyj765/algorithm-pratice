#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> floydWarshall(vector<vector<int>> graph) {
	vector<vector<int>> d=graph;

	for (int i = 0; i < graph.size(); i++) {
		for (int j = 0; j < graph.size(); j++) {
			for (int k = 0; k < graph.size(); k++) {
				if (d[j][i] + d[i][k] < d[j][k]) d[j][k] = d[j][i] + d[i][k];
			}
		}
	}
	// [1][0] + [0][2] < d[1][2] 
	return d;
}

int main() {
	int n;
	cin >> n;

	vector<vector<int>> graph(n, vector<int>(n));
	vector<vector<int>> re;
	for (int i = 0; i < n; i++ ) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	re= floydWarshall(graph);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << re[i][j] << " ";
		}
		cout << '\n';
	}


}