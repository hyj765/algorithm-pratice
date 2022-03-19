#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

//동호가 받을 수 있는 [최대 컵라면 개수] 구하기.
// n은 입력 횟수 ex.first은 데드라인 second는 컵라면 개수
/* 항상 더 많은 컵라면을 주게 순차적으로 골름 + 데드라인이 존재하기 떄문에 항상 체크해줘야함.
void pair_print(vector<pair<int, int>> ar) {
	for (auto value : ar) {
		cout << value.first << " " << value.second << endl;
	}
}*/

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
	//제일 낮은 데드라인부터 순차탐색하기 위해 정렬
	
	for (int i = 0; i < n; i++) {
		if (g.size() < ar[i].first) { //문제의 수에 따른 데드라인 체크 
			g.push({-(ar[i].second),ar[i].first}); // 우선순위 큐에서는 가장 컵라면을 적게 주는 문제가 최상단에 오게 하기 위해 -값으로 저장함.
		}
		else {
			if (-(g.top().first) < ar[i].second) { // 1 1 2 2 3 3 6          다음 case와 같이 앞썬 데드라인이 빠른 값을 선택하면 안되는 경우 
				g.pop();		       // 1 2 4 5 5 6 1000       앞선 값에서 가장 낮은 컵라면을 주는 값을 순차적으로 제거
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
