#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

void pair_print(vector<pair<int, int>> ar) {
	for (auto value : ar) {
		cout << value.first << " " << value.second << endl;
	}
}

bool cmp(pair<int,int> a , pair<int,int> b) {
	if (a < b) {
		return true;
	}
	return false;
}
int main() {
	int n,total =0;
	cin >> n;
	priority_queue<pair<int,int>> g;
	vector<pair<int,int>> ar;
	for (int i = 0; i < n; i++) {
		pair<int, int> ex;
		cin >> ex.first >> ex.second;
		ar.push_back(ex);
	}
	sort(ar.begin(), ar.end(), cmp);

	
	for (int i = 0; i < n; i++) {
		if (g.size() < ar[i].first) {
			g.push({-(ar[i].second),ar[i].first});
		}
		else {
			if (-(g.top().first) < ar[i].second) {
				g.pop();
				g.push({-(ar[i].second),ar[i].first});
			}
		}
	}

	while (!g.empty()) {
		total += -(g.top().first);
		g.pop();
	}
	cout << total;
	
}