#include <iostream>
#include <vector>
#include <algorithm>]
#include <ctime>
using namespace std;

int b_search_cnt(vector<int> arr, int val) { //  time complex = (n/2)+n 막 밀어보기 0.02초
	int start = 0;
	int end = arr.size() - 1;
	int middle;
	while (end > start) {
		middle = (start + end) / 2;
		if (arr[middle] == val) {
			int cnt = 1;
			int cur = middle;
			cur+=1; // 8
			while (cur < arr.size()) {
				if (arr[cur] == val) cnt++;
				else break;
				cur += 1;
			}
			return cnt;
		}
		else if (arr[middle] > val) {
			end = middle - 1;
		}
		else start = middle + 1;
	}
	return 0;
}

int two_b_search(vector<int> arr, int val) { // 두개의 바이너리 서치 값의 차이를 통하여 값 구하기 0.01초
	auto up = upper_bound(arr.begin(), arr.end(), val);
	auto down = lower_bound(arr.begin(), arr.end(), val);
	return up - down;
}


int main() {
	int n, val;
	cin >> n >> val;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	cout << two_b_search(arr, val) << endl;
	cout << b_search_cnt(arr, val) << endl;

}