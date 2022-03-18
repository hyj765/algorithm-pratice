#include<iostream>
#include<vector>
#include<string>
using namespace std;

void array_rotate(vector<vector<int>> &arr) {
	vector<vector<int>> temp = arr;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			temp[i][j] = arr[arr.size() - 1 - j][i];
		}
	}
	arr = temp;
}

void array_print(vector<vector<int>> arr) {

	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << "  ";
		}
		cout << '\n';
	}



}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> arr(n);
	int cur = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i].push_back(cur++);
		}
	}
	array_print(arr);
	array_rotate(arr);
	cout << '\n';
	array_print(arr);
	array_rotate(arr);
	cout << '\n';
	array_print(arr);
	array_rotate(arr);
	cout << '\n';
	array_print(arr);
}