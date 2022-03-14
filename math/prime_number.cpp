#include<iostream>
#include<vector>
using namespace std;

bool Is_PrimeNumber(int n) {
	bool prime = true;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			prime = false;  
			break;
		}
	}
	return prime;
}

vector<int> eratosthenes_sieve(int n) {
	vector<int> ar(n+1,0);
	vector<int> prime_numbers;
	for (int i = 2; i <= n; i++) {
		ar[i] = i;
	}
	for (int i = 2; i <= n; i++) {
		if (ar[i] == 0) continue;
		for (int j = i + i; j <= n; j += i) {
			ar[j] = 0;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (ar[i] == 0) continue;
		prime_numbers.push_back(ar[i]);
	}
	return prime_numbers;
}


int main() {
	int n;
	cin >> n;
	vector<int> result;
	result = eratosthenes_sieve(n);
	for (int number : result) {
		cout << number << " ";
	}
}