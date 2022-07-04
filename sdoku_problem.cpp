#include<iostream>
#include<vector>
#include<algorithm>
#include<future>
using namespace std;

bool check_cross(vector<vector<int>> line,int cnd) {
	if (cnd == 0) {
		for (int i = 0; i < line.size(); i++) {
			int checkbox[10] = { 0 , };
			for (int j = 0; j < line.size(); j++) {
				if (checkbox[line[i][j]] == true) return false;
				checkbox[line[i][j]] = true;
			}
		}
	}
	else {
		for (int i = 0; i < line.size(); i++) {
			int checkbox[10] = { 0 , };
			for (int j = 0; j < line.size(); j++) {
				if (checkbox[line[j][i]] == true) return false;
				checkbox[line[j][i]] = true;
			}
		}
	}

	return true;
}

bool box_check(vector<vector<int>>line) {
	for (int p = 0; p < 3; p++) {
	
		for (int k = 0; k < 3; k++) {
			int check_box = 0;
			check_box += line[(p * 3)  ][(k * 3)] + line[(p * 3)  ][(k * 3) + 1] + line[(p * 3)  ][(k * 3) + 2];
			check_box += line[(p * 3)+1][(k * 3)] + line[(p * 3)+1][(k * 3) + 1] + line[(p * 3)+1][(k * 3) + 2];
			check_box += line[(p * 3)+2][(k * 3)] + line[(p * 3)+2][(k * 3) + 1] + line[(p * 3)+2][(k * 3) + 2];
		
			if (check_box != 45) return false;
		}
	}
	return true;
}



int main() {
	int n;
	cin >> n;
	for (int test_case = 1; test_case <= n; test_case++) {
		vector<vector<int>> map(9, vector<int>(9));
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> map[i][j];
			}
		}
		printf("\n");
		future<bool> cross = std::async(std::launch::async, check_cross, map, 0);
		future<bool> sero = std::async(std::launch::async, check_cross, map, 1);
		future<bool> box = std::async(std::launch::async, box_check, map);

		if (cross.get() && sero.get() && box.get()) printf("#%d 1\n", test_case);
		else 	printf("#%d 0\n", test_case);
	}
}