#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int two_pointer(vector<int> arr , int v,int n) {
	int left = 0;
	int right = 0;
	int total = 0;
	int cnt = 0;

	while (left <= n) {
		if (total < v) {
			total += arr[left];
			left++;
		}
		else if (total >= v) {
			total -= arr[right];
			right++;
		}
		if (total == v) {
			cnt++;
		}
	}
	return cnt;
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> arr(N + 1, 0);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cout << two_pointer(arr, M, N);
}
