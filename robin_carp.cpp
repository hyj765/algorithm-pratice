#include<iostream>
#include<chrono>
using namespace std;

bool robin_carp(string pattern, string base) {
	bool fined = false;
	int patternhash = 0; 
	int basehash = 0; 
	int power = 1;
	for (int i = 0; i <= base.size() - pattern.size(); i++) {
		if (i == 0) {
			for (int j = 0; j < pattern.size(); j++) {
				basehash += base[pattern.size() - 1 - j] * power;
				patternhash += pattern[pattern.size() - 1 - j] * power;
				if (j < pattern.size() - 1) power *= 2;
			}
		}else {
			basehash = 2 * (basehash - base[i - 1] * power) + base[pattern.size() - 1 + i];
		}
		if (basehash == patternhash) {
			fined = true; 
			for (int j = 0; j < pattern.size(); j++) {
				if (base[i + j] != pattern[j]) {
					fined = false;
					break;
				}
			}
			if (fined == true) {
				return fined;
			}
		}

	}
	return fined;
}


int main() {
	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
	string a = "dsafnmsdajknfusauirenasifnsaidfnsaifdsakmfmlasdkfmkldsamfkldsamfklsmaklgmlksadnmfkldsanfklndasklfnskafnklndkfvznxcklfvnxlknfklzxnfklznkl";
	std::chrono::duration<double>sec = std::chrono::system_clock::now() - start;
	//robin_carp("fklznkl",a);
	a.find("fklznkl");
	std::cout << "for문을 돌리는데 걸리는 시간(초) : " << sec.count() << "seconds" << std::endl;

}