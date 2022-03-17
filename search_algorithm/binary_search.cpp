#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool b_search(vector<int> arr,int val) {
	int start = 0;
	int end = arr.size() - 1;
	int middle;
	bool check = false;
	while (end > start) {
		middle = (start + end) / 2;
		if (arr[middle] == val) {
			check = true;
			break;
		}
		else if (arr[middle] > val) {
			end = middle - 1;
		}
		else start = middle + 1;
	}
	return check;
}

int main() {

	int n,val;
	cin >> n >> val;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	cout << b_search(arr, val);
}
