#include<iostream>
using namespace std;

int euclid(int a, int b) {
	int answer = 0;
	int big, little;
	while (1) {
		if(a < b) swap(a, b);
		if (a % b != 0) a = a % b;
		else {
			answer = b;
			break;
		}
	}
	return answer;
}

int main() {
	cout << euclid(1112, 695);
}